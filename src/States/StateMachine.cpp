//
// Created by forestileao on 18/07/2021.
//

#include "../../include/States/StateMachine.h"
using namespace States;

StateMachine::StateMachine()
{
	currentState = "";
}

StateMachine::~StateMachine()
{
	for(int i = 0; i < states.size(); i++)
		delete states[i];
}

void StateMachine::addState(State* state, string stateName)
{
	states[stateName] = state;
}

void StateMachine::changeState(std::string nextStateID, void* arg){
	// If it has a current state processing
	if(currentState != "")
		states[currentState]->exit();

	// else it sets the state
	currentState = nextStateID;
	states[currentState]->enter(arg);

}

void StateMachine::update(float dt, Managers::EventManager* pEventsManager)
{
	states[currentState]->update(dt, pEventsManager);
}

void StateMachine::render(Managers::GraphicManager* pGraphicsManager)
{
	states[currentState]->render(pGraphicsManager);
}

const string StateMachine::getCurrentState() const
{
	return currentState;
}

void StateMachine::setCurrentState(const string state){
	currentState = state;
}