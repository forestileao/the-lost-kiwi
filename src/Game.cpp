//
// Created by forestileao on 05/07/2021.
//

#include "Game.h"

Game::Game():
	window(sf::VideoMode(800, 600), "The Lost Kiwi", sf::Style::Close | sf::Style::Titlebar)
{
	execute();
}

Game::~Game()
{

}

void Game::execute()
{
	// Game loop
	while(window.isOpen())
	{
		sf::Event ev;
		// Event Polling: verifies every time if it needs to start an event
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();

				break;
			}
		}

		// Update

		// Render
		window.clear(sf::Color(0x282A36ff)); // clear old frame

		// Draw

		window.display(); // display the drawing changes
	}
}