//
// Created by carolsfer on 05/08/2021.
//
#include "../../include/Stages/PhysicsEngine.h"
#include "../../include/Stages/Stage.h"
#include "../../include/Stages/EntityList.h"
#include "../../include/Entities/Archer.h"
#include "../../include/Entities/Warrior.h"
#include "../../include/Entities/Dracula.h"
#include "../../include/Entities/Obstacle.h"
#include "../../include/Entities/Platform.h"
#include "../../include/Entities/Spike.h"
#include "../../include/Entities/Fire.h"
#include "../../include/States/PlayState.h"
using namespace Stages;

PhysicsEngine::PhysicsEngine(Stages::Stage* pStage):
    pt_stage(pStage)
{
    playerList = pt_stage->getPlayerList();
    enemyList = pt_stage->getEnemyList();
    obstacleList = pt_stage->getObstacleList();
    projectileList = pt_stage->getProjectileList();
}

PhysicsEngine::~PhysicsEngine(){
}

void PhysicsEngine::applyCollisions(){

    Entities::Player* tempPlayer = nullptr;
    Entities::Enemy* tempEnemy = nullptr;
    Entities::Projectile* tempProj = nullptr;


    for (int i = 0; i < playerList->getList()->getLen(); ++i)
    {
        // player collision with other entities
        tempPlayer = dynamic_cast<Entities::Player*>((*playerList->getList())[i]);
        for (int j = 0; j < enemyList->getList()->getLen(); ++j)
        {
            tempEnemy = dynamic_cast<Entities::Enemy*>(enemyList->getList()->getItem(j));
            if (tempPlayer->intersects(tempEnemy->getGlobalBounds()))
            {
                if (tempPlayer->getVulnerability())
                {
                    tempPlayer->decrementLifePoints(tempEnemy->getDamage());
                    tempPlayer->setVulnerability(false);
                    std::cout << "Player Life: " << tempPlayer->getLife() << '\n';
                    if (!tempPlayer->isAlive())
                    {
                        pt_stage->removeEntity(tempPlayer);
                        tempPlayer = nullptr;
                        break;
                    }
                }
            }
        }
        if (!tempPlayer)
            continue;
        for (int j = 0; j < projectileList->getList()->getLen(); ++j)
        {
            tempProj = dynamic_cast<Entities::Projectile*>((*projectileList->getList())[j]);
            if (tempProj->isFriendly()) continue;
            if (tempPlayer->intersects(tempProj->getGlobalBounds()))
            {
                tempPlayer->decrementLifePoints(2);
                std::cout << "Player Life: " << tempPlayer->getLife() << '\n';
                pt_stage->removeEntity(tempProj);
                if (!tempPlayer->isAlive())
                {
                    pt_stage->removeEntity(tempPlayer);
                    tempPlayer = nullptr;
                    break;
                }
            }
        }
        if (!tempPlayer)
            continue;
        bool setGrounded = false;
        for (int j = 0; j < obstacleList->getList()->getLen(); ++j)
        {
            sf::Rect<float> blockRect = (*obstacleList->getList())[j]->getGlobalBounds();
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

            if (tempPlayer->intersects(blockRect))
            {
                Entities::Obstacle* tempObstacle = (Entities::Obstacle*)(*obstacleList->getList())[j];
                if (tempObstacle->getDamage() > 0)
                {
                    if (tempPlayer->getVulnerability())
                        tempPlayer->decrementLifePoints(tempObstacle->getDamage());
                    tempPlayer->setVulnerability(false);
                    if (!tempPlayer->isAlive())
                    {
                        pt_stage->removeEntity(tempPlayer);
                        tempPlayer = nullptr;
                        break;
                    }
                }
            }

            blockRect.top+=10;
            if (tempPlayer->intersects(blockRect))
            {
                if ((tempPlayer->getVel().x) > 0)
                    tempPlayer->setPosition(tempPlayer->getPosition().x-(4), tempPlayer->getPosition().y);
                else
                    tempPlayer->setPosition(tempPlayer->getPosition().x+(4), tempPlayer->getPosition().y);
                break;
            }
        }

    }

    for (int i = 0; i < enemyList->getList()->getLen(); ++i)
    {
        tempEnemy = dynamic_cast<Entities::Enemy*>((*enemyList->getList())[i]);
        if (!tempEnemy)
            continue;

        bool setGrounded = false;
        for (int j = 0; j < obstacleList->getList()->getLen(); ++j)
        {
            sf::Rect<float> blockRect = (*obstacleList->getList())[j]->getGlobalBounds();
            blockRect.height += 5;
            blockRect.top -= 10;
            if (!setGrounded)
            {
                if (tempEnemy->intersects(blockRect)) {
                    tempEnemy->setGrounded(true);
                    tempEnemy->setVel(tempEnemy->getVel().x, 0);
                    setGrounded = true;
                }
                else {
                    tempEnemy->setGrounded(false);
                }
            }

            blockRect.top+= 20;
            blockRect.height /= 20;

            if ((tempEnemy->getVel().x) > 0)
            {
                blockRect.left-= 10;
            }
            else if ((tempEnemy->getVel().x) < 0)
            {
                blockRect.left+= 10;
            }
            else
            {
                continue;
            }
            if (tempEnemy->intersects(blockRect))
            {
                if ((tempEnemy->getVel().x) > 0)
                {
                    tempEnemy->setPosition(tempEnemy->getPosition().x - (2), tempEnemy->getPosition().y);
                }
                else
                {
                    tempEnemy->setPosition(tempEnemy->getPosition().x +2, tempEnemy->getPosition().y);
                }
                break;
            }
        }

        for (int j = 0; j < projectileList->getList()->getLen(); ++j)
        {
            tempProj = dynamic_cast<Entities::Projectile*>((*projectileList->getList())[j]);
            if (tempProj->isFriendly() && tempProj->intersects(tempEnemy->getGlobalBounds()))
            {
                tempEnemy->decrementLifePoints(3);
                pt_stage->removeEntity(tempProj);
                if (!tempEnemy->isAlive())
                {
                    (*pt_stage->getPlayState()) += tempEnemy->getScoreValue();
                    pt_stage->removeEntity(tempEnemy);
                    pt_stage->getEnemySpawner()->decrementEnemiesCount();
                    tempEnemy = nullptr;
                    break;
                }
            }
        }
    }
}

void PhysicsEngine::applyGravity(float dt){

    Entities::Player* pTemp = nullptr;
    for (int i = 0; i < pt_stage->getPlayerList()->getList()->getLen(); ++i)
    {
        pTemp = dynamic_cast<Entities::Player*>((*playerList->getList())[i]);

        if(pTemp != nullptr && !(pTemp->getGrounded()))
            pTemp->setVel(pTemp->getVel().x, pTemp->getVel().y + 300.f*dt);

    }

    Entities::Warrior* pTempEnemy = nullptr;
    for (int i = 0; i < enemyList->getList()->getLen(); ++i)
    {
        pTempEnemy = dynamic_cast<Entities::Warrior*>((*enemyList->getList())[i]);

        if(pTempEnemy != nullptr && !(pTempEnemy->getGrounded()))
            pTempEnemy->setVel(pTempEnemy->getVel().x, pTempEnemy->getVel().y + 300.f*dt);

    }
}
