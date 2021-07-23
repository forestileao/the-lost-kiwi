#ifndef STAGE_H
#define STAGE_H

#include "../Entities/Player.h"
#include "../Entities/Enemy.h"
#include "EntityList.h"
#include "../Managers/GraphicManager.h"
#include "../Managers/EventManager.h"

namespace Stages
{
	class Stage
	{
	private:
		enum Stages
		{
			Hall,
			Castle
		};

		Managers::GraphicManager *pGraphicsManager;
		EntityList entities;
		//Stages::PhysicMachine physics;

		Entities::Player* p1;

		void initializeElements();

	public:
		Stage(Managers::GraphicManager *pGraphicManager);
		~Stage();

		// Adds and removes the Entity Body from the Physic Machine
		//void addBody(sf::RectangleShape *pEntityBody);
		//void removeBody(Managers::uniqueId id);

		// Adds and removes entities from entity List
		void addEntity(Entities::Entity *pEntity);
		void removeEntity(Managers::uniqueId id);
		
		//Stages::PhysicMachine *getPhysics();

		Managers::GraphicManager *getGraphicManager();

		void update(float dt, Managers::EventManager *pEvents);
		// Draws all entities
		void draw();
	};

}
#endif //STAGE_H
