//
// Created by forestileao on 05/07/2021.
//

#include "../../include/Entities/Player.h"
using namespace Entities;

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
	if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::D : sf::Keyboard::Right))
		body.move(sf::Vector2f(0.1f, 0.f));
	if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::W : sf::Keyboard::Up))
		body.move(sf::Vector2f(0.f, -0.1f));
	if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::A : sf::Keyboard::Left))
		body.move(sf::Vector2f(-0.1f, 0.f));
	if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::S : sf::Keyboard::Down))
		body.move(sf::Vector2f(0.f, 0.1f));
}