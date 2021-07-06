/*
	Class that acts like the game Engine
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Game
{
private:
	sf::RenderWindow window;

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void execute();
};


#endif //GAME_H