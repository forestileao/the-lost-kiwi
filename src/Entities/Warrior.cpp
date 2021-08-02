//
// Created by forestileao on 8/1/21.
//

#include "../../include/Entities/Warrior.h"
using namespace Entities;
Warrior::Warrior(int life,
                 int value,
                 Player *p1,
                 Player *p2,
                 Managers::GraphicManager *pGraphicManager,
                 Stages::Stage *pStage)
    : Enemy(life, value, p1, p2, pGraphicManager, pStage)
{
    frame = Managers::spriteRect(WARRIOR_RIGHT_RECT);

    vel.x = 50;
    vel.y = 0;

    textureId = pGraphicManager->loadTexture(WARRIOR_TEXTURE);
    spriteId = pGraphicManager->createSprite(textureId);
    pGraphicManager->setSpriteRect(spriteId, frame);
}
Warrior::~Warrior()
{

}
void Warrior::execute(float dt, Managers::EventManager *pEventManager)
{
    chooseTarget();

    if (isLookingToTheRight)
    {
        frame = Managers::spriteRect(WARRIOR_RIGHT_RECT);
    }
    else
    {
        frame = Managers::spriteRect(WARRIOR_LEFT_RECT);
    }

    if (getTargetDistance() <= 200)
    {
        if (isLookingToTheRight)
            move(vel.x*dt, vel.y*dt);
        else
            move(-vel.x*dt,vel.y*dt);
    }

    if(pGraphicManager)
        pGraphicManager->setSpriteRect(spriteId, frame);
}
