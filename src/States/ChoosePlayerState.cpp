//
// Created by forestileao on 8/5/21.
//

#include <States/PlayState.h>
#include "../../include/States/ChoosePlayerState.h"
#include "../../include/States/GameStateMachine.h"

ChoosePlayerState::ChoosePlayerState(States::StateMachine *pStateMachine, Managers::GraphicManager *pGraphicsManager):
    States::State(pStateMachine),
    pGraphicManager(pGraphicsManager),
    selected(0),
    timer(0),
    stageNum(0)
{
    sf::View* view = pGraphicManager->getView();
    view->setCenter((pGraphicManager->getView()->getSize().x)*0.5, pGraphicManager->getView()->getSize().y);
    onePlayerText = pGraphicManager->createText(0, "1 Player", 20);
    twoPlayerText = pGraphicManager->createText(0, "2 Players", 20);
    pGraphicsManager->setTextPosition(onePlayerText,view->getCenter().x-20,view->getCenter().y/2-30);
    pGraphicsManager->setTextPosition(twoPlayerText,view->getCenter().x-20,view->getCenter().y/2+50);
}
ChoosePlayerState::~ChoosePlayerState()
{

}


void ChoosePlayerState::update(float dt, Managers::EventManager *eventManager)
{
    sf::View *view = pGraphicManager->getView();
    pGraphicManager->setTextPosition(onePlayerText, view->getCenter().x-20,view->getCenter().y/2-30);
    pGraphicManager->setTextPosition(twoPlayerText, view->getCenter().x-20,view->getCenter().y/2+50);

    if (!(timer > 0.1))
        timer += dt;

    if (eventManager->isKeyPressed(sf::Keyboard::W))
        selected = selected == 0 ? 1 : 0;
    else if (eventManager->isKeyPressed(sf::Keyboard::S))
        selected = selected == 1 ? 0 : 1;

    if (selected == 0 && timer > 0.1)
    {
        pGraphicManager->setTextColor(onePlayerText, 0xffff00ff);
        pGraphicManager->setTextColor(twoPlayerText, 0xffffffff);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            GameData gameData;
            gameData.players = 1;
            gameData.isResuming = false;
            gameData.isLoading = false;
            gameData.stageNum = stageNum;
            ((GameStateMachine *)getStateMachine())->changeState("PlayState", static_cast<void *>(&gameData));
        }
    }
    else if ( selected == 1 && timer > 0.1)
    {
        pGraphicManager->setTextColor(onePlayerText, 0xffffffff);
        pGraphicManager->setTextColor(twoPlayerText, 0xffff00ff);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            GameData gameData;
            gameData.players = 2;
            gameData.isResuming = false;
            gameData.isLoading = false;
            gameData.stageNum = stageNum;
            ((GameStateMachine *)getStateMachine())->changeState("PlayState", static_cast<void *>(&gameData));
        }
    }
}
void ChoosePlayerState::draw(Managers::GraphicManager *graphicsManager)
{
    pGraphicManager->drawText(onePlayerText);
    pGraphicManager->drawText(twoPlayerText);
}
void ChoosePlayerState::init(void *arg)
{
    timer = 0;
    stageNum = *((int*)arg);
}
void ChoosePlayerState::exit()
{
    State::exit();
}
