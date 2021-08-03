//
// Created by forestileao on 8/1/21.
//

#include "../../include/Entities/Obstacle.h"
using namespace Entities;
Obstacle::Obstacle(Managers::GraphicManager* pGraphicsManager, Stages::Stage* pStage):
    Entity(pGraphicsManager, pStage),
    damage(0)
{
    frame = sf::Rect<int>(OBSTACLE_RECT);
}
Obstacle::~Obstacle()
{

}
int Obstacle::getDamage() const
{
    return damage;
}
void Obstacle::setDamage(int dam)
{
    if (dam > 0)
        damage = dam;
}
void Obstacle::execute(float dt, Managers::EventManager *pEventManager)
{

}
