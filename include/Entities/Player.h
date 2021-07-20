//
// Created by forestileao on 05/07/2021.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Character.h"

namespace Entities
{
	class Player: public Character
	{
	private:
		bool isFirstPlayer;
	public:
		Player(int life, bool firstPlayer = true);
		~Player();

		void execute();
	};
}

#endif //PLAYER_H
