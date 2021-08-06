//
// Created by forestileao on 8/3/21.
//

#include "../../include/Entities/Block.h"
using namespace Entities;

Block::Block(bool isFirstStage,Managers::GraphicManager *pGraphicsManager, Stages::Stage *pStage)
    : Obstacle(pGraphicsManager, pStage)
{
    obstacleId = isFirstStage ? 0 : 1;
    updateRect();
}

Block::~Block()
{

}
