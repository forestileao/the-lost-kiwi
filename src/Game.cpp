//
// Created by forestileao on 05/07/2021.
//

#include "../include/Game.h"
#include "iostream"

Game::Game():
	window(sf::VideoMode(800, 600), "The Lost Kiwi", sf::Style::Close | sf::Style::Titlebar)
{
	window.setFramerateLimit(60);

	player1 = new Player();
	player1->setWindow(&window);

	stage1 = new Stage(&window, player1);
	entityList = stage1->getEntityList();


	execute();
}

Game::~Game()
{
 	delete player1;
 	delete stage1;
}

void Game::update()
{
	player1->move();
}

void Game::draw()
{
	for (int i = 0; i < entityList->mainList.getLen(); i++)
	{
		Entity* temp = entityList->mainList.getItem(i);
		temp->draw();
	}
}

void Game::execute()
{
	// Game loop
	while(window.isOpen())
	{
		sf::Event event;
		// Event Polling: verifies every time if it needs to start an event
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		// Updates entities positions
		update();

		window.clear(sf::Color(0x282A36ff)); // clear old frame

		// Draw all entities
		draw();

		window.display(); // display the drawing changes
	}
}