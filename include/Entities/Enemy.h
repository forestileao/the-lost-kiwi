//
// Created by forestileao on 05/07/2021.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
class Enemy : public Character
{
private:


public:
	Enemy(int life);
	~Enemy();

	void execute();
};


#endif //ENEMY_H
