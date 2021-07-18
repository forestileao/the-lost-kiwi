//
// Created by forestileao on 18/07/2021.
//

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "../Stages/Stage.h"

class PlayState : public States::State
{
private:
	Managers::GraphicManager* pGraphicManager;
	Stages::Stage* pStage;
	Managers::uniqueId scoreText;

	int score;

public:
	PlayState(States::StateMachine* pStateMachine = NULL, Managers::GraphicManager* pGraphicsManager = NULL);
	~PlayState();

	virtual void update(float dt, Managers::EventManager* eventManager);
	virtual void draw(Managers::GraphicManager* graphicsManager);

	virtual void enter(void* arg);
	virtual void exit();
};


#endif //PLAYSTATE_H
