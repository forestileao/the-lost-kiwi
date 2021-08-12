//
// Created by forestileao on 08/08/2021.
//

#include <Entities/Enemy.h>
#include <Entities/Archer.h>
#include <Entities/Warrior.h>
#include "Stages/EnemySpawner.h"
#include "Stages/Stage.h"
using namespace Stages;

EnemySpawner::EnemySpawner(Stage *pStage):
    enemiesSpawned(0),
    spawnPositions(),
    pStage(pStage)
{
    srand(time(NULL));
}

EnemySpawner::~EnemySpawner()
{

}

void EnemySpawner::addSpawnPosition(sf::Vector2f spawnPos)
{
    spawnPositions.push_back(spawnPos);
}

void EnemySpawner::spawnEnemy()
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

void EnemySpawner::decrementEnemiesCount()
{
    enemiesSpawned--;
}
void EnemySpawner::setEnemiesCount(unsigned int num)
{
    enemiesSpawned = num;
}
