//
// Created by forestileao on 05/07/2021.
//

#include "../../include/Entities/Player.h"
using namespace Entities;

Player::Player(int life, bool firstPlayer):
	Character(life),
	isFirstPlayer(firstPlayer),
	isAttacking(false),
	isColliding(false),
	isTakingDamage(false),
	isWalking(false),
	isIdle(true),
	isJumping(false),
	cronometer()
{
	window = nullptr;
}

Player::~Player()
{
	window = nullptr;
}

void Player::execute(float dt)
{
	if (isJumping)
	{
		body.move(sf::Vector2f(0.f, dt*-200.f));

		if (cronometer.getElapsedTime().asSeconds() > 0.7)
		{
			cronometer.restart();
			isJumping = false;
		}
	}

	if (isIdle)
	{
		if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::D : sf::Keyboard::Right))
		{
			body.move(sf::Vector2f(dt*100.f, 0.f));
			isWalking = true;
			isIdle = false;
		}
		if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::W : sf::Keyboard::Up) && !isJumping)
		{
			// body.move(sf::Vector2f(0.f, -200.f*dt + 9.8*dt*dt/2.f)); // vot² + at²/2
			isJumping = true;
			isWalking = true;
			isIdle = false;
			cronometer.restart();
		}
		if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::A : sf::Keyboard::Left))
		{
			body.move(sf::Vector2f(dt*-100.f, 0.f));
			isWalking = true;
			isIdle = false;
		}
		if (sf::Keyboard::isKeyPressed(isFirstPlayer ? sf::Keyboard::S : sf::Keyboard::Down))
		{
			body.move(sf::Vector2f(0.f, dt*100.f));
			isWalking = true;
			isIdle = false;
		}
	}
	else if (isWalking && !isIdle )
	{
		isWalking = !isWalking;
		isIdle = !isIdle;
	}

	if (body.getPosition().y  + body.getSize().y < window->getSize().y && !isJumping)
	{
		std::cout << body.getPosition().y  << " " << window->getSize().y << "\n";
		body.move(sf::Vector2f(0.f, dt * 600.f));
	}

}