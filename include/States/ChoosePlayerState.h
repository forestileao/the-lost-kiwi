//
// Created by forestileao on 8/5/21.
//

#ifndef CHOOSEPLAYERSTATE_H
#define CHOOSEPLAYERSTATE_H


#include "State.h"
class ChoosePlayerState : public States::State
{
private:
    Managers::GraphicManager* pGraphicManager;
    Managers::uniqueId onePlayerText;
    Managers::uniqueId twoPlayerText;
    int selected;
    int stageNum;
    float timer;

public:
    ChoosePlayerState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicsManager = nullptr);
    ~ChoosePlayerState();
    void update(float dt, Managers::EventManager* eventManager);
    void draw(Managers::GraphicManager* graphicsManager);

    void init(void* arg);
    void exit();

};


#endif //CHOOSEPLAYERSTATE_H
