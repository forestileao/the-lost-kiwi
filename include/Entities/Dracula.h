//
// Created by forestileao on 8/2/21.
//

#ifndef DRACULA_H
#define DRACULA_H

#include "Player.h"
#include "Enemy.h"

#define FIRE_TEXTURE "../assets/fire.png"
#define FIRE_RECT 0, 0, 16, 11

#define DRACULA_TEXTURE "../assets/dracula.png"
#define DRACULA_ATTACK_RECT_LEFT 38, 0, 60, 79
#define DRACULA_ATTACK_RECT_RIGHT 98, 0, -60, 79
#define DRACULA_REST_RECT_LEFT 0, 0, 40, 79
#define DRACULA_REST_RECT_RIGHT 40, 0, -40, 79

namespace Entities
{
    class Dracula: public Enemy
    {
    private:
        float attackTimer;
        bool isAttacking;

    public:
        Dracula(
            int life = 0,
            int value = 0,
            Player* p1 = nullptr,
            Player* p2 = nullptr,
            Managers::GraphicManager* pGraphicManager = nullptr,
            Stages::Stage* pStage = nullptr);
        ~Dracula();

        void execute(float dt, Managers::EventManager* pEventManager);
    };
}

#endif //DRACULA_H
