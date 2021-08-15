//
// Created by forestileao on 08/08/2021.
//

#include <Entities/Archer.h>
#include "Stages/Graveyard.h"
#include "States/PlayState.h"
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
    p1 = new Entities::Player(50, this, true, pGraphicManager);
    p1->setPosition(100, 200);

    if (players == 2)
    {
        p2 = new Entities::Player(50, this, false, pGraphicManager);
        p2->setPosition(150, 200);
    }

    loadMap(GRAVEYARD_FILE);
    addEntity(p1);
    if (p2)
        addEntity(p2);
}
void Graveyard::finishStage()
{
    if (p1)
    {
        if (p1->intersects(sf::Rect<float>(80 * 40, 0, 20 * 40, 12 * 40)))
            pState->changeStage(2, players);
    }
    if (p2)
    {
        if (p2->intersects(sf::Rect<float>(80 * 40, 12 * 40, 20 * 40, 12 * 40)))
            pState->changeStage(2 , players);
    }
}
