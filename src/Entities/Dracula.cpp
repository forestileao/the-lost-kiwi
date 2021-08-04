//
// Created by forestileao on 8/2/21.
//

#include "../../include/Entities/Dracula.h"
#include "../../include/Stages/Stage.h"
using namespace Entities;


Dracula::Dracula(int life,
                   int value,
                   Player *p1,
                   Player *p2,
                   Managers::GraphicManager *pGraphicManager,
                   Stages::Stage *pStage):
   Enemy(life, value, p1, p2, pGraphicManager, pStage),
   attackTimer(0),
   isAttacking(false)
{
    body.setSize(sf::Vector2f(40,79));
    frame = Managers::spriteRect(DRACULA_REST_RECT_RIGHT);

    textureId = pGraphicManager->loadTexture(DRACULA_TEXTURE);
    spriteId = pGraphicManager->createSprite(textureId);
    pGraphicManager->setSpriteRect(spriteId, frame);
}

Dracula::~Dracula()
{

}
void Dracula::execute(float dt, Managers::EventManager *pEventManager)
{
    pGraphicManager->getWindowPointer()->draw(body);
    chooseTarget();

    if (isLookingToTheRight)
    {
        frame = Managers::spriteRect(DRACULA_ATTACK_RECT_RIGHT);
    }
    else
    {
        frame = Managers::spriteRect (DRACULA_ATTACK_RECT_LEFT);
    }

    if (getTargetDistance() <= 400)
    {
        if (attackTimer >= 3)
        {
            pStage->addEntity(new Projectile(
                sf::Vector2f(getPosition().x,
                             getPosition().y + 10),
                             FIRE_TEXTURE,
                             sf::Rect<int>(FIRE_RECT),
                             pStage,
                             pGraphicManager,
                             isLookingToTheRight
                             ));
            pStage->addEntity(new Projectile(
                sf::Vector2f(getPosition().x,
                             getPosition().y + 40),
                             FIRE_TEXTURE,
                             sf::Rect<int>(FIRE_RECT),
                             pStage,
                             pGraphicManager,
                             isLookingToTheRight
                             ));
            pStage->addEntity(new Projectile(
                sf::Vector2f(getPosition().x,
                             getPosition().y + 70),
                             FIRE_TEXTURE,
                             sf::Rect<int>(FIRE_RECT),
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
