//
// Created by forestileao on 05/07/2021.
//

#include "../../include/Entities/Player.h"
using namespace Entities;

//PlayerStateMachine----------------
Player::PlayerStateMachine::PlayerStateMachine(Player *p)
{
	States::State* state = static_cast<States::State*>(new PlayerJumpState(static_cast<States::StateMachine*>(this), p));
	addState(state, PLAYER_JUMP_STATE);
	state = static_cast<States::State*>(new PlayerRestState(static_cast<States::StateMachine*>(this), p));
	addState(state, PLAYER_REST_STATE);
	state = static_cast<States::State*>(new PlayerWalkState(static_cast<States::StateMachine*>(this), p));
	addState(state, PLAYER_WALK_STATE);
	changeState(PLAYER_REST_STATE, NULL);
}

Player::PlayerStateMachine::~PlayerStateMachine()
{
}

//PlayerJumpState-------------------
Player::PlayerJumpState::PlayerJumpState(States::StateMachine* pStateMachine, Player *p)
:State(pStateMachine)
{
	this->p = p;
}

Player::PlayerJumpState::~PlayerJumpState()
{
}

void Player::PlayerJumpState::init(void* arg)
{
	std::cout << "PLAYER: Jumped\n";
	//p->double_jump = (bool&&)arg;
	p->vel.y = -p->jumpVel;
}

void Player::PlayerJumpState::update(float dt, Managers::EventManager* pEventManager)
{
	if(p)
	{
		// LEFT Side
		if(pEventManager->isKeyDown(p->leftKey))
		{
			p->rightDirection = false;
			p->vel.x -= p->airAcceleration;
			if(p->vel.x < -p->velMax)
				p->vel.x = -p->velMax;
		}

		if(pEventManager->isKeyDown(p->rightKey))
		{
			p->rightDirection = true;
			p->vel.x += p->airAcceleration;
			if(p->vel.x > p->velMax)
				p->vel.x = p->velMax;
		}
		p->frame = p->vel.x > 0 ? Managers::spriteRect(JUMP): Managers::spriteRect(JUMP_L);

		if(p->getGrounded())
		{//jogador atingiu o chao
			pStateMachine->changeState(PLAYER_REST_STATE, NULL); //ESTADO PARADO
			p->vel.x = 0;

			//muda o retangulo do sprite
			p->frame = Managers::spriteRect(DEFAULT);
		}
		if(p->double_jump)
		{ //PULO DUPLO
			if(pEventManager->isKeyPressed(p->jumpKey))
			{
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)false);//chama o pulo sem possibilidade de double jump
			}
		}
	}
}

void Player::PlayerJumpState::draw(Managers::GraphicManager* pGraphicManager)
{

}

//PlayerRestState-------------------
Player::PlayerRestState::PlayerRestState(States::StateMachine* pStateMachine, Player *p):State(pStateMachine)
{
	this->p = p;
}

Player::PlayerRestState::~PlayerRestState()
{
}

void Player::PlayerRestState::update(float dt, Managers::EventManager* pEventManager)
{
	if(p)
	{
		if(5.0f < p->vel.y*p->vel.y )
			p->setGrounded(false);

		if(pEventManager->isKeyPressed(p->jumpKey))
		{
			if(p->isGrounded)
			{
				p->setGrounded(false);
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)true);//chama o pulo com possibilidade de double jump
				//muda o retangulo do sprite
				p->frame = Managers::spriteRect(JUMP);
			}
			else{
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)false);//chama o pulo sem possibilidade de double jump
				//muda o retangulo do sprite
				p->frame = Managers::spriteRect(JUMP);
			}
		}

			//ESTADO ANDANDO
		else if(pEventManager->isKeyDown(p->rightKey) || pEventManager->isKeyDown(p->leftKey))
			pStateMachine->changeState(PLAYER_WALK_STATE, NULL);
	}
}

void Player::PlayerRestState::draw(Managers::GraphicManager* pGraphicManager)
{

}

//PlayerWalkState-------------------
Player::PlayerWalkState::PlayerWalkState(States::StateMachine* pStateMachine, Player *p):State(pStateMachine)
{
	this->p = p;
}

Player::PlayerWalkState::~PlayerWalkState()
{
}

