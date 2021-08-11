//
// Created by forestileao on 18/07/2021.
//

#include <States/GameOverState.h>
#include <States/PauseState.h>
#include "../../include/States/GameStateMachine.h"
#include "../../include/States/PlayState.h"
#include "../../include/States/MainMenuState.h"
#include "../../include/States/ScoreboardState.h"
#include "../../include/States/ChoosePlayerState.h"

GameStateMachine::GameStateMachine(Managers::GraphicManager *graphicManager)
{
	States::State* state = static_cast<States::State*>(new PlayState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "PlayState");
	state = static_cast<States::State*>(new MainMenuState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "MainMenu");
	state = static_cast<States::State*>(new ScoreboardState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "Scoreboard");
	state = static_cast<States::State*>(new ChoosePlayerState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "ChoosePlayer");
	state = static_cast<States::State*>(new PauseState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "PauseState");
	state = static_cast<States::State*>(new GameOverState(static_cast<States::StateMachine*>(this), graphicManager));
	addState(state, "GameOver");
	changeState("MainMenu", NULL);
}

GameStateMachine::~GameStateMachine() { }