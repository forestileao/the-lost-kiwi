//
// Created by forestileao on 18/07/2021.
//

#include "../../include/States/GameStateMachine.h"
#include "../../include/States/PlayState.h"
#include "../../include/States/MainMenuState.h"

GameStateMachine::GameStateMachine(Managers::GraphicManager *graphicManager)
{
	States::State* state = static_cast<States::State*>(new PlayState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "PlayState");
	state = static_cast<States::State*>(new MainMenuState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "MainMenu");
	changeState("MainMenu", NULL);
}

GameStateMachine::~GameStateMachine() { }