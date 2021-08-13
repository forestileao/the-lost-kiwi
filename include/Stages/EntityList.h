#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "../List/List.h"
#include "../Entities/Entity.h"

namespace Stages
{
	class EntityList
	{
    protected:
	    List<Entities::Entity> mainList;
	public:
		EntityList();
		~EntityList();
		List<Entities::Entity>* getList();
	};
}



#endif //ENTITYLIST_H
