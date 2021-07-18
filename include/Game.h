/*
	Class that acts like the game Engine
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include "EntityList.h"
#include "Stage.h"

class Game
{
private:
	sf::RenderWindow window;
	Player* player1;
	Player* player2;
	EntityList* entityList;
	Stage* stage1;

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