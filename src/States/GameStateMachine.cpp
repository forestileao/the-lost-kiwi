//
// Created by forestileao on 18/07/2021.
//

#include "../../include/States/GameStateMachine.h"
#include "../../include/States/PlayState.h"

GameStateMachine::GameStateMachine(Managers::GraphicsManager *graphicManager)
{
	States::State* state = static_cast<States::State*>(new PlayState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "PlayState");
	changeState("PlayState", NULL);
}

GameStateMachine::~GameStateMachine() { }