//
// Created by forestileao on 8/1/21.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#define OBSTALE_RECT 0, 0, 40, 40

#define BASIC_BLOCK_TEXTURE "../assets/block.png"

#include "Entity.h"
namespace Entities
{
    class Obstacle : public Entity
    {
    private:
        bool givesDamage;

    public:
        Obstacle(Managers::GraphicManager* pGraphicsManager = nullptr, Stages::Stage* pStage = nullptr);
        ~Obstacle();


    };
}

#endif //OBSTACLE_H
