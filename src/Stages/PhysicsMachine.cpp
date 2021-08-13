//
// Created by carolsfer on 05/08/2021.
//
#include "../../include/Stages/PhysicsMachine.h"
#include "../../include/Stages/Stage.h"
#include "../../include/Stages/EntityList.h"
#include "../../include/Entities/Archer.h"
#include "../../include/Entities/Warrior.h"
#include "../../include/Entities/Dracula.h"
#include "../../include/Entities/Obstacle.h"
#include "../../include/Entities/Block.h"
#include "../../include/Entities/Spike.h"
#include "../../include/Entities/Fire.h"
#include "../../include/States/PlayState.h"
using namespace Stages;

PhysicsMachine::PhysicsMachine(Stages::Stage* pStage):
    pt_stage(pStage)
{
}

PhysicsMachine::~PhysicsMachine(){
}

void PhysicsMachine::applyCollisions(){

    Entities::Player* tempPlayer = nullptr;
    Entities::Enemy* tempEnemy = nullptr;
    Entities::Projectile* tempProj = nullptr;


    for (int i = 0; i < pt_stage->getPlayerList()->getList()->getLen(); ++i)
    {
        // player collision with other entities
        tempPlayer = dynamic_cast<Entities::Player*>(pt_stage->getPlayerList()->getList()->getItem(i));
        for (int j = 0; j < pt_stage->getEnemyList()->getList()->getLen(); ++j)
        {
            tempEnemy = dynamic_cast<Entities::Enemy*>(pt_stage->getEnemyList()->getList()->getItem(j));
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
        for (int j = 0; j < pt_stage->getProjectileList()->getList()->getLen(); ++j)
        {
            tempProj = dynamic_cast<Entities::Projectile*>(pt_stage->getProjectileList()->getList()->getItem(j));
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
        for (int j = 0; j < pt_stage->getObstacleList()->getList()->getLen(); ++j)
        {
            sf::Rect<float> blockRect = pt_stage->getObstacleList()->getList()->getItem(j)->getGlobalBounds();
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
                Entities::Obstacle* tempObstacle = (Entities::Obstacle*)pt_stage->getObstacleList()->getList()->getItem(j);
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

    for (int i = 0; i < pt_stage->getEnemyList()->getList()->getLen(); ++i)
    {
        tempEnemy = dynamic_cast<Entities::Enemy*>(pt_stage->getEnemyList()->getList()->getItem(i));
        if (!tempEnemy)
            continue;

        bool setGrounded = false;
        for (int j = 0; j < pt_stage->getObstacleList()->getList()->getLen(); ++j)
        {
            sf::Rect<float> blockRect = pt_stage->getObstacleList()->getList()->getItem(j)->getGlobalBounds();
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

        for (int j = 0; j < pt_stage->getProjectileList()->getList()->getLen(); ++j)
        {
            tempProj = dynamic_cast<Entities::Projectile*>(pt_stage->getProjectileList()->getList()->getItem(j));
            if (tempProj->isFriendly() && tempProj->intersects(tempEnemy->getGlobalBounds()))
            {
                tempEnemy->decrementLifePoints(3);
                pt_stage->removeEntity(tempProj);
                if (!tempEnemy->isAlive())
                {
                    pt_stage->getPlayState()->incrementScore(tempEnemy->getScoreValue());
                    pt_stage->removeEntity(tempEnemy);
                    pt_stage->getEnemySpawner()->decrementEnemiesCount();
                    tempEnemy = nullptr;
                    break;
                }
            }
        }
    }
}

void PhysicsMachine::applyGravity(float dt){

    Entities::Player* pTemp = nullptr;
    for (int i = 0; i < pt_stage->getPlayerList()->getList()->getLen(); ++i)
    {
        pTemp = dynamic_cast<Entities::Player*>(pt_stage->getPlayerList()->getList()->getItem(i));

        if(pTemp != nullptr && !(pTemp->getGrounded()))
            pTemp->setVel(pTemp->getVel().x, pTemp->getVel().y + 300.f*dt);

    }

    Entities::Warrior* pTempEnemy = nullptr;
    for (int i = 0; i < pt_stage->getEnemyList()->getList()->getLen(); ++i)
    {
        pTempEnemy = dynamic_cast<Entities::Warrior*>(pt_stage->getEnemyList()->getList()->getItem(i));

        if(pTempEnemy != nullptr && !(pTempEnemy->getGrounded()))
            pTempEnemy->setVel(pTempEnemy->getVel().x, pTempEnemy->getVel().y + 300.f*dt);

    }
}
