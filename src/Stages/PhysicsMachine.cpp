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

PhysicsMachine::PhysicsMachine(){
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

void PhysicsMachine::applyGravity(float dt, EntityList &entities){

    Entities::Player* pTemp = nullptr;
    for (int i = 0; i < entities.mainList.getLen(); ++i)
    {
        pTemp = dynamic_cast<Entities::Player*>(entities.mainList.getItem(i));

        if(pTemp != nullptr && !(pTemp->getGrounded()))
            pTemp->setVel(pTemp->getVel().x, pTemp->getVel().y + 300.f*dt);

    }
}
