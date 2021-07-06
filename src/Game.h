/*
	Class that acts like the game Engine
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Enemy.h"


class Game
{
private:
	sf::RenderWindow window;

	// Entities
	Player player1;

	Enemy enemy;
public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void update();
	void draw();
	void execute();
};


#endif //GAME_H