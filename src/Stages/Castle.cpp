//
// Created by forestileao on 08/08/2021.
//

#include <Entities/Archer.h>
#include <Entities/Dracula.h>
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

    boss = new Entities::Dracula(50, 100,p1,p2, pGraphicManager, this);
    boss->setPosition(90*40, pGraphicManager->getView()->getSize().y - 150);
    addEntity(boss);
}

void Castle::finishStage()
{
    if (!boss->isAlive())
    {
        int score = pState->getScore();
        pState->getStateMachine()->changeState("GameOver", static_cast<void *>(&score));
    }
}
