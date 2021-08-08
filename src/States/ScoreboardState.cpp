//
// Created by forestileao on 8/4/21.
//

#include <fstream>
#include "../../include/States/ScoreboardState.h"
#include "../../include/States/GameStateMachine.h"

ScoreboardState::ScoreboardState(States::StateMachine *pStateMachine, Managers::GraphicManager *pGraphicsManager):
    States::State(pStateMachine),scores()
{
    this->pGraphicManager = pGraphicsManager;
    titleText = pGraphicsManager->createText(0, "ScoreBoard\n Top 10", 20);
    pGraphicsManager->setTextPosition(titleText, 255, 20);
    pGraphicsManager->setTextColor(titleText, 0xffff00ff);
    loadScores();
}

void ScoreboardState::loadScores()
{
    std::ifstream input;
    string line;
    input.open(SCOREBOARD_FILE);
    int scr = 0;
    int lineCounter = 0;
    std::string showText;
    while(input.good())
    {
        getline(input,line);
        if (line.length() > 0)
        {
            showText = line;
            std::replace(showText.begin(), showText.end(), ';', ' ');
            scr = pGraphicManager->createText(0, showText, 20);
            pGraphicManager->setTextColor(scr, 0xffffffff);
            scores.insert(std::make_pair(std::stoi(line.substr(line.find(';') + 1, line.size())), scr));
            lineCounter++;
        }
    }
    input.close();
}

ScoreboardState::~ScoreboardState()
{

}

void ScoreboardState::update(float dt, Managers::EventManager *eventManager)
{
    pGraphicManager->setTextPosition(titleText, pGraphicManager->getView()->getCenter().x-20, 20);

    if (eventManager->isKeyPressed(sf::Keyboard::Space))
        ((GameStateMachine*)getStateMachine())->changeState("MainMenu", nullptr);
}

void ScoreboardState::draw(Managers::GraphicManager *graphicsManager)
{
    pGraphicManager->drawText(titleText);
    int i = 0;
    for (std::multimap<int,int>::iterator it = scores.begin(); it != scores.end() && i < 10; it++)
    {
        pGraphicManager->setTextPosition(it->second, pGraphicManager->getView()->getCenter().x-20, 80 + i*40);
        pGraphicManager->drawText(it->second);
        i++;
    }

}

void ScoreboardState::init(void *arg)
{
    printf("Current State: Scoreboard\n");
}

void ScoreboardState::exit()
{
    printf("Exiting Scoreboard\n");
}
