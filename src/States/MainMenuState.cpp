//
// Created by forestileao on 23/07/2021.
//

#include "../../include/States/MainMenuState.h"
#include "../../include/States/GameStateMachine.h"

MainMenuState::MainMenuState(States::StateMachine* pStateMachine, Managers::GraphicManager* pGraphicManager):
	States::State(pStateMachine), selected(0), timer(0)
{
	this->pGraphicManager = pGraphicManager;
	sf::View* view = pGraphicManager->getView();
	gameNameText = pGraphicManager->createText(0, "Nome Feliz Pro jogo :D", 40);
	startGameText = pGraphicManager->createText(0, "Start Game", 20);
	scoreboardText = pGraphicManager->createText(0, "Scoreboard", 20);
	quitGameText = pGraphicManager->createText(0, "Quit Game", 20);

	pGraphicManager->setTextPosition(gameNameText, view->getCenter().x - 180, 20);
	pGraphicManager->setTextPosition(startGameText, view->getCenter().x - 20, 100);
	pGraphicManager->setTextPosition(scoreboardText, view->getCenter().x - 20, 200);
	pGraphicManager->setTextPosition(quitGameText, view->getCenter().x - 20, 300);
	pGraphicManager->setTextColor(gameNameText, 0xff0000ff);
	pGraphicManager->setTextColor(startGameText, 0xffff00ff);
	pGraphicManager->setTextColor(scoreboardText, 0xffffffff);
	pGraphicManager->setTextColor(quitGameText, 0xffffffff);
}

MainMenuState::~MainMenuState()
{
	pGraphicManager = nullptr;
}

void MainMenuState::init(void* arg)
{
    timer = 0;
    background = pGraphicManager->createSprite(pGraphicManager->loadTexture(MENU_BACKGROUND_FILE));
	printf("Entrando no Menu\n");
	pGraphicManager->setBackground(background);
}

void MainMenuState::exit()
{
	std::cout << "Exiting game...\n";
}

void MainMenuState::update(float dt, Managers::EventManager* pEventManager)
{

    sf::View *view = pGraphicManager->getView();
    pGraphicManager->setTextPosition(gameNameText, view->getCenter().x - 180, 20);
    pGraphicManager->setTextPosition(startGameText, view->getCenter().x - 20, 100);
    pGraphicManager->setTextPosition(scoreboardText, view->getCenter().x - 20, 200);
    pGraphicManager->setTextPosition(quitGameText, view->getCenter().x - 20, 300);


    pGraphicManager->getView()->setCenter((pGraphicManager->getWindowPointer()->getSize().x)/2, pGraphicManager->getView()->getSize().y/2);
    pGraphicManager->getWindowPointer()->setView(*pGraphicManager->getView());
    if (timer > 0.05)
    {
        if (pEventManager->isKeyDown(sf::Keyboard::W))
            selected -= selected >= 1 ? 1 : 0;
        else if (pEventManager->isKeyDown(sf::Keyboard::S))
            selected += selected < 2 ? 1 : 0;

        timer = 0;
    }
    else
    {
        timer += dt;
        return;
    }
	if (selected == 0)
	{
		pGraphicManager->setTextColor(startGameText, 0xffff00ff);
		pGraphicManager->setTextColor(scoreboardText, 0xffffffff);
		pGraphicManager->setTextColor(quitGameText, 0xffffffff);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			int loadingArg = 1;
			((GameStateMachine *)getStateMachine())->changeState("ChoosePlayer", static_cast<void *>(&loadingArg));
		}
	}
	else if ( selected == 1)
	{
	    pGraphicManager->setTextColor(startGameText, 0xffffffff);
	    pGraphicManager->setTextColor(scoreboardText, 0xffff00ff);
	    pGraphicManager->setTextColor(quitGameText, 0xffffffff);

	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	    {
	        ((GameStateMachine *)getStateMachine())->changeState("Scoreboard", nullptr);
	    }
	}
	else if (selected == 2)
	{
	    pGraphicManager->setTextColor(startGameText, 0xffffffff);
	    pGraphicManager->setTextColor(scoreboardText, 0xffffffff);
	    pGraphicManager->setTextColor(quitGameText, 0xffff00ff);

	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	        pGraphicManager->closeWindow();
	}

}

void MainMenuState::draw(Managers::GraphicManager* pGraphicManager)
{
	pGraphicManager->drawText(gameNameText);
	pGraphicManager->drawText(startGameText);
	pGraphicManager->drawText(scoreboardText);
	pGraphicManager->drawText(quitGameText);
}