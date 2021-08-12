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

void PhysicsMachine::applyCollisions(EntityList &entities){

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
            {
                if (tempPlayer->getVulnerability())
                {
                    tempPlayer->decrementLifePoints(tempEnemy->getDamage());
                    tempPlayer->setVulnerability(false);
                    std::cout << "Player Life: " << tempPlayer->getLife() << '\n';
                    if (!tempPlayer->isAlive())
                    {
                        pt_stage->removeEntity(tempPlayer);
                        break;
                    }
                }
            }
        }

        for (int j = 0; j < entities.projectileList.getLen(); ++j)
        {
            tempProj = dynamic_cast<Entities::Projectile*>(entities.projectileList.getItem(j));
            if (tempProj->isFriendly()) continue;
            if (tempPlayer->intersects(tempProj->getGlobalBounds()))
            {
                tempPlayer->decrementLifePoints(2);
                std::cout << "Player Life: " << tempPlayer->getLife() << '\n';
                pt_stage->removeEntity(tempProj);
                if (!tempPlayer->isAlive())
                {
                    pt_stage->removeEntity(tempPlayer);
                    break;
                }
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

            if (tempPlayer->intersects(blockRect))
            {
                Entities::Obstacle* tempObstacle = (Entities::Obstacle*)entities.blockList.getItem(j);
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
                    tempPlayer->setPosition(tempPlayer->getPosition().x-(3), tempPlayer->getPosition().y);
                else
                    tempPlayer->setPosition(tempPlayer->getPosition().x+(3), tempPlayer->getPosition().y);
                break;
            }
        }

    }

    for (int i = 0; i < entities.enemyList.getLen(); ++i)
    {
        tempEnemy = dynamic_cast<Entities::Enemy*>(entities.enemyList.getItem(i));
        if (!tempEnemy)
            continue;

        bool setGrounded = false;
        for (int j = 0; j < entities.blockList.getLen(); ++j)
        {
            sf::Rect<float> blockRect = entities.blockList.getItem(j)->getGlobalBounds();
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

            blockRect.top+= 10;
            blockRect.width+= 10;
            if (tempEnemy->intersects(blockRect))
            {
                if ((tempEnemy->getVel().x) < 0)
                    tempEnemy->setPosition(tempEnemy->getPosition().x-(5), tempEnemy->getPosition().y);
                else
                    tempEnemy->setPosition(tempEnemy->getPosition().x+(5), tempEnemy->getPosition().y);
                break;
            }
        }

        for (int j = 0; j < entities.projectileList.getLen(); ++j)
        {
            tempProj = dynamic_cast<Entities::Projectile*>(entities.projectileList.getItem(j));
            if (tempProj->isFriendly() && tempProj->intersects(tempEnemy->getGlobalBounds()))
            {
                tempEnemy->decrementLifePoints(3);
                pt_stage->removeEntity(tempProj);
                if (!tempEnemy->isAlive())
                {
                    pt_stage->removeEntity(tempEnemy);
                    pt_stage->getEnemySpawner()->decrementEnemiesCount();
                    pt_stage->getPlayState()->incrementScore(10);
                    tempEnemy = nullptr;
                    break;
                }
            }
        }
    }
}

void PhysicsMachine::applyGravity(float dt, EntityList &entities){

    Entities::Player* pTemp = nullptr;
    for (int i = 0; i < entities.mainList.getLen(); ++i)
    {
        pTemp = dynamic_cast<Entities::Player*>(entities.mainList.getItem(i));

        if(pTemp != nullptr && !(pTemp->getGrounded()))
            pTemp->setVel(pTemp->getVel().x, pTemp->getVel().y + 300.f*dt);

    }

    Entities::Warrior* pTempEnemy = nullptr;
    for (int i = 0; i < entities.enemyList.getLen(); ++i)
    {
        pTempEnemy = dynamic_cast<Entities::Warrior*>(entities.enemyList.getItem(i));

        if(pTempEnemy != nullptr && !(pTempEnemy->getGrounded()))
            pTempEnemy->setVel(pTempEnemy->getVel().x, pTempEnemy->getVel().y + 300.f*dt);

    }
}
