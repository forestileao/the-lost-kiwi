#include "../../include/Stages/Stage.h"
#include "../../include/Entities/Archer.h"
#include "../../include/Entities/Warrior.h"
#include "../../include/Entities/Dracula.h"
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
	p1->setPosition(100, 440);

	p2 = new Entities::Player(10, this, false, pGraphicManager);
	p2->setPosition(150, 440);


	Entities::Archer* archer = new Entities::Archer(10,10,p1, p2,pGraphicManager,this);
	Entities::Archer* archer2 = new Entities::Archer(10,10,p1, p2,pGraphicManager,this);
	Entities::Warrior* warrior = new Entities::Warrior(10,10,p1, p2,pGraphicManager,this);
	Entities::Dracula* dracula = new Entities::Dracula(10,10,p1, p2,pGraphicManager,this);
	archer->setPosition(200, 440);
	archer2->setPosition(300, 440);
	warrior->setPosition(400, 440);
	dracula->setPosition(500, 400);

	addEntity(p1);
	addEntity(p2);
    addEntity(archer);
    addEntity(archer2);
    addEntity(warrior);
    addEntity(dracula);
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
	updateViewLocation();
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

		if(pTemp != nullptr && !(pTemp->getGrounded()))
			pTemp->setVel(pTemp->getVel().x, pTemp->getVel().y + 300.f*dt);

	}
}
void Stage::updateViewLocation()
{
    if (pGraphicManager)
    {
        sf::View* view = pGraphicManager->getView();

        if (p1 && p2)
        {
            view->setCenter(sf::Vector2f((p1->getPosition().x + p2->getPosition().x)/2,
                                         pGraphicManager->getWindowPointer()->getSize().y/2));
        }
        else if (p1)
        {
            view->setCenter(sf::Vector2f(p1->getPosition().x,
                                         pGraphicManager->getWindowPointer()->getSize().y/2));
        }
        pGraphicManager->getWindowPointer()->setView(*view);
    }
}
