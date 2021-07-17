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

add_executable(the_lost_kiwi include/List.h src/main.cpp src/Game.cpp include/Game.h src/Entity.cpp include/Entity.h src/Player.cpp include/Player.h src/Enemy.cpp include/Enemy.h include/Element.h src/EntityList.cpp include/EntityList.h src/Stage.cpp include/Stage.h src/Character.cpp include/Character.h)
target_link_libraries (the_lost_kiwi sfml-graphics sfml-window sfml-system)