#include "../../include/Stages/Stage.h"
using namespace Stages;

Stage::Stage(Managers::GraphicManager *pGraphicManager):
	entities()
{
	this->pGraphicsManager = pGraphicsManager;
	p1 = new Entities::Player(10);
	p1->setWindow(pGraphicManager->getWindowPointer());
	initializeElements();
}

Stage::~Stage()
{
	delete p1;
}

void Stage::initializeElements()
{
	addEntity(p1);
}


// Draws all Entities
void Stage::draw()
{
	for (int i = 0; i < entities.mainList.getLen(); ++i)
	{
		entities.mainList.getItem(i)->draw();
	}
}

// Updates all entities
void Stage::update(float dt, Managers::EventManager *pEvents)
{
	for (int i = 0; i < entities.mainList.getLen(); ++i)
	{
		entities.mainList.getItem(i)->execute();
	}
}

void Stage::addEntity(Entities::Entity *pEntity)
{
	entities.mainList.push(pEntity);
}

void Stage::removeEntity(Managers::uniqueId id)
{
	entities.mainList.pop(entities.mainList.getItem(id));
}
Managers::GraphicManager *Stage::getGraphicsManager()
{
	return pGraphicsManager;
}
