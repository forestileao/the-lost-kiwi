//
// Created by forestileao on 08/08/2021.
//

#include <Entities/Archer.h>
#include <Entities/Warrior.h>
#include <Entities/Dracula.h>
#include "Stages/Castle.h"
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
    p1 = new Entities::Player(10, this, true, pGraphicManager);
    p1->setPosition(100, 200);

    if (players == 2)
    {
        p2 = new Entities::Player(10, this, false, pGraphicManager);
        p2->setPosition(150, 200);
    }

    /*
    Entities::Archer* archer = new Entities::Archer(10,10,p1, p2,pGraphicManager,this);
    Entities::Archer* archer2 = new Entities::Archer(10,10,p1, p2,pGraphicManager,this);
    Entities::Warrior* warrior = new Entities::Warrior(10,10,p1, p2,pGraphicManager,this);
    Entities::Dracula* dracula = new Entities::Dracula(10,10,p1, p2,pGraphicManager,this);
    archer->setPosition(200, 350);
    archer2->setPosition(300, 350);
    warrior->setPosition(400, 350);
    dracula->setPosition(500, 300);
*/
    loadMap(CASTLE_FILE);
    addEntity(p1);
    if (p2)
        addEntity(p2);

    /*
    addEntity(archer);
    addEntity(archer2);
    addEntity(warrior);
    addEntity(dracula);
     */
}
