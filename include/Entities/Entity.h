namespace Stages
{
	class Stage;
}

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "../Managers/EventManager.h"
#include "../Managers/GraphicManager.h"

namespace Entities
{
	class Entity
	{
	protected:
        sf::RenderWindow *window;
		Stages::Stage* pStage;

		bool vulnerability;

		Managers::GraphicManager* pGraphicManager;

		int id;
		Managers::uniqueId textureId;
		Managers::uniqueId spriteId;
		Managers::spriteRect frame;

        sf::RectangleShape body;
    public:
		static int entityCount;
		static void decrementEntityCount();

		Entity(Managers::GraphicManager* pGraphicsManager = nullptr,Stages::Stage* pStage = nullptr);
		virtual ~Entity();

		void setWindow(sf::RenderWindow *window)
		{ this->window = window; }
		void setPosition(float x, float y)
		{ body.setPosition(x, y);}
		sf::Vector2f getPosition();

		void draw();

		// Pure virtual function to execute entity action (if it exists)
		virtual void execute(float dt, Managers::EventManager* pEventManager) = 0;
	};
}
static int entityCount = 0;
#endif //ENTITY_H
