//
// Created by forestileao on 8/1/21.
//

#include "../../include/Entities/Obstacle.h"
using namespace Entities;
Obstacle::Obstacle(Managers::GraphicManager* pGraphicsManager, Stages::Stage* pStage):
    Entity(pGraphicsManager, pStage),
    damage(0),
    obstacleId(0)
{
    body.setSize(sf::Vector2f(40, 40));
    frame = sf::Rect<int>(OBSTACLE_RECT);
    textureId = pGraphicManager->loadTexture(OBSTACLE_TEXTURE);
    spriteId = pGraphicManager->createSprite(textureId);
    pGraphicManager->setSpriteRect(spriteId, frame);
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

int Obstacle::getObstacleId() const
{
    return obstacleId;
}

void Obstacle::execute(float dt, Managers::EventManager *pEventManager)
{

}
void Obstacle::updateRect()
{
    frame.left += obstacleId*frame.width;
}
