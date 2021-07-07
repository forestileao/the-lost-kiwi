//
// Created by forestileao on 05/07/2021.
//

#include "Game.h"

Game::Game():
	window(sf::VideoMode(800, 600), "The Lost Kiwi", sf::Style::Close | sf::Style::Titlebar),
	player1(),
	enemy()
{
	window.setFramerateLimit(60);

	player1.setWindow(&window);
	enemy.setWindow(&window);
	execute();
}

Game::~Game()
{

}

void Game::update()
{
	player1.move();
}

void Game::draw()
{
	enemy.draw();
	player1.draw();
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