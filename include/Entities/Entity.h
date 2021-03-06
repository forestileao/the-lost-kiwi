namespace Stages
{
	class Stage;
}

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <Ente.h>
#include "../Managers/EventManager.h"
#include "../Managers/GraphicManager.h"

namespace Entities
{
	class Entity: public Ente
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
		~Entity();

		void setWindow(sf::RenderWindow *window)
		{ this->window = window; }
		void setPosition(float x, float y)
		{ body.setPosition(x, y);}
		sf::Vector2f getPosition();
		sf::Vector2f getSize();
		sf::Rect<float> getGlobalBounds() const;
		bool intersects(sf::Rect<float> rect) const;

		void draw();
		virtual void save(std::ofstream& stream) = 0;
		// Pure virtual function to execute entity action (if it exists)
		virtual void execute(float dt, Managers::EventManager* pEventManager) = 0;
	};
}
static int entityCount = 0;
#endif //ENTITY_H
