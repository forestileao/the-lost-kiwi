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
	PlayState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicsManager = nullptr);
	~PlayState();

	void update(float dt, Managers::EventManager* eventManager);
	void draw(Managers::GraphicManager* graphicsManager);

	void incrementScore(int num);

	void init(void* arg);
	void exit();
};
#endif //PLAYSTATE_H
