//
// Created by forestileao on 28/07/2021.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

namespace Entities
{
	class Projectile: public Entity
	{
	private:
	    bool friendly;
		// Movements
		bool positiveMovement;
		sf::Vector2f vel;

	public:
	    Projectile(sf::Vector2f origin,char* textureFile, sf::Rect<int> frameRect, Stages::Stage* pStage, Managers::GraphicManager* pGraphicManager, bool positiveMovement = true, bool isFriendly = false);
		~Projectile();

		bool isFriendly() const;
		void execute(float dt, Managers::EventManager *pEventManager);
	};
}

#endif //PROJECTILE_H
