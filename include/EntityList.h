#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "List/List.h"
#include "Entities/Entity.h"

class EntityList
{
public:
	List<Entity> mainList;

	EntityList();
	~EntityList();
};


#endif //ENTITYLIST_H
