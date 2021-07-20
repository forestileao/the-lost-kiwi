//
// Created by forestileao on 18/07/2021.
//

#include "../../include/States/StateMachine.h"
using namespace States;

StateMachine::StateMachine():
	states()
{
	currentState = "";
}

StateMachine::~StateMachine()
{
	for (auto it = states.begin(); it != states.end(); ++it)
		delete it->second;
}

void StateMachine::addState(State* state, string stateName)
{
	states[stateName] = state;
}

void StateMachine::changeState(std::string nextStateName, void* arg){
	// If it has a current state processing
	if(currentState != "")
		states[currentState]->exit();

	// else it sets the state
	currentState = nextStateName;
	states[currentState]->enter(arg);
}

void StateMachine::update(float dt, Managers::EventManager* pEventsManager)
{
	states[currentState]->update(dt, pEventsManager);
}

void StateMachine::draw(Managers::GraphicManager* pGraphicsManager)
{
	states[currentState]->draw(pGraphicsManager);
}

const string StateMachine::getCurrentState() const
{
	return currentState;
}

void StateMachine::setCurrentState(const string state){
	currentState = state;
}