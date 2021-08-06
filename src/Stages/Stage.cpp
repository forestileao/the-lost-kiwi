#include <fstream>
#include "../../include/Stages/Stage.h"
#include "../../include/Stages/PhysicsMachine.h"
#include "../../include/Entities/Archer.h"
#include "../../include/Entities/Warrior.h"
#include "../../include/Entities/Dracula.h"
#include "../../include/Entities/Obstacle.h"
#include "../../include/Entities/Block.h"
#include "../../include/Entities/Spike.h"
#include "../../include/Entities/Fire.h"
#include "../../include/States/PlayState.h"
using namespace Stages;

Stage::Stage(Managers::GraphicManager *pGraphicManager, PlayState* pState):
	entities(),
	backgroundSprite(-1),
	players(-1),
	changeStage(false),
	pState(pState),
    physics(this)
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

	p1 = new Entities::Player(10, this, true, pGraphicManager);
	p1->setPosition(100, 200);

	p2 = new Entities::Player(10, this, false, pGraphicManager);
	p2->setPosition(150, 200);


	Entities::Archer* archer = new Entities::Archer(10,10,p1, p2,pGraphicManager,this);
	Entities::Archer* archer2 = new Entities::Archer(10,10,p1, p2,pGraphicManager,this);
	Entities::Warrior* warrior = new Entities::Warrior(10,10,p1, p2,pGraphicManager,this);
	Entities::Dracula* dracula = new Entities::Dracula(10,10,p1, p2,pGraphicManager,this);
	archer->setPosition(200, 350);
	archer2->setPosition(300, 350);
	warrior->setPosition(400, 350);
	dracula->setPosition(500, 300);

    loadMap("../assets/cemiterio.txt");
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
	for (int i = 0; i < entities.enemyList.getLen(); ++i)
	    entities.enemyList.getItem(i)->draw();

	for (int i = 0; i < entities.blockList.getLen(); ++i)
	    entities.blockList.getItem(i)->draw();

	for (int i = 0; i < entities.projectileList.getLen(); ++i)
	    entities.projectileList.getItem(i)->draw();

	for (int i = 0; i < entities.mainList.getLen(); ++i)
	    entities.mainList.getItem(i)->draw();
}

// Updates all entities
void Stage::update(float dt, Managers::EventManager *pEvents)
{
	for (int i = 0; i < entities.mainList.getLen(); ++i)
		entities.mainList.getItem(i)->execute(dt, pEvents);

	for (int i = 0; i < entities.enemyList.getLen(); ++i)
	    entities.enemyList.getItem(i)->execute(dt, pEvents);

	for (int i = 0; i < entities.blockList.getLen(); ++i)
	    entities.blockList.getItem(i)->execute(dt, pEvents);

	for (int i = 0; i < entities.projectileList.getLen(); ++i)
	    entities.projectileList.getItem(i)->execute(dt, pEvents);

	physics.applyCollisions(entities);
	physics.applyGravity(dt, entities);
	updateViewLocation();
}

void Stage::addEntity(Entities::Entity *pEntity)
{
    /* Dynamic Cast can be used to verify the Entity Type:
     * Returns null if it is not instance of a type */
    if (dynamic_cast<Entities::Player*>(pEntity))
	    entities.mainList.push(pEntity);
    else if (dynamic_cast<Entities::Enemy*>(pEntity))
        entities.enemyList.push(pEntity);
    else if (dynamic_cast<Entities::Obstacle*>(pEntity))
        entities.blockList.push(pEntity);
    else if (dynamic_cast<Entities::Projectile*>(pEntity))
        entities.projectileList.push(pEntity);
}

void Stage::removeEntity(Entities::Entity* pEntity)
{
    if (dynamic_cast<Entities::Player*>(pEntity))
        entities.mainList.pop(pEntity);
    else if (dynamic_cast<Entities::Enemy*>(pEntity))
        entities.enemyList.pop(pEntity);
    else if (dynamic_cast<Entities::Obstacle*>(pEntity))
        entities.blockList.pop(pEntity);
    else if (dynamic_cast<Entities::Projectile*>(pEntity))
        entities.projectileList.pop(pEntity);

	Entities::Entity::decrementEntityCount();
}
EntityList Stage::getEntitylist()
{
	return entities;
}

