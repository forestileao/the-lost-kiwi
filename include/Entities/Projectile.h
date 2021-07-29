//
// Created by forestileao on 28/07/2021.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#define PROJECTILE_TEXTURE_FILE "../assets/knife.png"
#define KNIFE_FRAME_RIGHT 0, 0, 13, 4
#define KNIFE_FRAME_LEFT 13, 0, -13, 4

#include "Entity.h"

namespace Entities
{
	class Projectile: public Entity
	{
	private:
		const float acceleration = 15;
		const float maxVel = 100;

		// Movements
		bool positiveMovement;
		sf::Vector2f vel;

	public:
		Projectile(sf::Vector2f origin, Stages::Stage* pStage, Managers::GraphicManager* pGraphicManager, bool positiveMovement = true);
		~Projectile();

		void execute(float dt, Managers::EventManager *pEventManager);
	};
}

#endif //PROJECTILE_H
