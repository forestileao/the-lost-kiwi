//
// Created by forestileao on 05/07/2021.
//

#include "../include/Player.h"

Player::Player(int life, bool firstPlayer):
	Character(life),
	isFirstPlayer(firstPlayer)
{
	window = nullptr;
}

Player::~Player()
{
	window = nullptr;
}

void Player::execute()
{
	if (isFirstPlayer)
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
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			body.move(sf::Vector2f(2.f, 0.f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			body.move(sf::Vector2f(0.f, -2.f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			body.move(sf::Vector2f(-2.f, 0.f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			body.move(sf::Vector2f(0.f, 2.f));
	}
}