//
// Created by forestileao on 05/07/2021.
//

#include "../include/Entity.h"

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