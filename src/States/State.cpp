//
// Created by forestileao on 18/07/2021.
//

#include "../../include/States/State.h"
using namespace States;

State::State(StateMachine* pStateMachine)
{
	setStateMachine(pStateMachine);
}

State::~State() { }

void State::setStateMachine(StateMachine* pStateMachine){
	this->pStateMachine = pStateMachine;
}

StateMachine* State::getStateMachine(){
	return pStateMachine;
}