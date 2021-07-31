//
// Created by forestileao on 18/07/2021.
//

#ifndef STATE_H
#define STATE_H

#include "../Managers/EventManager.h"
#include "../Managers/GraphicManager.h"

#include <vector>
#include <iostream>
using std::string;

namespace States
{
	class StateMachine;
	class State
	{
	protected:
		// Pointer to the State Machine that it belongs
		StateMachine* pStateMachine;

	public:
		State(StateMachine *pStateMachine = nullptr);
		virtual ~State();

		virtual void init(void *arg)
		{}
		virtual void exit()
		{}

		virtual void update(float dt, Managers::EventManager *pEventsManager) = 0;
		virtual void draw(Managers::GraphicManager *pGraphicsManager) = 0;

		void setStateMachine(StateMachine *pStateMachine);
		StateMachine *getStateMachine();
	};
}
#endif //STATE_H
