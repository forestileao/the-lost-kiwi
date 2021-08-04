//
// Created by forestileao on 05/07/2021.
//

#include "../../include/Entities/Entity.h"
using namespace Entities;

Entity::Entity(Managers::GraphicManager* pGraphicsManager, Stages::Stage* pStage):
	body(),
	pGraphicManager(pGraphicsManager),
	vulnerability(false),
	id(::entityCount++)
{
	this->pStage = pStage;
	spriteId = -1;
	textureId = -1;
	window = nullptr;
}

Entity::~Entity()
{
	window = nullptr;
	pStage = nullptr;

	if(spriteId >= 0)
		pGraphicManager->removeSprite(spriteId);
}
void Entity::draw()
{
	pGraphicManager->setSpriteRect(spriteId, frame);
	pGraphicManager->setSpritePosition(spriteId, body.getPosition().x, body.getPosition().y);
	pGraphicManager->drawSprite(spriteId);
}

sf::Vector2f Entity::getPosition()
{
    return body.getPosition();

}

sf::Vector2f Entity::getSize()
{
    return body.getSize();
}

void Entity::decrementEntityCount()
{
	::entityCount--;
}
sf::Rect<float> Entity::getGlobalBounds() const
{
    return body.getGlobalBounds();
}

bool Entity::intersects(sf::Rect<float> rect) const
{
    return body.getGlobalBounds().intersects(rect);
}
