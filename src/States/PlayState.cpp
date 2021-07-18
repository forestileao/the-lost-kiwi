//
// Created by forestileao on 18/07/2021.
//

#include "../../include/States/PlayState.h"

PlayState::PlayState(States::StateMachine* pStateMachine, Managers::GraphicsManager* pGraphicsManager):
	States::State(pStateMachine), score(0)
{
	this->pGraphicManager = pGraphicsManager;
	pStage = nullptr;

	scoreText = pGraphicsManager->createText(0, "Score: 0", 20);
	pGraphicsManager->setTextPosition(scoreText, 255, 20);
	pGraphicsManager->setTextColor(scoreText, 255, 255, 0, 255);
}

PlayState::~PlayState()
{
	delete pStage;
}

void PlayState::enter(void* arg)
{
	printf("Entrando no jogo\n");
	if(arg)
	{
		if (pStage)
			delete pStage;

		printf("loading level\n");

		pStage = new Stages::Stage(pGraphicManager);
		int* rArgs = (int*)(arg);

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

	// If Game Over
	/*if(!pStage->getPlayers())
	{
		int finalScore = score;
		pStateMachine->changeState("GameOverState", (void*)&finalScore);
	}
	 */
}

void PlayState::draw(Managers::GraphicsManager* pGraphicsManager)
{
	pStage->draw();
	pGraphicsManager->drawText(scoreText);
}