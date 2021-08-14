#ifndef CHOOSESTAGESTATE_H
#define CHOOSESTAGESTATE_H


#include "State.h"
class ChooseStageState : public States::State
    {
    private:
        Managers::GraphicManager* pGraphicManager;
        Managers::uniqueId graveyardText;
        Managers::uniqueId castleText;
        int selected;
        float timer;

    public:
        ChooseStageState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicsManager = nullptr);
        ~ChooseStageState();
        void update(float dt, Managers::EventManager* eventManager);
        void draw(Managers::GraphicManager* graphicsManager);

        void init(void* arg);
        void exit();

    };


#endif //CHOOSESTAGESTATE_H
