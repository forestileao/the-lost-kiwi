//
// Created by forestileao on 15/07/2021.
//

#ifndef CHARACTER_H
#define CHARACTER_H


#include "Entity.h"
namespace Entities
{
	class Character: public Entity
	{
	protected:
		int lifePoints;
	public:
		Character(int life);
		virtual ~Character();
		virtual void execute() = 0;

		bool isAlive();
		void setLife(int life);
		void addLifePoints(int points);
	};
}

#endif //CHARACTER_H
