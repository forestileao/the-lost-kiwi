//
// Created by forestileao on 15/07/2021.
//

#include "../../include/Entities/Character.h"
using namespace Entities;

Character::Character(int life) :
	Entity(),
	lifePoints(life)
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
