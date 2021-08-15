//
// Created by forestileao on 8/3/21.
//

#include "../../include/Entities/Platform.h"
using namespace Entities;

Platform::Platform(bool isFirstStage,Managers::GraphicManager *pGraphicsManager, Stages::Stage *pStage)
    : Obstacle(pGraphicsManager, pStage)
{
    obstacleId = isFirstStage ? 0 : 1;
    updateRect();
}

Platform::~Platform()
{

}
