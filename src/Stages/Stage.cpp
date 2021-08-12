#include <fstream>
#include <Entities/Warrior.h>
#include "../../include/Stages/Stage.h"
#include "../../include/Entities/Archer.h"
#include "../../include/Entities/Obstacle.h"
#include "../../include/Entities/Block.h"
#include "../../include/Entities/Spike.h"
#include "../../include/Entities/Fire.h"
#include "../../include/States/PlayState.h"


using namespace Stages;

Stage::Stage(Managers::GraphicManager *pGraphicManager, PlayState* pState, int playersNum):
	entities(),
	backgroundSprite(-1),
	players(playersNum),
	changeStage(false),
	pState(pState),
    physics(this),
    spawner(this)
{
    p1 = nullptr;
    p2 = nullptr;
	this->pGraphicManager = pGraphicManager;
}

Stage::~Stage()
{
    delete p1;
    delete p2;
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
    finishStage();
    spawner.spawnEnemy();
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

	if (p1 && p2)
	{
	    if (!p1->isAlive() && !p2->isAlive())
        {
	        int score = pState->getScore();
            pState->getStateMachine()->changeState("GameOver", static_cast<void *>(&score));
        }
	}
	else if (p1)
	{
	    if (!p1->isAlive())
	    {
	        int score = pState->getScore();
	        pState->getStateMachine()->changeState("GameOver", static_cast<void *>(&score));
	    }
	}
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
    bool isPlayer = false;
    if (dynamic_cast<Entities::Enemy*>(pEntity))
        entities.enemyList.pop(pEntity);
    else if (dynamic_cast<Entities::Obstacle*>(pEntity))
        entities.blockList.pop(pEntity);
    else if (dynamic_cast<Entities::Projectile*>(pEntity))
        entities.projectileList.pop(pEntity);
    else if (dynamic_cast<Entities::Player*>(pEntity))
    { entities.mainList.pop(pEntity); isPlayer = true; }

    if (!isPlayer)
        delete pEntity;

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

void Stage::updateViewLocation()
{
    if (pGraphicManager)
    {
        sf::View* view = pGraphicManager->getView();

        if (p1 && p2 && p1->isAlive() && p2->isAlive())
        {
            view->setCenter(sf::Vector2f((p1->getPosition().x + p2->getPosition().x)/2,
                                         480/2));
        }
        else if (p1 && p1->isAlive())
        {
            view->setCenter(sf::Vector2f(p1->getPosition().x,
                                         480/2));
        }
        else if (p2 && p2->isAlive())
        {
                view->setCenter(sf::Vector2f(p2->getPosition().x,
                                             480/2));
        }
        pGraphicManager->getWindowPointer()->setView(*view);
    }
}

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
                spawner.addSpawnPosition(sf::Vector2f(i*40, lineCount*40));
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
Entities::Player *Stage::getPlayer1()
{
    return p1;
}
Entities::Player *Stage::getPlayer2()
{
    return p2;
}
EnemySpawner *Stage::getEnemySpawner()
{
    return &spawner;
}
void Stage::loadGame(char* fileName)
{
    removeEntity(p1);
    delete p1;
    delete p2;
    p1 = nullptr;
    p2 = nullptr;

    std::ifstream input;
    string line;

    int entitiesNum, entityType, entityLife;
    float entityPosX, entityPosY;

    input.open(fileName);
    Entities::Enemy* tempEnemy = nullptr;

    getline(input,line); // skips line

    getline(input,line) >> entitiesNum;
    players = entitiesNum;

    getline(input,line) >> entityLife
                                >> entityPosX >> entityPosY;
    p1 = new Entities::Player(entityLife, this, true, pGraphicManager);
    p1->setPosition(entityPosX, entityPosY);
    p1->setGrounded(false);
    addEntity(p1);

    if (entitiesNum == 2)
    {
        getline(input,line) >> entityLife
                                    >> entityPosX >> entityPosY;
        p2 = new Entities::Player(entityLife, this, false, pGraphicManager);
        p2->setPosition(entityPosX, entityPosY);
        p2->setGrounded(false);
        addEntity(p2);
    }

    getline(input,line) >> entitiesNum;
    spawner.setEnemiesCount(entitiesNum);

    for (int i = 0; i < entitiesNum; i ++)
    {
        getline(input,line) >> entityType >> entityLife
                                    >> entityPosX >> entityPosY;

        if (entityType)
            tempEnemy = new Entities::Warrior(entityLife, 20, p1, p2, pGraphicManager, this);
        else
            tempEnemy = new Entities::Archer(entityLife, 15, p1, p2, pGraphicManager, this);

        tempEnemy->setLife(entityLife);
        tempEnemy->setPosition(entityPosX, entityPosY);
        addEntity(tempEnemy);
    }
    input.close();
}