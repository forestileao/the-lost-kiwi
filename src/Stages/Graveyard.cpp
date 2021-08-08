//
// Created by forestileao on 08/08/2021.
//

#include <Entities/Archer.h>
#include <Entities/Warrior.h>
#include <Entities/Dracula.h>
#include "Stages/Graveyard.h"
using namespace Stages;

Graveyard::Graveyard(Managers::GraphicManager *pGraphicManager, PlayState *pState, int playersNum)
: Stage(pGraphicManager, pState, playersNum)
{
    initializeElements();
}
Graveyard::~Graveyard()
{

}

void Graveyard::initializeElements()
{
    p1 = new Entities::Player(10, this, true, pGraphicManager);
    p1->setPosition(100, 200);

    if (players == 2)
    {
        p2 = new Entities::Player(10, this, false, pGraphicManager);
        p2->setPosition(150, 200);
    }

    loadMap(GRAVEYARD_FILE);
    addEntity(p1);
    if (p2)
    addEntity(p2);
}
