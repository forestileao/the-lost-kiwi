//
// Created by forestileao on 18/07/2021.
//

#ifndef STATE_H
#define STATE_H

#include <vector>
#include <iostream>
using std::string;

class StateMachine;
namespace States
{
	class State
	{
		State(StateMachine *pStateMachine = nullptr);
		virtual ~State();

		virtual void enter(void *arg)
		{}
		virtual void exit()
		{}

		virtual void update(float dt, Managers::EventManager *pEventsManager) = 0;
		virtual void render(Managers::GraphicManager *pGraphicsManager) = 0;

		void setStateMachine(StateMachine *pStateMachine);
		StateMachine *getStateMachine();
	};
}
#endif //STATE_H
