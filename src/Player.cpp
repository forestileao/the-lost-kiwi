//
// Created by forestileao on 05/07/2021.
//

#include "Player.h"

Player::Player()
{
	window = NULL;
}

Player::~Player()
{
	window = NULL;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		body.move(sf::Vector2f(2.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		body.move(sf::Vector2f(0.f, -2.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		body.move(sf::Vector2f(-2.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		body.move(sf::Vector2f(0.f, 2.f));
}