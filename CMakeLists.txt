cmake_minimum_required(VERSION 3.19)
project(the_lost_kiwi)

set(CMAKE_CXX_STANDARD 14)

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()
include_directories(include)
add_executable(the_lost_kiwi include/List/List.h src/main.cpp src/Game.cpp include/Game.h src/Entities/Entity.cpp include/Entities/Entity.h src/Entities/Player.cpp include/Entities/Player.h src/Entities/Enemy.cpp include/Entities/Enemy.h include/List/Element.h src/Stages/EntityList.cpp include/Stages/EntityList.h src/Stages/Stage.cpp include/Stages/Stage.h src/Entities/Character.cpp include/Entities/Character.h src/States/State.cpp include/States/State.h src/States/StateMachine.cpp src/Managers/EventManager.cpp include/Managers/EventManager.h src/Managers/GraphicManager.cpp include/Managers/GraphicManager.h src/States/GameStateMachine.cpp include/States/GameStateMachine.h src/States/PlayState.cpp include/States/PlayState.h include/States/StateMachine.h src/States/MainMenuState.cpp include/States/MainMenuState.h src/Entities/Projectile.cpp include/Entities/Projectile.h src/Entities/Archer.cpp include/Entities/Archer.h src/Entities/Obstacle.cpp include/Entities/Obstacle.h src/Entities/Warrior.cpp include/Entities/Warrior.h src/Entities/Dracula.cpp include/Entities/Dracula.h src/Entities/Block.cpp include/Entities/Block.h src/Entities/Spike.cpp include/Entities/Spike.h src/Entities/Fire.cpp include/Entities/Fire.h include/Stages/PhysicsMachine.h src/Stages/PhysicsMachine.cpp src/States/ScoreboardState.cpp include/States/ScoreboardState.h src/States/ChoosePlayerState.cpp include/States/ChoosePlayerState.h src/Stages/Graveyard.cpp include/Stages/Graveyard.h src/Stages/Castle.cpp include/Stages/Castle.h src/States/GameOverState.cpp include/States/GameOverState.h src/Stages/EnemySpawner.cpp include/Stages/EnemySpawner.h src/States/PauseState.cpp include/States/PauseState.h src/Ente.cpp include/Ente.h)
target_link_libraries (the_lost_kiwi sfml-graphics sfml-window sfml-system)