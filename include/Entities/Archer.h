//
// Created by forestileao on 8/1/21.
//

#ifndef ARCHER_H
#define ARCHER_H


#define ARROW_TEXTURE "../assets/arrow.png"
#define ARROW_RECT 0, 0, 30, 4

#define ARCHER_TEXTURE "../assets/archer.png"
#define ARCHER_RECT_RIGHT 0, 0, 58, 35
#define ARCHER_RECT_LEFT 58, 0, -58, 35

#include "Enemy.h"

namespace Entities
{
    class Archer: public Enemy
    {
    private:
        float attackTimer;
        bool isAttacking;

    public:
        Archer(
            int life = 0,
            int value = 0,
            Player* p1 = nullptr,
            Player* p2 = nullptr,
            Managers::GraphicManager* pGraphicManager = nullptr,
            Stages::Stage* pStage = nullptr);
        ~Archer();

        void execute(float dt, Managers::EventManager* pEventManager);
    };
}

#endif //ARCHER_H
