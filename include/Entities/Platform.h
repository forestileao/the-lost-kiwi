//
// Created by forestileao on 8/3/21.
//

#ifndef PLATFORM_H
#define PLATFORM_H

#include "Obstacle.h"
namespace Entities
{
    class Platform : public Obstacle
    {

    public:
        Platform(bool isFirstStage = true,Managers::GraphicManager* pGraphicsManager = nullptr, Stages::Stage* pStage = nullptr);
        ~Platform();
    };
}


#endif //PLATFORM_H
