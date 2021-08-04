//
// Created by forestileao on 8/3/21.
//

#ifndef FIRE_H
#define FIRE_H

#include "Obstacle.h"
namespace Entities
{
    class Fire : public Obstacle
    {
    public:
        Fire(Managers::GraphicManager* pGraphicsManager = nullptr, Stages::Stage* pStage = nullptr);
        ~Fire();
    };

}

#endif //FIRE_H
