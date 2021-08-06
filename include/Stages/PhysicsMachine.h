//
// Created by carolsfer on 05/08/2021.
//

#ifndef PHYSICSMACHINE_H
#define PHYSICSMACHINE_H
namespace Stages{
    class Stage;
    class PhysicsMachine{
    private:
        Stage * pt_stage;

    public:
        PhysicsMachine();
        ~PhysicsMachine();
        void applyCollisions(EntityList &entities);
        void applyGravity(float dt, EntityList &entities);

    };
}
#endif //PHYSICSMACHINE_H