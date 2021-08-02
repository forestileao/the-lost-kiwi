#ifndef STAGE_H
#define STAGE_H

#include "EntityList.h"
#include "../Entities/Entity.h"
#include "../Managers/GraphicManager.h"
#include "../Managers/EventManager.h"
#include "../Entities/Player.h"
#include "../Entities/Projectile.h"

namespace Stages
{
	class Stage
	{
    protected:
		enum Stages
		{
			Hall,
			Castle
		};

		Managers::uniqueId backgroundSprite;
		Managers::GraphicManager *pGraphicManager;
		EntityList entities;
		Entities::Player* p1;
		Entities::Player* p2;

		int currentLevel;
		int players;
		int totalPlayers;
		bool changeStage;
		int stageScore;

		void initializeElements();
		void applyGravity(float dt);
		void updateViewLocation();

	public:
		Stage(Managers::GraphicManager *pGraphicManager);
		~Stage();

		// Adds and removes the Entity Body from the Physic Machine
		//void addBody(sf::RectangleShape *pEntityBody);
		//void removeBody(Managers::uniqueId id);

		// Adds and removes entities from entity List
		void addEntity(Entities::Entity *pEntity);
		void removeEntity(Entities::Entity* pEntity);
		
		//Stages::PhysicMachine *getPhysics();

		Managers::GraphicManager *getGraphicManager();

		void update(float dt, Managers::EventManager *pEvents);
		// Draws all entities
		void draw();
	};

}
#endif //STAGE_H
