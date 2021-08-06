//
// Created by forestileao on 8/3/21.
//

#include "../../include/Entities/Fire.h"
using namespace Entities;
Fire::Fire(Managers::GraphicManager *pGraphicsManager, Stages::Stage *pStage)
    : Obstacle(pGraphicsManager, pStage)
{
    obstacleId = 3;
    updateRect();
    setDamage(3);
}

Fire::~Fire()
{

}
