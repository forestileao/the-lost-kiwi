#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::RectangleShape body;
	sf::RenderWindow* window;

public:
	Entity();
	~Entity();

	void setWindow(sf::RenderWindow* window) { this->window = window; }
	void draw() { window->draw(body); }
};


#endif //ENTITY_H
