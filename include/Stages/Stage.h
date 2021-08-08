#ifndef STAGE_H
#define STAGE_H

#include "EntityList.h"
#include "../Entities/Entity.h"
#include "../Managers/GraphicManager.h"
#include "../Managers/EventManager.h"
#include "../Entities/Player.h"
#include "../Entities/Projectile.h"
#include "PhysicsMachine.h"
#include "EnemySpawner.h"

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

		EnemySpawner spawner;

		int players;
		bool changeStage;

		virtual void initializeElements() = 0;
		void loadMap(char* fileName);
		void updateViewLocation();

	public:
	    Stage(Managers::GraphicManager *pGraphicManager, PlayState* pState, int playersNum);
		~Stage();

		// Adds and removes entities from entity List
		void addEntity(Entities::Entity *pEntity);
		void removeEntity(Entities::Entity* pEntity);
		EntityList getEntitylist();
		EnemySpawner* getEnemySpawner();

		PlayState* getPlayState() const;
		Managers::GraphicManager *getGraphicManager();

		Entities::Player* getPlayer1();
		Entities::Player* getPlayer2();

		void update(float dt, Managers::EventManager *pEvents);
		// Draws all entities
		void draw();
	};

}
#endif //STAGE_H
