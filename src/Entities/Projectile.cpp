//
// Created by forestileao on 28/07/2021.
//

#include "../../include/Entities/Projectile.h"

Entities::Projectile::Projectile(sf::Vector2f origin, Stages::Stage *pStage, Managers::GraphicManager *pGraphicManager, bool positiveMovement):
	Entity(pGraphicManager, pStage),
	vel(0, 0),
	positiveMovement(positiveMovement)
{
	setPosition(origin.x, origin.y);
}

Entities::Projectile::~Projectile()
{

}

void Entities::Projectile::execute(float dt, Managers::EventManager *pEventManager)
{
	vel
}
