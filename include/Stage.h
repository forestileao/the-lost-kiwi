#ifndef STAGE_H
#define STAGE_H

#include "Player.h"
#include "Enemy.h"
#include "EntityList.h"

class Stage
{
private:
	sf::RenderWindow* window;

	EntityList* entityList;
	Player* player1;

	Enemy* enemy1;

	void initializeElements();

public:
	Stage(sf::RenderWindow* renderWindow, Player* p1);
	~Stage();

	EntityList* getEntityList();
};


#endif //STAGE_H
