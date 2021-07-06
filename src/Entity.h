#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
private:
	sf::RectangleShape body;
	int x;
	int y;

public:
	Entity();
	~Entity();
};


#endif //ENTITY_H
