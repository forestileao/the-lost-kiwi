//
// Created by forestileao on 05/07/2021.
//

#include "../include/Game.h"
#include "../include/States/GameStateMachine.h"

Game::Game()
{
	graphicManager = new Managers::GraphicManager(WINDOW_WIDTH, WINDOW_HEIGHT, "TecDracula");

	eventManager = new Managers::EventManager(graphicManager->getWindowPointer());
	graphicManager->loadFont("../assets/fonts/seagram-tfb.ttf");
	stateMachine = new GameStateMachine(graphicManager);

	execute();
}

Game::~Game()
{
 	delete graphicManager;
 	delete eventManager;
 	delete stateMachine;
}

void Game::update(float dt)
{
	eventManager->pollAll();

	if (eventManager->isWindowClosing())
		graphicManager->closeWindow();


	stateMachine->update(dt, eventManager);
}

void Game::draw()
{
	stateMachine->draw(graphicManager);
	graphicManager->draw();
}

void Game::execute()
{
	sf::Clock clock;
	float dt;

	while(graphicManager->isWindowOpen())
	{
		dt = clock.getElapsedTime().asSeconds();
		clock.restart();

		update(dt);
		draw();
	}
}