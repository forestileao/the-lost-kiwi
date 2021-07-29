//
// Created by forestileao on 23/07/2021.
//

#include "../../include/States/MainMenuState.h"
#include "../../include/States/GameStateMachine.h"

MainMenuState::MainMenuState(States::StateMachine* pStateMachine, Managers::GraphicManager* pGraphicManager):
	States::State(pStateMachine), selected(0)
{
	this->pGraphicManager = pGraphicManager;

	gameNameText = pGraphicManager->createText(0, "Nome Feliz Pro jogo :D", 40);
	startGameText = pGraphicManager->createText(0, "Start Game", 20);
	quitGameText = pGraphicManager->createText(0, "Quit Game", 20);

	pGraphicManager->setTextPosition(gameNameText, 100, 20);
	pGraphicManager->setTextPosition(startGameText, 255, 100);
	pGraphicManager->setTextPosition(quitGameText, 255, 200);
	pGraphicManager->setTextColor(gameNameText, 0xff0000ff);
	pGraphicManager->setTextColor(startGameText, 0xffff00ff);
	pGraphicManager->setTextColor(quitGameText, 0xffffffff);

	background = pGraphicManager->createSprite(pGraphicManager->loadTexture(MENU_BACKGROUND_FILE));
}

MainMenuState::~MainMenuState()
{
	pGraphicManager = nullptr;
}

void MainMenuState::init(void* arg)
{
	printf("Entrando no Menu\n");
	pGraphicManager->setBackground(background);
}

void MainMenuState::exit()
{
	std::cout << "Exiting game...\n";
}

void MainMenuState::update(float dt, Managers::EventManager* pEventManager)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		selected -= selected == 1 ?1: 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		selected += selected == 0 ?1:0;

	if (selected == 0)
	{
		pGraphicManager->setTextColor(startGameText, 0xffff00ff);
		pGraphicManager->setTextColor(quitGameText, 0xffffffff);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			int loadingArg = 1;
			((GameStateMachine *)getStateMachine())->changeState("PlayState", static_cast<void *>(&loadingArg));
		}
	}
	else if ( selected == 1)
	{
		pGraphicManager->setTextColor(startGameText, 0xffffffff);
		pGraphicManager->setTextColor(quitGameText, 0xffff00ff);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			pGraphicManager->closeWindow();
	}

}

void MainMenuState::draw(Managers::GraphicManager* pGraphicManager)
{
	pGraphicManager->drawText(gameNameText);
	pGraphicManager->drawText(startGameText);
	pGraphicManager->drawText(quitGameText);
}