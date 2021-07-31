#include "../../include/Stages/Stage.h"
using namespace Stages;

Stage::Stage(Managers::GraphicManager *pGraphicManager):
	entities(),
	backgroundSprite(-1),
	currentLevel(-1),
	players(-1),
	changeStage(false),
	stageScore(0)
{
	this->pGraphicManager = pGraphicManager;
	initializeElements();
}

Stage::~Stage()
{
	delete p1;
}

void Stage::initializeElements()
{
	//currentLevel = n;
	totalPlayers = players;

	p1 = new Entities::Player(10, this, true, pGraphicManager);

	p1->setPosition(100, 400);
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
		entities.mainList.getItem(i)->execute(dt, pEvents);
	}
	applyGravity(dt);
}

void Stage::addEntity(Entities::Entity *pEntity)
{
	entities.mainList.push(pEntity);
}

void Stage::removeEntity(Entities::Entity* pEntity)
{
	entities.mainList.pop(pEntity);
	Entities::Entity::decrementEntityCount();
}
Managers::GraphicManager *Stage::getGraphicManager()
{
	return pGraphicManager;
}
void Stage::applyGravity(float dt)
{
	Entities::Player* pTemp = nullptr;
	for (int i = 0; i < entities.mainList.getLen(); ++i)
	{
		pTemp = dynamic_cast<Entities::Player*>(entities.mainList.getItem(i));

		if(pTemp != nullptr && !pTemp->getGrounded())
			pTemp->setVel(pTemp->getVel().x, pTemp->getVel().y + 300.f*dt);

	}
}
