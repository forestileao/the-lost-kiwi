//
// Created by forestileao on 09/08/2021.
//

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <Managers/GraphicManager.h>
#include <Managers/EventManager.h>
#include "StateMachine.h"

#define PAUSE_BACKGROUND_FILE "../assets/pause.png"
namespace Stages
{
    class Stage;
}

class PauseState : public States::State
{
private:
    int selected;
    float timer;

    Stages::Stage* pStage;

    Managers::GraphicManager* pGraphicManager;
    Managers::uniqueId resumeText;
    Managers::uniqueId quitGameText;
    Managers::uniqueId saveText;
    Managers::uniqueId background;

    void saveGame();
public:
    PauseState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicsManager = nullptr);
    ~PauseState();
    void update(float dt, Managers::EventManager* eventManager);
    void draw(Managers::GraphicManager* graphicManager);

    void init(void* arg);
    void exit();
};


#endif //PAUSESTATE_H
