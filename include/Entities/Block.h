//
// Created by forestileao on 8/3/21.
//

#ifndef BLOCK_H
#define BLOCK_H

#include "Obstacle.h"
namespace Entities
{
    class Block : public Obstacle
    {

    public:
        Block(bool isFirstStage = true,Managers::GraphicManager* pGraphicsManager = nullptr, Stages::Stage* pStage = nullptr);
        ~Block();
    };
}


#endif //BLOCK_H
