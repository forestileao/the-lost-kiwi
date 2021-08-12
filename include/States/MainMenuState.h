//
// Created by forestileao on 23/07/2021.
//

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"

#define MENU_BACKGROUND_FILE "../assets/moon.png"

class MainMenuState : public States::State
{
private:
	Managers::uniqueId background;
	Managers::GraphicManager* pGraphicManager;
	Managers::uniqueId gameNameText;
	Managers::uniqueId startGameText;
	Managers::uniqueId loadGameText;
	Managers::uniqueId quitGameText;
	Managers::uniqueId scoreboardText;

	float timer;
	int selected;

public:
	MainMenuState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicManager = nullptr);
	~MainMenuState();

	void update(float dt, Managers::EventManager* eventManager);
	void draw(Managers::GraphicManager* graphicManager);

	void init(void* arg);
	void exit();
};


#endif //MAINMENUSTATE_H
