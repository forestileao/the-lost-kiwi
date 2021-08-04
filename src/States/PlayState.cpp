//
// Created by forestileao on 18/07/2021.
//

#include "../../include/States/PlayState.h"
PlayState::PlayState(States::StateMachine* pStateMachine, Managers::GraphicManager* pGraphicsManager):
	States::State(pStateMachine),
	score(0)
{
	this->pGraphicManager = pGraphicsManager;
	pStage = nullptr;
	scoreText = pGraphicsManager->createText(0, "Score: 0", 20);
	pGraphicsManager->setTextPosition(scoreText, 255, 20);
	pGraphicsManager->setTextColor(scoreText, 0xffff00ff);
}

PlayState::~PlayState()
{
	delete pStage;
}

void PlayState::init(void* arg)
{
	printf("Entrando no jogo\n");
	if(arg)
	{
		if (pStage)
			delete pStage;

		std::cout << "Stage is loading...\n";

		pStage = new Stages::Stage(pGraphicManager, this);

		// TODO: Implement Pause State
	}
	else if(pStage)
	{
		//pGraphicManager->setBackground(pStage->getBackground());
	}
}

void PlayState::exit()
{
	std::cout << "Exiting game...\n";
}

void PlayState::update(float dt, Managers::EventManager* pEventManager)
{
	pStage->update(dt, pEventManager);
	// score = pStage->getScore();
	std::string text = "Score: " + std::to_string(static_cast<unsigned long int>(score));

	pGraphicManager->setString(scoreText, text);
	pGraphicManager->setTextPosition(scoreText, pGraphicManager->getView()->getCenter().x, 20);
}

void PlayState::draw(Managers::GraphicManager* pGraphicsManager)
{
	pStage->draw();
	pGraphicsManager->drawText(scoreText);
}

void PlayState::incrementScore(int num)
{
    PlayState::score += num;
}
