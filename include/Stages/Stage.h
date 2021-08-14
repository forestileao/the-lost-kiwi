#ifndef STAGE_H
#define STAGE_H

#include "EntityList.h"
#include "../Entities/Entity.h"
#include "../Managers/GraphicManager.h"
#include "../Managers/EventManager.h"
#include "../Entities/Player.h"
#include "../Entities/Projectile.h"
#include "PhysicsMachine.h"
#include "Spawner.h"

class PlayState;
namespace Stages
{
	class Stage : public Ente
	{
    protected:
		Managers::uniqueId backgroundSprite;
		Managers::GraphicManager *pGraphicManager;
		EntityList playerList;
		EntityList enemyList;
		EntityList projectileList;
		EntityList obstacleList;
		Entities::Player* p1;
		Entities::Player* p2;
		PlayState* pState;
		PhysicsMachine physics;

		Spawner spawner;

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
		EntityList* getPlayerList();
		EntityList* getEnemyList();
		EntityList* getProjectileList();
		EntityList* getObstacleList();
		Spawner* getEnemySpawner();

		PlayState* getPlayState() const;
		Managers::GraphicManager *getGraphicManager();

		Entities::Player* getPlayer1();
		Entities::Player* getPlayer2();

		void loadGame(char* fileName);

		virtual void finishStage() = 0;

		void update(float dt, Managers::EventManager *pEvents);
		// Draws all entities
		void draw();
	};

}
#endif //STAGE_H
