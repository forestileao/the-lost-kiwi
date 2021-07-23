#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

namespace Entities
{
	class Entity
	{
	protected:
		sf::RectangleShape body;
		sf::RenderWindow *window;

	public:
		Entity();
		virtual ~Entity();

		void setWindow(sf::RenderWindow *window)
		{ this->window = window; }
		void draw()
		{ window->draw(body); }

		// Pure virtual function to execute entity action (if it exists)
		virtual void execute(float dt) = 0;
	};
}

#endif //ENTITY_H
