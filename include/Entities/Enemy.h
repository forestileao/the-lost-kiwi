//
// Created by forestileao on 05/07/2021.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Player.h"

namespace Entities
{
	class Enemy: public Character
	{
    protected:
	    int scoreValue;
	    Player* pPlayer1;
	    Player* pPlayer2;
	    Player* attackTarget;

	    float targetDistance;

	    Stages::Stage* pStage;

	public:
		Enemy(
		        int life = 0,
		        int value = 0,
		        Player* p1 = nullptr,
		        Player* p2 = nullptr,
		        Managers::GraphicManager* pGraphicManager = nullptr,
		        Stages::Stage* pStage = nullptr);
		~Enemy();

		void chooseTarget();
		Player* getTarget();
		float getTargetDistance() const;

        int getScoreValue() const;
        void setScoreValue(int value);

        virtual void execute(float dt, Managers::EventManager* pEventManager) = 0;
	};
}

#endif //ENEMY_H
