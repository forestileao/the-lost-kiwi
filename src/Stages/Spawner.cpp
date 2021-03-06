//
// Created by forestileao on 08/08/2021.
//

#include <Entities/Enemy.h>
#include <Entities/Archer.h>
#include <Entities/Warrior.h>
#include <Entities/Obstacle.h>
#include <Entities/Fire.h>
#include <Entities/Spike.h>
#include "Stages/Spawner.h"
#include "Stages/Stage.h"
using namespace Stages;

Spawner::Spawner(Stage *pStage):
    enemiesSpawned(0),
    obstaclesSpawned(0),
    spawnPositions(),
    pStage(pStage),
    didSpawnedObstacles(false)
{
    srand(time(NULL));
    srand(time(NULL));
}

Spawner::~Spawner()
{

}

void Spawner::addSpawnPosition(sf::Vector2f spawnPos)
{
    spawnPositions.push_back(spawnPos);
}

void Spawner::spawnEnemy()
{
    Entities::Enemy* newEnemy = nullptr;
    if (enemiesSpawned < maxEnemies && spawnPositions.size() > 0)
    {
        int enemyType = rand() % 2;
        if (enemyType == 0)
            newEnemy = new Entities::Archer(10,
                                            15,
                                            pStage->getPlayer1(),
                                            pStage->getPlayer2(),
                                            pStage->getGraphicManager(),
                                            pStage);
        else
            newEnemy = new Entities::Warrior(15,
                                             20,
                                             pStage->getPlayer1(),
                                             pStage->getPlayer2(),
                                             pStage->getGraphicManager(),
                                             pStage);

        sf::Vector2f randomPosition = spawnPositions[rand()%spawnPositions.size()];
        newEnemy->setPosition(randomPosition.x, randomPosition.y);

        pStage->addEntity(newEnemy);
        enemiesSpawned++;
    }
}

void Spawner::decrementEnemiesCount()
{
    enemiesSpawned--;
}
void Spawner::setEnemiesCount(unsigned int num)
{
    enemiesSpawned = num;
}
void Spawner::spawnObstacles()
{
    if (obstaclesSpawned < maxObstacles)
    {
        obstaclesSpawned++;
        spawnObstacles();
    }
    else
    {
        didSpawnedObstacles = true;
        return;
    }

    int enemyType = (rand() % 2), positionIndex;
    Entities::Obstacle* newObstacle;
    if (enemyType)
        newObstacle = new Entities::Fire(pStage->getGraphicManager(), pStage);
    else
        newObstacle = new Entities::Spike(pStage->getGraphicManager(), pStage);

    positionIndex = rand()%spawnPositions.size();
    sf::Vector2f randomPosition = spawnPositions[positionIndex];
    newObstacle->setPosition(randomPosition.x, randomPosition.y);
    spawnPositions.erase(spawnPositions.begin() + positionIndex);
    pStage->addEntity(newObstacle);
}
void Spawner::setObstaclesCount(unsigned int num)
{
    obstaclesSpawned = num;
}
bool Spawner::didObstaclesSpawned() const
{
    return didSpawnedObstacles;
}
