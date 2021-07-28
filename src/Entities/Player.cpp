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
	//pPlayer->double_jump = (bool&&)arg;
	p->vel.y = -p->jumpVel;
}

void Player::PlayerJumpState::update(float dt, Managers::EventManager* pEventManager)
{
	if(p)
	{
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

		p->frame = Managers::spriteRect((p->vel.x >= 0)?JUMP_X:JUMP_X+JUMP_SIZE_X,JUMP_Y,(p->vel.x >= 0)?JUMP_SIZE_X:JUMP_SIZE_X*(-1),JUMP_SIZE_Y);

		if(p->getGrounded())
		{
			pStateMachine->changeState(PLAYER_REST_STATE, NULL);
			p->vel.x = 0;

			p->frame = Managers::spriteRect((p->rightDirection)?REST_R:REST_L);
		}
		if(p->double_jump)
		{
			if(pEventManager->isKeyPressed(p->jumpKey))
			{
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)false);
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
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)true);

				// Replaces to the jump State
				p->frame = Managers::spriteRect(JUMP);
			}
			else
			{
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)false);
				p->frame = Managers::spriteRect(JUMP);
			}
		}

		else if(pEventManager->isKeyDown(p->rightKey) || pEventManager->isKeyDown(p->leftKey))
			pStateMachine->changeState(PLAYER_WALK_STATE, NULL);

		if (p->rightDirection)
			p->frame = Managers::spriteRect(REST_R);
		else
			p->frame = Managers::spriteRect(REST_L);
	}
}

void Player::PlayerRestState::draw(Managers::GraphicManager* pGraphicManager)
{

}

//PlayerWalkState-------------------
Player::PlayerWalkState::PlayerWalkState(States::StateMachine* pStateMachine, Player *p):State(pStateMachine)
{
	this->pPlayer = p;
}

Player::PlayerWalkState::~PlayerWalkState()
{
}

void Player::PlayerWalkState::update(float dt, Managers::EventManager* pEventManager)
{
	if(pPlayer)
	{
		if (pPlayer->body.getPosition().y >= pPlayer->pGraphicManager->getWindowPointer()->getSize().y)
			pPlayer->setGrounded(true);


		if(pPlayer->vel.y*pPlayer->vel.y > 5.0f)
			pPlayer->setGrounded(false);

		if(pEventManager->isKeyDown(pPlayer->rightKey))
		{
			pPlayer->rightDirection = true;

			pPlayer->vel.x += pPlayer->groundAcceleration;
			if(pPlayer->vel.x > pPlayer->velMax)
				pPlayer->vel.x = pPlayer->velMax;

			pPlayer->frameTime += dt;
			pPlayer->frame = Managers::spriteRect(sf::Rect<int>(WALK_X* (pPlayer->numRect), WALK_Y,WALK_SIZE_X,WALK_SIZE_Y));

			if(pPlayer->frameTime > WALK_ANIMATION_FRAME_TIME)
			{
				pPlayer->frameTime = 0;
				pPlayer->numRect = ((pPlayer->numRect)+1)%8;
			}
		}

		if(pEventManager->isKeyDown(pPlayer->leftKey))
		{
			pPlayer->rightDirection = false;
			pPlayer->vel.x -= pPlayer->groundAcceleration;
			if(pPlayer->vel.x < -pPlayer->velMax)
				pPlayer->vel.x = -pPlayer->velMax;

			pPlayer->frameTime += dt;
			pPlayer->frame = Managers::spriteRect(sf::Rect<int>(WALK_X * (pPlayer->numRect) + WALK_SIZE_X, WALK_Y,-WALK_SIZE_X,WALK_SIZE_Y));

			if(pPlayer->frameTime > WALK_ANIMATION_FRAME_TIME)
			{
				pPlayer->frameTime = 0;
				pPlayer->numRect = ((pPlayer->numRect)+1)%8;
			}
		}

		// Jumping State
		if(pEventManager->isKeyPressed(pPlayer->jumpKey))
		{
			if(pPlayer->isGrounded)
			{
				pPlayer->setGrounded(false);
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)true);

				pPlayer->frame = Managers::spriteRect(JUMP_X,JUMP_Y,(pPlayer->vel.x >= 0)?JUMP_SIZE_X:-JUMP_SIZE_X,JUMP_SIZE_Y);
			}
			else
			{
				pStateMachine->changeState(PLAYER_JUMP_STATE, (void*)(bool&&)false);

				//muda o retangulo do sprite
				pPlayer->frame = Managers::spriteRect(JUMP_X,JUMP_Y,(pPlayer->vel.x >= 0)?JUMP_SIZE_X:-JUMP_SIZE_X,JUMP_SIZE_Y);
			}
		}

		// Resting State
		if(!pEventManager->isKeyDown(pPlayer->rightKey) && !pEventManager->isKeyDown(pPlayer->leftKey))
		{
			pStateMachine->changeState(PLAYER_REST_STATE, NULL);
			pPlayer->vel.x = 0;
			pPlayer->frame = Managers::spriteRect((pPlayer->rightDirection)?REST_R:REST_L);
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
	rightDirection(true),
	vulnerability_timer(),
	attackTimer(),
	double_jump(),
	frameTime(),
	numRect(0)
{
	vel.x = 0;
	vel.y = 0;
	setWindow(pGraphicManager->getWindowPointer());
	setControls(firstPlayer);

	this->pGraphicManager = pGraphicManager;
	this->pStage = pStage;

	frame = Managers::spriteRect(REST_R);
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