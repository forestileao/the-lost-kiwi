//
// Created by forestileao on 09/08/2021.
//

#include <States/GameStateMachine.h>
#include <States/PlayState.h>
#include <fstream>
#include <Entities/Warrior.h>
#include <Stages/Graveyard.h>
#include <Entities/Fire.h>
#include <Entities/Spike.h>
#include <Entities/Block.h>
#include <Entities/Archer.h>
#include "States/PauseState.h"
PauseState::PauseState(States::StateMachine *pStateMachine, Managers::GraphicManager *pGraphicsManager):
States::State(pStateMachine),
pStage(nullptr),
pGraphicManager(pGraphicsManager),
selected(0)
{
    sf::View* view = pGraphicManager->getView();

    resumeText = pGraphicManager->createText(0, "Resume Game", 20);
    saveText = pGraphicManager->createText(0, "Save Game", 20);
    quitGameText = pGraphicManager->createText(0, "Quit Game", 20);

    pGraphicManager->setTextPosition(resumeText, view->getCenter().x - 20, 100);
    pGraphicManager->setTextPosition(saveText, view->getCenter().x - 20, 200);
    pGraphicManager->setTextPosition(quitGameText, view->getCenter().x - 20, 300);
    pGraphicManager->setTextColor(resumeText, 0xff0000ff);
    pGraphicManager->setTextColor(saveText, 0xffff00ff);
    pGraphicManager->setTextColor(quitGameText, 0xffffffff);
}
PauseState::~PauseState()
{

}
void PauseState::update(float dt, Managers::EventManager *eventManager)
{
    sf::View *view = pGraphicManager->getView();
    pGraphicManager->setTextPosition(resumeText, view->getCenter().x - 20, 100);
    pGraphicManager->setTextPosition(saveText, view->getCenter().x - 20, 200);
    pGraphicManager->setTextPosition(quitGameText, view->getCenter().x - 20, 300);


    pGraphicManager->getView()->setCenter((pGraphicManager->getWindowPointer()->getSize().x)/2, pGraphicManager->getView()->getSize().y/2);
    pGraphicManager->getWindowPointer()->setView(*pGraphicManager->getView());
    if (timer > 0.05)
    {
        if (eventManager->isKeyDown(sf::Keyboard::W))
            selected -= selected >= 1 ? 1 : 0;
        else if (eventManager->isKeyDown(sf::Keyboard::S))
            selected += selected < 2 ? 1 : 0;

        timer = 0;
    }
    else
        timer += dt;
    if (selected == 0)
    {
        pGraphicManager->setTextColor(resumeText, 0xffff00ff);
        pGraphicManager->setTextColor(saveText, 0xffffffff);
        pGraphicManager->setTextColor(quitGameText, 0xffffffff);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            GameData data;
            data.isLoading = false;
            data.isResuming = true;
            ((GameStateMachine *)getStateMachine())->changeState("PlayState", static_cast<void *>(&data));
        }
    }
    else if ( selected == 1)
    {
        pGraphicManager->setTextColor(resumeText, 0xffffffff);
        pGraphicManager->setTextColor(saveText, 0xffff00ff);
        pGraphicManager->setTextColor(quitGameText, 0xffffffff);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            saveGame();
            ((GameStateMachine *)getStateMachine())->changeState("MainMenu", nullptr);
        }
    }
    else if (selected == 2)
    {
        pGraphicManager->setTextColor(resumeText, 0xffffffff);
        pGraphicManager->setTextColor(saveText, 0xffffffff);
        pGraphicManager->setTextColor(quitGameText, 0xffff00ff);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            ((GameStateMachine *)getStateMachine())->changeState("MainMenu", nullptr);
        }
    }
}
void PauseState::draw(Managers::GraphicManager *graphicManager)
{
    pGraphicManager->drawText(resumeText);
    pGraphicManager->drawText(saveText);
    pGraphicManager->drawText(quitGameText);
}
void PauseState::init(void *arg)
{
    pStage = ((Stages::Stage*)arg);
    timer = 0;
    selected = 0;
    background = pGraphicManager->createSprite(pGraphicManager->loadTexture(PAUSE_BACKGROUND_FILE));
    printf("Pausing Game\n");
    pGraphicManager->setBackground(background);
}
void PauseState::exit()
{

}
void PauseState::saveGame()
{
    std::string filePath = "../saves/stage.txt";
    std::ofstream newFile(filePath, std::ios_base::trunc | std::ios_base::out);

    newFile << pStage->getPlayState()->getScore() << '\n';

    List<Entities::Entity> enemyList = *(pStage->getEnemyList()->getList());
    List<Entities::Entity> mainList = *(pStage->getPlayerList()->getList());
    List<Entities::Entity> obstacleList = *(pStage->getObstacleList()->getList());

    // saving players
    if (dynamic_cast<Stages::Graveyard*>(pStage) == NULL)
        newFile << 2 << '\n';
    else newFile << 1 << '\n';

    newFile << mainList.getLen() << '\n';
    for (int i = 0; i < mainList.getLen(); i ++)
    {
        Entities::Player* pPlayer = (Entities::Player*)(mainList.getItem(i));
        newFile << ((Entities::Character*)pPlayer)->getLife() << ' '
        << pPlayer->getPosition().x << ' ' << pPlayer->getPosition().y << '\n';
    }
    // saving enemies
    newFile << enemyList.getLen() << '\n';
    for (int i = 0; i < enemyList.getLen(); i++)
    {
        int enemyType = 0;
        Entities::Entity* pTemp = enemyList.getItem(i);

        if (dynamic_cast<Entities::Warrior*>(pTemp) != NULL)
        {
            enemyType = 0;
        }
        else if(dynamic_cast<Entities::Archer*>(pTemp) != NULL)
        {
            enemyType = 1;
        }
        else
            continue;

        newFile << enemyType << ' ' << ((Entities::Character*)pTemp)->getLife() << ' '
        << pTemp->getPosition().x << ' ' << pTemp->getPosition().y << '\n';
    }

    int obstacleCounter = 0;
    Entities::Entity* pTempObstacle;
    for (int i = 0; i < obstacleList.getLen(); i++)
    {
        pTempObstacle = obstacleList.getItem(i);
        if (dynamic_cast<Entities::Block*>(pTempObstacle) == nullptr)
        {
            obstacleCounter++;
        }
    }
    // saving obstacles
    newFile << obstacleCounter << '\n';
    for (int i = 0; i < obstacleList.getLen(); i++)
    {
        int obstacleType = 0;
        pTempObstacle = obstacleList.getItem(i);

        if (dynamic_cast<Entities::Fire*>(pTempObstacle) != nullptr)
        {
            obstacleType = 3;
        }
        else if (dynamic_cast<Entities::Spike*>(pTempObstacle) != nullptr)
        {
            obstacleType = 2;
        }
        else
            continue;
        newFile << obstacleType << ' '
        << pTempObstacle->getPosition().x << ' ' << pTempObstacle->getPosition().y << '\n';
    }

    newFile.close();
}
