//
// Created by forestileao on 28/07/2021.
//

#include <fstream>
#include "../../include/Stages/Stage.h"
#include "../../include/Entities/Projectile.h"

Entities::Projectile::Projectile(sf::Vector2f origin,char* textureFile, sf::Rect<int> frameRect, Stages::Stage *pStage, Managers::GraphicManager *pGraphicManager, bool positiveMovement, bool isFriendly):
	Entity(pGraphicManager, pStage),
	vel(200, 0),
	positiveMovement(positiveMovement),
	friendly(isFriendly)
{
    body.setSize(sf::Vector2f(12,4));
	setWindow(pGraphicManager->getWindowPointer());
	setPosition(origin.x, origin.y);
	textureId = pGraphicManager->loadTexture(textureFile);
	spriteId = pGraphicManager->createSprite(textureId);
	frame = sf::Rect<int>(frameRect);

	// inverts the frame Rect
	if (!positiveMovement)
	{
        frame.left += frame.width;
        frame.width *= -1;
    }

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
bool Entities::Projectile::isFriendly() const
{
    return friendly;
}
void Entities::Projectile::save(std::ofstream &stream)
{
    stream << isFriendly() << ' ' << positiveMovement << ' '
    << body.getPosition().x << ' ' << body.getPosition().y << '\n';
}
