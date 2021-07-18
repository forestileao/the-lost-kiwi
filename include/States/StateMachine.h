//
// Created by forestileao on 18/07/2021.
//

#ifndef STATEMACHINE_H
#define STATEMACHINE_H


#include "State.h"
namespace States
{
class StateMachine
{

protected:
	std::vector<State*> states;
	string currentState;

public:
	StateMachine();
	virtual ~StateMachine();

	void addState(State* state);
	void changeState(string nextStateID, void* arg);

	void update(float dt, Managers::Events* pEventsManager);
	void render(Managers::Graphics* pGraphicsManager);

	const string getCurrentState() const;

	void setCurrentState(const string state);
};
}
#endif //STATEMACHINE_H
