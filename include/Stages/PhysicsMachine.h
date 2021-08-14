//
// Created by carolsfer on 05/08/2021.
//

#ifndef PHYSICSMACHINE_H
#define PHYSICSMACHINE_H
#include "EntityList.h"
namespace Stages
{
    class Stage;
    class PhysicsMachine{
    private:
        Stage * pt_stage;
        EntityList* playerList;
        EntityList* enemyList;
        EntityList* obstacleList;
        EntityList* projectileList;

    public:
        PhysicsMachine(Stages::Stage* pStage);
        ~PhysicsMachine();
        void applyCollisions();
        void applyGravity(float dt);

    };
}
#endif //PHYSICSMACHINE_H
