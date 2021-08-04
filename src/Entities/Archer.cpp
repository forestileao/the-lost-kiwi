//
// Created by forestileao on 8/1/21.
//
#include "../../include/Stages/Stage.h"
#include "../../include/Entities/Archer.h"
using namespace Entities;

Archer::Archer(int life,
               int value,
               Player *p1,
               Player *p2,
               Managers::GraphicManager *pGraphicManager,
               Stages::Stage *pStage)
    : Enemy(life, value, p1, p2, pGraphicManager, pStage),
    attackTimer(0),
    isAttacking(false)
{
    body.setSize(sf::Vector2f(35,35));
    frame = Managers::spriteRect(ARCHER_RECT_RIGHT);

    textureId = pGraphicManager->loadTexture(ARCHER_TEXTURE);
    spriteId = pGraphicManager->createSprite(textureId);
    pGraphicManager->setSpriteRect(spriteId, frame);
}
Archer::~Archer()
{

}

void Archer::execute(float dt, Managers::EventManager *pEventManager)
{
    pGraphicManager->getWindowPointer()->draw(body);
    chooseTarget();

    if (isLookingToTheRight)
    {
        frame = Managers::spriteRect(ARCHER_RECT_RIGHT);
    }
    else
    {
        frame = Managers::spriteRect (ARCHER_RECT_LEFT);
    }

    if (getTargetDistance() <= 400)
    {
        if (attackTimer >= 1)
        {
            pStage->addEntity(new Projectile(
                sf::Vector2f(getPosition().x,
                             getPosition().y + 16),
                             ARROW_TEXTURE,
                             sf::Rect<int>(ARROW_RECT),
                pStage,
                pGraphicManager,
                isLookingToTheRight
            ));
            attackTimer = 0;
        }
        else
            attackTimer += dt;
    }

    if(pGraphicManager)
        pGraphicManager->setSpriteRect(spriteId, frame);
}
