//
// Created by forestileao on 05/07/2021.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
private:

public:
	Player();
	~Player();

	void move();
};


#endif //PLAYER_H
