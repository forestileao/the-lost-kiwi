//
// Created by forestileao on 05/07/2021.
//

#include <cmath>
#include "../../include/Entities/Enemy.h"
using namespace Entities;

Enemy::Enemy(int life, int value, Player *p1, Player *p2, Managers::GraphicManager *pGraphicManager,
             Stages::Stage *pStage):
    pStage(pStage),
    pPlayer1(p1),
    pPlayer2(p2),
    scoreValue(value),
    Character(life, pGraphicManager, pStage),
    targetDistance(0),
    damage(2)
{
    attackTarget = nullptr;
}

Enemy::~Enemy()
{
    pPlayer1 = nullptr;
    pPlayer2 = nullptr;
}
void Enemy::chooseTarget()
{
    sf::Vector2f enemyPos = getPosition();

    if(pPlayer1 || pPlayer2)
    {
        if(!pPlayer2)
        {
            attackTarget = pPlayer1;
            sf::Vector2f p1Pos = pPlayer1->getPosition();
            targetDistance = std::sqrt(((p1Pos - enemyPos).x * (p1Pos - enemyPos).x) + ((p1Pos- enemyPos).y*(p1Pos- enemyPos).y));

        }
        else if(!pPlayer1)
        {
            sf::Vector2f p2Pos = pPlayer2->getPosition();
            attackTarget = pPlayer2;
            targetDistance =  std::sqrt((p2Pos - enemyPos).x*(p2Pos - enemyPos).x) + ((p2Pos - enemyPos).y*(p2Pos - enemyPos).y);
        }
        else
        {
            sf::Vector2f p1Pos = pPlayer1->getPosition();
            sf::Vector2f p2Pos = pPlayer2->getPosition();

            float distanceToP1 = ((p1Pos - enemyPos).x * (p1Pos - enemyPos).x) + ((p1Pos- enemyPos).y*(p1Pos- enemyPos).y);
            float distanceToP2 = ((p2Pos - enemyPos).x*(p2Pos - enemyPos).x) + ((p2Pos - enemyPos).y*(p2Pos - enemyPos).y);
            attackTarget = (distanceToP1 >= distanceToP2) ? pPlayer2 : pPlayer1;
            targetDistance = (distanceToP1 >= distanceToP2) ?  std::sqrt(distanceToP2) :  std::sqrt(distanceToP1);
        }
        isLookingToTheRight = (attackTarget->getPosition().x > getPosition().x);
    }
    else
        attackTarget = nullptr;
}
int Enemy::getScoreValue() const
{
    return scoreValue;
}

void Enemy::setScoreValue(int value)
{
    if (scoreValue > 0)
        scoreValue = value;
}

float Enemy::getTargetDistance() const
{
    return targetDistance;
}
Player *Enemy::getTarget()
{
    return attackTarget;
}
int Enemy::getDamage() const
{
    return damage;
}
