//
// Created by forestileao on 8/3/21.
//

#ifndef SPIKE_H
#define SPIKE_H

#include "Obstacle.h"

namespace Entities
{
    class Spike : public Obstacle
    {
    public:
        Spike(Managers::GraphicManager* pGraphicsManager = nullptr, Stages::Stage* pStage = nullptr);
        ~Spike();
    };
}



#endif //SPIKE_H
