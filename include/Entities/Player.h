//
// Created by forestileao on 05/07/2021.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Character.h"
#include "../States/StateMachine.h"

namespace Entities
{
	class Player: public Character
	{
	private:
		sf::Clock cronometer;

		bool isFirstPlayer;
		bool isColliding;
		bool isTakingDamage;
		bool isAttacking;
		bool isWalking;
		bool isJumping;
		bool isIdle;
	public:
		Player(int life, bool firstPlayer = true);
		~Player();

		void execute(float dt);
	};
}

#endif //PLAYER_H
