//
// Created by forestileao on 8/1/21.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#define OBSTACLE_RECT 0, 0, 40, 40
#define OBSTACLE_TEXTURE "../assets/obstacles.png"

#include "Entity.h"
namespace Entities
{
    class Obstacle : public Entity
    {
    protected:
        int obstableId;
        int damage;

        void updateRect();
    public:
        Obstacle(Managers::GraphicManager* pGraphicsManager = nullptr, Stages::Stage* pStage = nullptr);
        ~Obstacle();

        int getObstacleId() const;
        int getDamage() const;
        void setDamage(int dam);
        void execute(float dt, Managers::EventManager *pEventManager) override;
    };
}

#endif //OBSTACLE_H
