//
// Created by forestileao on 28/07/2021.
//

#include "../../include/Stages/Stage.h"
#include "../../include/Entities/Projectile.h"

Entities::Projectile::Projectile(sf::Vector2f origin, Stages::Stage *pStage, Managers::GraphicManager *pGraphicManager, bool positiveMovement):
	Entity(pGraphicManager, pStage),
	vel(200, 0),
	positiveMovement(positiveMovement)
{
	setWindow(pGraphicManager->getWindowPointer());
	setPosition(origin.x, origin.y);
	textureId = pGraphicManager->loadTexture(PROJECTILE_TEXTURE_FILE);
	spriteId = pGraphicManager->createSprite(textureId);

	if (positiveMovement)
		frame = sf::Rect<int>(KNIFE_FRAME_RIGHT);
	else
		frame = sf::Rect<int>(KNIFE_FRAME_LEFT);

	pGraphicManager->setSpriteRect(spriteId, frame);

	if (!positiveMovement)
		vel.x *= -1;
}

Entities::Projectile::~Projectile()
{

}

void Entities::Projectile::execute(float dt, Managers::EventManager *pEventManager)
{
    sf::View* view = pGraphicManager->getView();
    if (body.getPosition().x > view->getCenter().x + view->getSize().x/2 || body.getPosition().x < view->getCenter().x - view->getSize().x/2)
		pStage->removeEntity(this);

	body.move(vel.x*dt,vel.y*dt);
}
