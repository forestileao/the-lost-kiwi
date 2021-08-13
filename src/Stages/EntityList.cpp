#include "../../include/Stages/EntityList.h"
using namespace Stages;

EntityList::EntityList():
	mainList()
{

}

EntityList::~EntityList()
{

}
List<Entities::Entity> *EntityList::getList()
{
    return &mainList;
}

