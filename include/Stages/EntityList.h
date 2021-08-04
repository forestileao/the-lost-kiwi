#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "../List/List.h"
#include "../Entities/Entity.h"

namespace Stages
{
	class EntityList
	{
	public:
		List<Entities::Entity> mainList;
		List<Entities::Entity> enemyList;
		List<Entities::Entity> blockList;
		List<Entities::Entity> projectileList;

		EntityList();
		~EntityList();
	};
}



#endif //ENTITYLIST_H
