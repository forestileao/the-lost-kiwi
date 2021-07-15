#include "../include/Stage.h"

// Constructors / Destructors
Stage::Stage(sf::RenderWindow* renderWindow,Player* p1, Player* p2)
{
	window = renderWindow;
	player1 = p1;
	player2 = p2;

	entityList = new EntityList();

	enemy1 = new Enemy(10);
	enemy1->setWindow(window);
	initializeElements();
}
Stage::~Stage()
{
	delete entityList;
}
void Stage::initializeElements()
{
	entityList->mainList.push(enemy1);

	// instance players
	entityList->mainList.push(player1);

	if (player2 != NULL)
		entityList->mainList.push(player2);
}
EntityList* Stage::getEntityList()
{
	return entityList;
}
