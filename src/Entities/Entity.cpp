//
// Created by forestileao on 05/07/2021.
//

#include "../../include/Entities/Entity.h"
using namespace Entities;

Entity::Entity():
	body(sf::Vector2f(20.f, 20.f))
{
	window = nullptr;

	body.setFillColor(sf::Color().Red);
	body.setPosition(0, 0);
}

Entity::~Entity()
{
	window = nullptr;
}