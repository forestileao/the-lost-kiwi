//
// Created by forestileao on 08/08/2021.
//

#include <Entities/Archer.h>
#include "Stages/Castle.h"
#include "States/PlayState.h"
using namespace Stages;

Castle::Castle(Managers::GraphicManager *pGraphicManager, PlayState* pState, int playersNum)
: Stage(pGraphicManager, pState, playersNum)
{
    initializeElements();
}
Castle::~Castle()
{

}
void Castle::initializeElements()
{
    p1 = new Entities::Player(50, this, true, pGraphicManager);
    p1->setPosition(100, 200);

    if (players == 2)
    {
        p2 = new Entities::Player(50, this, false, pGraphicManager);
        p2->setPosition(150, 200);
    }

    loadMap(CASTLE_FILE);
    addEntity(p1);
    if (p2)
        addEntity(p2);

}

void Castle::finishStage()
{
    //int score = pState->getScore();
    //pState->getStateMachine()->changeState("GameOver", &score);
}
