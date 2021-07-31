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

		EntityList();
		~EntityList();
	};
}



#endif //ENTITYLIST_H
