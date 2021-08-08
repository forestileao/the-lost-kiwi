//
// Created by forestileao on 08/08/2021.
//

#ifndef CASTLE_H
#define CASTLE_H

#include "Stage.h"

#define CASTLE_FILE "../assets/castle.txt"

namespace Stages
{
    class Castle: public Stage
    {
    private:
        void initializeElements() override;
    public:
        Castle(Managers::GraphicManager *pGraphicManager, PlayState* pState, int playersNum);
        ~Castle();
    };
}

#endif //CASTLE_H