void Player::PlayerWalkState::update(float dt, Managers::EventManager* pEventManager)
{
	if(p)
	{
		if (p->body.getPosition().y >= p->pGraphicManager->getWindowPointer()->getSize().y)
		{
			p->setGrounded(true);
		}

		if(p->vel.y*p->vel.y > 5.0f)
			p->setGrounded(false);
		if(pEventManager->isKeyDown(p->rightKey))
		{ //DIREITA
			p->rightDirection = true;
			//atualiza velocidades
			p->vel.x += p->groundAcceleration;
			if(p->vel.x > p->velMax)
				p->vel.x = p->velMax;

			//muda o retangulo do sprite
			p->frame = (p->nRect) ? Managers::spriteRect(WALK_R1): Managers::spriteRect(WALK_R2);

			p->frameTime += dt;
			if(p->frameTime > WALK_ANIMATION_FRAME_TIME)
			{
				p->frameTime = 0;
				p->nRect = !p->nRect;
			}
		}

		if(pEventManager->isKeyDown(p->leftKey))
		{ //ESQUERDA
			p->rightDirection = false;
			//atualiza velocidades
			p->vel.x -= p->groundAcceleration;
			if(p->vel.x < -p->velMax)
				p->vel.x = -p->velMax;

			//muda o retangulo do sprite
			p->frame = (p->nRect) ? Managers::spriteRect(WALK_L1): Managers::spriteRect(WALK_L2);
			p->frameTime += dt;
			if(p->frameTime > WALK_ANIMATION_FRAME_TIME)
			{
				p->frameTime = 0;
				p->nRect = !p->nRect;
			}
		}

		//ESTADO PARADO
		if(!pEventManager->isKeyDown(p->rightKey) && !pEventManager->isKeyDown(p->leftKey))
		{
			pStateMachine->changeState(PLAYER_REST_STATE, NULL);
			p->vel.x = 0;
			p->frame = Managers::spriteRect(DEFAULT);
		}

		//ESTADO PULO
		if(pEventManager->isKeyPressed(p->jumpKey))
		{
			if(p->isGrounded)
			{
				p->setGrounded(false);
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)true);//chama o pulo com possibilidade de pulo duplo

				//muda o retangulo do sprite
				p->frame = (p->vel.x > 0) ? Managers::spriteRect(JUMP): Managers::spriteRect(JUMP_L);
			}
			else{
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)false);//chama o pulo sem possibilidade de pulo duplo

				//muda o retangulo do sprite
				p->frame = (p->vel.x > 0) ? Managers::spriteRect(JUMP): Managers::spriteRect(JUMP_L);
			}
		}
	}
}

void Player::PlayerWalkState::draw(Managers::GraphicManager* pGraphicManager)
{
}
/********************************************************************************************
 *
 *  Player Development
 *
 ********************************************************************************************/

Player::Player(int life, Stages::Stage* pStage, bool firstPlayer, Managers::GraphicManager* pGraphicManager):
	Character(life, pGraphicManager, pStage),
	rightDirection(),
	vulnerability_timer(),
	attackTimer(),
	double_jump(),
	frameTime()
{
	vel.x = 0;
	vel.y = 0;
	setWindow(pGraphicManager->getWindowPointer());
	setControls(firstPlayer);

	this->pGraphicManager = pGraphicManager;
	this->pStage = pStage;

	frame = Managers::spriteRect(DEFAULT);
	textureId = pGraphicManager->loadTexture(firstPlayer ? PLAYER1_TEXTURE_FILE : PLAYER2_TEXTURE_FILE);
	spriteId = pGraphicManager->createSprite(textureId);
	pGraphicManager->setSpriteRect(spriteId, frame);
	stateMachine = new PlayerStateMachine(this);
}

Player::~Player()
{
	window = nullptr;
	delete stateMachine;
}

void Player::execute(float dt, Managers::EventManager* pEventManager)
{

	if(stateMachine)
		stateMachine->update(dt, pEventManager);

	move(vel.x * dt, vel.y * dt);

	if(pGraphicManager)
		pGraphicManager->setSpriteRect(spriteId, frame);

	if(!vulnerability)
	{
		if(vulnerability_timer > VULNERABILITY_MAX)
		{
			vulnerability = true;
			vulnerability_timer = 0;
		}
		vulnerability_timer += dt;
	}

	attackTimer += dt;
}
void Player::setControls(bool isPlayerOne)
{
	if(isPlayerOne)
	{
		leftKey = Managers::EventManager::keyCode::A;
		rightKey = Managers::EventManager::keyCode::D;
		jumpKey = Managers::EventManager::keyCode::W;
		attackKey = Managers::EventManager::keyCode::G;
	}
	else
	{
		leftKey = Managers::EventManager::keyCode::Left;
		rightKey = Managers::EventManager::keyCode::Right;
		jumpKey = Managers::EventManager::keyCode::Up;
		attackKey = Managers::EventManager::keyCode::RShift;
	}
}
/*
void Player::onCollide(sf::Sprite* other, float dt)
{
	if(vulnerability)
	{
		if(dynamic_cast<Projectile*>(other) != 0)
		{
			if(!dynamic_cast<Projectile*>(other)->fromPlayer())
			{
				lives -= 1;
				vulnerability = false;
			}
		}
		else if(dynamic_cast<Enemy*>(other) != 0)
		{
			lives -= 1;
			vulnerability = false;
		}
	}
}
*/