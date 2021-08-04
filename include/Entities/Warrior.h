//
// Created by forestileao on 8/1/21.
//

#ifndef WARRIOR_H
#define WARRIOR_H

#define WARRIOR_TEXTURE "../assets/warrior.png"
#define WARRIOR_RIGHT_RECT 0, 0, 27, 41
#define WARRIOR_LEFT_RECT 27, 0, -27, 41

#include "Enemy.h"
namespace Entities
{
    class Warrior: public Enemy
    {
    private:

    public:
        Warrior(
            int life = 0,
            int value = 0,
            Player* p1 = nullptr,
            Player* p2 = nullptr,
            Managers::GraphicManager* pGraphicManager = nullptr,
            Stages::Stage* pStage = nullptr);
        ~Warrior();

        void execute(float dt, Managers::EventManager* pEventManager);
    };
}

#endif //WARRIOR_H
