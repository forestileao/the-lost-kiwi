//
// Created by forestileao on 18/07/2021.
//

#include <Stages/Graveyard.h>
#include <Stages/Castle.h>
#include "../../include/States/PlayState.h"
PlayState::PlayState(States::StateMachine* pStateMachine, Managers::GraphicManager* pGraphicsManager):
	States::State(pStateMachine),
	graveyardBackground(-1),
	castleBackground(-1),
	currentBackground(-1),
	score(0),
    gameData()
{
	this->pGraphicManager = pGraphicsManager;
    pStage = nullptr;
	scoreText = pGraphicsManager->createText(0, "Score: 0", 20);
	playerOneLifeText = pGraphicsManager->createText(0, "Player 1: 0", 20);
	playerTwoLifeText = pGraphicsManager->createText(0, "Player 2: 0", 20);

	pGraphicsManager->setTextPosition(playerOneLifeText, 40, 20);
	pGraphicsManager->setTextPosition(playerTwoLifeText, 600, 20);
	pGraphicsManager->setTextPosition(scoreText, 255, 20);
	pGraphicsManager->setTextColor(scoreText, 0xffff00ff);
}

PlayState::~PlayState()
{
	delete pStage;
}

void PlayState::init(void* arg)
{
    gameData = *((GameData *)arg);
	printf("Entrando no jogo\n");

	if (gameData.isLoading)
	{
        return;
	}
	else if (!gameData.isResuming)
	{
	    changeStage(1, gameData.players);
	    std::cout << "Stage is loading...\n";
        return;
	}
	pGraphicManager->setBackground(currentBackground);
}

void PlayState::exit()
{
	std::cout << "Exiting game...\n";
}

void PlayState::update(float dt, Managers::EventManager* pEventManager)
{
	pStage->update(dt, pEventManager);
	std::string text = "Score: " + std::to_string(static_cast<unsigned long int>(score));

	pGraphicManager->setString(scoreText, text);

	if (pStage->getPlayer1())
	    pGraphicManager->setString(playerOneLifeText,  std::to_string(pStage->getPlayer1()->getLife()));
	if (pStage->getPlayer2())
	    pGraphicManager->setString(playerOneLifeText,  std::to_string(pStage->getPlayer2()->getLife()));

	pGraphicManager->setTextPosition(scoreText, pGraphicManager->getView()->getCenter().x, 20);
	pGraphicManager->setTextPosition(playerOneLifeText, pGraphicManager->getView()->getCenter().x + 40, 20);
	if (gameData.players == 2)
	    pGraphicManager->setTextPosition(playerTwoLifeText, pGraphicManager->getView()->getCenter().x + 600, 20);

	if(pEventManager->isKeyPressed(sf::Keyboard::P))
	    pStateMachine->changeState("PauseState", static_cast<void*>(pStage));
}

void PlayState::draw(Managers::GraphicManager* pGraphicsManager)
{
	pStage->draw();
	pGraphicsManager->drawText(scoreText);

	pGraphicsManager->drawText(playerOneLifeText);
	if (gameData.players == 2)
	    pGraphicsManager->drawText(playerTwoLifeText);
}

void PlayState::incrementScore(int num)
{
    PlayState::score += num;
}
int PlayState::getScore()
{
    return score;
}

void PlayState::changeStage(int stageNum, int playersNum)
{
    delete pStage;
    switch (stageNum)
    {
        case 1:
            graveyardBackground = pGraphicManager->createSprite(pGraphicManager->loadTexture(GRAVEYARD_BACKGROUND));
            pStage = new Stages::Graveyard(pGraphicManager, this, playersNum);
            pGraphicManager->setBackground(graveyardBackground);
            currentBackground = graveyardBackground;
            break;

        case 2:
            castleBackground = pGraphicManager->createSprite(pGraphicManager->loadTexture(CASTLE_BACKGROUND));
            pStage = new Stages::Castle(pGraphicManager, this, playersNum);
            pGraphicManager->setBackground(castleBackground);
            currentBackground = castleBackground;
            break;

        default:
            pStage = new Stages::Graveyard(pGraphicManager, this, playersNum);
            pGraphicManager->setBackground(graveyardBackground);
            currentBackground = graveyardBackground;
            break;
    }
}
