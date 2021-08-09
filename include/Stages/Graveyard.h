//
// Created by forestileao on 08/08/2021.
//

#ifndef THE_LOST_KIWI_GRAVEYARD_H
#define THE_LOST_KIWI_GRAVEYARD_H

#include "Stage.h"

#define GRAVEYARD_FILE "../assets/cemiterio.txt"

namespace Stages
{
    class Graveyard: public Stage
    {
    private:
        void initializeElements() override;

    public:
        Graveyard(Managers::GraphicManager *pGraphicManager, PlayState* pState, int playersNum);
        ~Graveyard();

        void finishStage() override;
    };
}


#endif //THE_LOST_KIWI_GRAVEYARD_H
