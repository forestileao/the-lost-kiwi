#include "../include/Stage.h"

// Constructors / Destructors
Stage::Stage(sf::RenderWindow* renderWindow,Player* player)
{
	window = renderWindow;
	player1 = player;
	entityList = new EntityList();

	enemy1 = new Enemy();
	enemy1->setWindow(window);
	initializeElements();
}
Stage::~Stage()
{
	delete entityList;
}
void Stage::initializeElements()
{
	entityList->mainList.push(player1);
	entityList->mainList.push(enemy1);
}
EntityList* Stage::getEntityList()
{
	return entityList;
}