Managers::GraphicManager *Stage::getGraphicManager()
{
	return pGraphicManager;
}
/*
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
*/
void Stage::updateViewLocation()
{
    if (pGraphicManager)
    {
        sf::View* view = pGraphicManager->getView();

        if (p1 && p2 && p1->isAlive() && p2->isAlive())
        {
            view->setCenter(sf::Vector2f((p1->getPosition().x + p2->getPosition().x)/2,
                                         pGraphicManager->getWindowPointer()->getSize().y/2));
        }
        else if (p1 && p1->isAlive())
        {
            view->setCenter(sf::Vector2f(p1->getPosition().x,
                                         pGraphicManager->getWindowPointer()->getSize().y/2));
        }
        else if (p2 && p2->isAlive())
        {
                view->setCenter(sf::Vector2f(p2->getPosition().x,
                                             pGraphicManager->getWindowPointer()->getSize().y/2));
        }
        pGraphicManager->getWindowPointer()->setView(*view);
    }
}
/*
void Stage::applyCollisions()
{
    Entities::Player* tempPlayer = nullptr;
    Entities::Enemy* tempEnemy = nullptr;
    Entities::Projectile* tempProj = nullptr;

    for (int i = 0; i < entities.mainList.getLen(); ++i)
    {
        // player collision with other entities
        tempPlayer = dynamic_cast<Entities::Player*>(entities.mainList.getItem(i));
        for (int j = 0; j < entities.enemyList.getLen(); ++j)
        {
            tempEnemy = dynamic_cast<Entities::Enemy*>(entities.enemyList.getItem(j));
            if (tempPlayer->intersects(tempEnemy->getGlobalBounds()))
               std::cout << "COLIDIU CARA !!!!!!!!!!!\n";
        }

        for (int j = 0; j < entities.projectileList.getLen(); ++j)
        {
            tempProj = dynamic_cast<Entities::Projectile*>(entities.projectileList.getItem(j));
            if (tempProj->isFriendly()) continue;
            if (tempPlayer->intersects(tempProj->getGlobalBounds()))
            {
                tempPlayer->decrementLifePoints(3);
                std::cout << "VISH TOMO TIRO MEO\n";
            }
        }

        bool setGrounded = false;
        for (int j = 0; j < entities.blockList.getLen(); ++j)
        {
            sf::Rect<float> blockRect = entities.blockList.getItem(j)->getGlobalBounds();
            if (!setGrounded)
            {
                if (tempPlayer->intersects(blockRect)) {
                    tempPlayer->setGrounded(true);
                    tempPlayer->setVel(tempPlayer->getVel().x, 0);
                    setGrounded = true;
                }
                else {
                    tempPlayer->setGrounded(false);
                }
            }

            blockRect.top+=10;
            if (tempPlayer->intersects(blockRect)) {
                if ((tempPlayer->getVel().x) > 0)
                    tempPlayer->setPosition(tempPlayer->getPosition().x-(3), tempPlayer->getPosition().y);
                else
                    tempPlayer->setPosition(tempPlayer->getPosition().x+(3), tempPlayer->getPosition().y);
                break;
            }
        }

    }
}
*/
void Stage::loadMap(char* fileName)
{
    std::ifstream input;
    string line;
    int lineCount = 0;
    input.open(fileName);
    Entities::Obstacle* tempObstacle = nullptr;
    while(input.good()){
        getline(input,line);

        for(int i = 0; i != line.length(); i++)
        {
            switch (line[i])
            {
            case '0':
                tempObstacle = new Entities::Block(true,pGraphicManager, this);
                break;
            case '1':
                tempObstacle = new Entities::Block(false,pGraphicManager, this);
                break;
            case '2':
                tempObstacle = new Entities::Spike(pGraphicManager, this);
                break;
            case '3':
                tempObstacle = new Entities::Fire(pGraphicManager, this);
                break;
            case '&':
                // TODO: set mob spawner position
                break;
            }
            if (tempObstacle)
            {
                tempObstacle->setPosition(i*40,lineCount*40);
                addEntity(tempObstacle);
            }
            tempObstacle = nullptr;
        }
        lineCount++;
    }
    input.close();
}
PlayState *Stage::getPlayState() const
{
    return pState;
}
