//
// Created by forestileao on 8/3/21.
//

#include "../../include/Entities/Spike.h"
Entities::Spike::Spike(Managers::GraphicManager *pGraphicsManager, Stages::Stage *pStage)
    : Obstacle(pGraphicsManager, pStage)
{
    obstacleId = 2;
    updateRect();
    setDamage(5);
}
Entities::Spike::~Spike()
{

}
