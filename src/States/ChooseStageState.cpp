#include <States/GameStateMachine.h>
#include "States/ChooseStageState.h"
ChooseStageState::ChooseStageState(States::StateMachine *pStateMachine, Managers::GraphicManager *pGraphicsManager):
States::State(pStateMachine),
pGraphicManager(pGraphicsManager),
selected(0),
timer(0)
{
    sf::View* view = pGraphicManager->getView();
    view->setCenter((pGraphicManager->getView()->getSize().x)*0.5, pGraphicManager->getView()->getSize().y);
    graveyardText = pGraphicManager->createText(0, "Graveyard", 20);
    castleText = pGraphicManager->createText(0, "Castle", 20);
    pGraphicsManager->setTextPosition(graveyardText,view->getCenter().x-20,view->getCenter().y/2-30);
    pGraphicsManager->setTextPosition(castleText,view->getCenter().x-20,view->getCenter().y/2+50);
}
ChooseStageState::~ChooseStageState()
{

}


void ChooseStageState::update(float dt, Managers::EventManager *eventManager)
{
    sf::View *view = pGraphicManager->getView();
    pGraphicManager->setTextPosition(graveyardText, view->getCenter().x-20,view->getCenter().y/2-30);
    pGraphicManager->setTextPosition(castleText, view->getCenter().x-20,view->getCenter().y/2+50);

    if (!(timer > 0.1))
        timer += dt;

    if (eventManager->isKeyPressed(sf::Keyboard::W))
        selected = selected == 0 ? 1 : 0;
    else if (eventManager->isKeyPressed(sf::Keyboard::S))
        selected = selected == 1 ? 0 : 1;

    if (selected == 0 && timer > 0.1)
    {
        pGraphicManager->setTextColor(graveyardText, 0xffff00ff);
        pGraphicManager->setTextColor(castleText, 0xffffffff);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            int stageNum = 1;
            ((GameStateMachine *)getStateMachine())->changeState("ChoosePlayer", static_cast<void *>(&stageNum));
        }
    }
    else if ( selected == 1 && timer > 0.1)
    {
        pGraphicManager->setTextColor(graveyardText, 0xffffffff);
        pGraphicManager->setTextColor(castleText, 0xffff00ff);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            int stageNum = 2;
            ((GameStateMachine *)getStateMachine())->changeState("ChoosePlayer", static_cast<void *>(&stageNum));
        }
    }
}
void ChooseStageState::draw(Managers::GraphicManager *graphicsManager)
{
    pGraphicManager->drawText(graveyardText);
    pGraphicManager->drawText(castleText);
}
void ChooseStageState::init(void *arg)
{
    timer = 0;
}
void ChooseStageState::exit()
{
    State::exit();
}
