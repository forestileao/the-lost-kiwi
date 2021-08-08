//
// Created by forestileao on 08/08/2021.
//

#include <fstream>
#include "States/GameOverState.h"
GameOverState::GameOverState(States::StateMachine *pStateMachine, Managers::GraphicManager *pGraphicsManager):
States::State(pStateMachine),
score(0),
playerName("")
{
    this->pGraphicManager = pGraphicsManager;

    titleText = pGraphicManager->createText(0, "GAME OVER", 20);
    pGraphicManager->setTextPosition(titleText, 70, 20);

    scoreText = pGraphicManager->createText(0, "Score: ", 15);
    pGraphicManager->setTextPosition(scoreText, 70, 50);

    nameText = pGraphicManager->createText(0, "Digite seu nome: ", 15);
    pGraphicManager->setTextPosition(nameText, 70, 70);

    exitText = pGraphicManager->createText(0, "Pressione ENTER para inserir", 15);
    pGraphicManager->setTextPosition(exitText, 70, 110);
}

GameOverState::~GameOverState()
{

}

void GameOverState::update(float dt, Managers::EventManager *eventManager)
{
    pGraphicManager->getView()->setCenter((pGraphicManager->getWindowPointer()->getSize().x)/2, pGraphicManager->getView()->getSize().y/2);
    pGraphicManager->getWindowPointer()->setView(*pGraphicManager->getView());
    if(eventManager->isKeyPressed(Managers::EventManager::keyCode::Enter) && playerName.length() > 0)
    {
        addToScoreBoard();
        pStateMachine->changeState("Scoreboard", nullptr);
    }
    else if(eventManager->isKeyPressed(Managers::EventManager::keyCode::BackSpace))
    {
        if(playerName.length()>0)
            playerName.pop_back();
    }
    else
        playerName += eventManager->getStringInput();

}

void GameOverState::draw(Managers::GraphicManager *graphicsManager)
{
    pGraphicManager->setString(scoreText, "Score: " + std::to_string(score));
    pGraphicManager->setString(nameText, "Insert your name: " + playerName);

    pGraphicManager->drawText(titleText);
    pGraphicManager->drawText(scoreText);
    pGraphicManager->drawText(nameText);
    pGraphicManager->drawText(exitText);
}

void GameOverState::init(void *arg)
{
    score = (*(int*)arg);
    background = pGraphicManager->createSprite(pGraphicManager->loadTexture(GAME_OVER_BACKGROUND));
    pGraphicManager->setBackground(background);
}

void GameOverState::exit()
{

}
void GameOverState::addToScoreBoard()
{
    std::ofstream log(SCOREBOARD_FILE, std::ios_base::app | std::ios_base::out);
    log << playerName << ';' << score << '\n';
}
