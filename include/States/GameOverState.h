//
// Created by forestileao on 08/08/2021.
//

#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#define GAME_OVER_BACKGROUND "../assets/game-over.jpg"
#define SCOREBOARD_FILE "../saves/scoreboard.txt"

#include <Managers/GraphicManager.h>
#include "StateMachine.h"
class GameOverState: public States::State
    {
    private:
        Managers::GraphicManager* pGraphicManager;
        Managers::uniqueId background;

        Managers::uniqueId titleText;
        Managers::uniqueId scoreText;
        Managers::uniqueId nameText;
        Managers::uniqueId exitText;
        int score;
        std::string playerName;

        void addToScoreBoard();

    public:
        GameOverState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicsManager = nullptr);
        ~GameOverState();

        void update(float dt, Managers::EventManager* eventManager);
        void draw(Managers::GraphicManager* graphicsManager);

        void init(void* arg);
        void exit();
    };


#endif //GAMEOVERSTATE_H
