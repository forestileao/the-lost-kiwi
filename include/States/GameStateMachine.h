//
// Created by forestileao on 18/07/2021.
//

#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "StateMachine.h"
#include "../Managers/GraphicsManager.h"

class GameStateMachine : public States::StateMachine
{
public:
	GameStateMachine(Managers::GraphicsManager* graphicManager = nullptr);
	~GameStateMachine();
};


#endif //GAMESTATEMACHINE_H
