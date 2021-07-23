//
// Created by forestileao on 05/07/2021.
//

#include "../../include/Entities/Enemy.h"
using namespace Entities;

Enemy::Enemy(int life):
	Character(life)
{
	window = NULL;

	body.setFillColor(sf::Color::Blue);
	body.setPosition(sf::Vector2f(200.f, 200.f));
}

Enemy::~Enemy()
{
	window = NULL;
}
void Enemy::execute(float dt)
{
	// TODO: Implement actions here
}
