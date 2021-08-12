//
// Created by forestileao on 18/07/2021.
//

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "../Stages/Stage.h"

#define GRAVEYARD_BACKGROUND "../assets/graveyard.png"
#define CASTLE_BACKGROUND "../assets/castle.jpg"

typedef struct
{
    bool isResuming;
    bool isLoading;
    int players;
} GameData;

class PlayState : public States::State
{
private:
	Managers::GraphicManager* pGraphicManager;
	Stages::Stage* pStage;
	Managers::uniqueId scoreText;
	Managers::uniqueId playerOneLifeText;
	Managers::uniqueId playerTwoLifeText;
	Managers::uniqueId graveyardBackground;
	Managers::uniqueId castleBackground;
	Managers::uniqueId currentBackground;
	int score;

	GameData gameData;

public:
	PlayState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicsManager = nullptr);
	~PlayState();

	void update(float dt, Managers::EventManager* eventManager);
	void draw(Managers::GraphicManager* graphicsManager);

	void incrementScore(int num);
	int getScore();

	void changeStage(int stageNum, int playersNum);

	void init(void* arg);
	void exit();
};
#endif //PLAYSTATE_H
