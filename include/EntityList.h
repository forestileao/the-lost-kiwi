#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "List.h"
#include "Entity.h"

class EntityList
{
public:
	List<Entity> mainList;

	EntityList();
	~EntityList();
};


#endif //ENTITYLIST_H
