//
// Created by carolsfer on 05/08/2021.
//

#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H
#include "EntityList.h"
namespace Stages
{
    class Stage;
    class PhysicsEngine{
    private:
        Stage * pt_stage;
        EntityList* playerList;
        EntityList* enemyList;
        EntityList* obstacleList;
        EntityList* projectileList;

    public:
        PhysicsEngine(Stages::Stage* pStage);
        ~PhysicsEngine();
        void applyCollisions();
        void applyGravity(float dt);

    };
}
#endif //PHYSICSENGINE_H
