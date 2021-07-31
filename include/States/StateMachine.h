//
// Created by forestileao on 18/07/2021.
//

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <iostream>
#include <map>
#include "State.h"

namespace States
{
	class StateMachine
	{

	protected:
		std::map<std::string, State*> states;
		std::string currentState;

	public:
		StateMachine();
		virtual ~StateMachine();

		void addState(State* state, std::string stateName);
		void changeState(std::string nextStateName, void* arg);

		void update(float dt, Managers::EventManager* pEventsManager);
		void draw(Managers::GraphicManager* pGraphicsManager);

		const std::string getCurrentState() const;

		void setCurrentState(std::string state);
	};
}

#endif //STATEMACHINE_H
