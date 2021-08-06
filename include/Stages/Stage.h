#ifndef STAGE_H
#define STAGE_H

#include "EntityList.h"
#include "../Entities/Entity.h"
#include "../Managers/GraphicManager.h"
#include "../Managers/EventManager.h"
#include "../Entities/Player.h"
#include "../Entities/Projectile.h"
#include "PhysicsMachine.h"

class PlayState;
namespace Stages
{
	class Stage
	{
    protected:
		Managers::uniqueId backgroundSprite;
		Managers::GraphicManager *pGraphicManager;
		EntityList entities;
		Entities::Player* p1;
		Entities::Player* p2;
		PlayState* pState;
		PhysicsMachine physics;

		int players;
		bool changeStage;

		void initializeElements();
		//void applyGravity(float dt);
		void loadMap(char* fileName);
		//void applyCollisions();
		void updateViewLocation();

	public:
		Stage(Managers::GraphicManager *pGraphicManager, PlayState* pState);
		~Stage();

		// Adds and removes entities from entity List
		void addEntity(Entities::Entity *pEntity);
		void removeEntity(Entities::Entity* pEntity);
		EntityList getEntitylist();

		PlayState* getPlayState() const;
		Managers::GraphicManager *getGraphicManager();

		void update(float dt, Managers::EventManager *pEvents);
		// Draws all entities
		void draw();
	};

}
#endif //STAGE_H
