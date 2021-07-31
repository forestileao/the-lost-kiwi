//
// Created by forestileao on 15/07/2021.
//

#include "../../include/Entities/Character.h"
using namespace Entities;

Character::Character(int life, Managers::GraphicManager* pGraphicsManager,Stages::Stage* pStage) :
	Entity(pGraphicsManager, pStage),
	lifePoints(life),
	vulnerability(false)
{

}

Character::~Character() noexcept
{
	window = nullptr;
}

// returns if character is alive
bool Character::isAlive()
{
	return lifePoints > 0;
}

void Character::setLife(int life)
{
	lifePoints = life;
}

void Character::addLifePoints(int points)
{
	lifePoints += points;
}
void Character::decrementLifePoints(int points)
{
	lifePoints -= points;
}
void Character::move(float x, float y)
{
	body.move(x, y);
}
void Character::setGrounded(bool ground)
{
	isGrounded = ground;
}

bool Character::getGrounded() const
{
	return isGrounded;
}

sf::Vector2<float> Character::getVel() const
{
	return vel;
}
void Character::setVel(const float x, const float y)
{
	vel.x = x;
	vel.y = y;
}
