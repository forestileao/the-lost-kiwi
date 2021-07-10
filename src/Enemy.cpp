//
// Created by forestileao on 05/07/2021.
//

#include "../include/Enemy.h"

Enemy::Enemy()
{
	window = NULL;

	body.setFillColor(sf::Color::Blue);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Enemy::~Enemy()
{
	window = NULL;
}