#include "../../include/Stages/Stage.h"
using namespace Stages;

Stage::Stage(Managers::GraphicsManager *pGraphicManager):
	entities()
{
	this->pGraphicsManager = pGraphicsManager;
	initializeElements();
}

Stage::~Stage()
{

}

void Stage::initializeElements()
{

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
Managers::GraphicsManager *Stage::getGraphicsManager()
{
	return pGraphicsManager;
}
