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
#include "Stages/EntityList.h"
#include "Stages/Stage.h"
#include "States/StateMachine.h"

#define WINDOW_HEIGHT   480
#define WINDOW_WIDTH    840

class Game
{
private:
	Managers::GraphicManager* graphicManager;
	Managers::EventManager* eventManager;
	States::StateMachine* stateMachine;

	sf::RenderWindow window;

	// private Functions
	void update(float dt);
	void draw();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Functions
	void execute();
};


#endif //GAME_H