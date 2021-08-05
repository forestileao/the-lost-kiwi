//
// Created by forestileao on 8/4/21.
//

#ifndef SCOREBOARDSTATE_H
#define SCOREBOARDSTATE_H
#include <vector>
#define SCOREBOARD_FILE "../saves/scoreboard.txt"

#include "State.h"
class ScoreboardState : public States::State
{
private:
    Managers::GraphicManager* pGraphicManager;
    Managers::uniqueId titleText;
    std::multimap<Managers::uniqueId,int, std::greater<int>> scores;
public:
    ScoreboardState(States::StateMachine* pStateMachine = nullptr, Managers::GraphicManager* pGraphicsManager = nullptr);
    ~ScoreboardState();
    void update(float dt, Managers::EventManager* eventManager);
    void draw(Managers::GraphicManager* graphicsManager);
    void loadScores();

    void init(void* arg);
    void exit();
};


#endif //SCOREBOARDSTATE_H
