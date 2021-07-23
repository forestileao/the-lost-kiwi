//
// Created by forestileao on 18/07/2021.
//

#include "../../include/Managers/EventManager.h"
using namespace Managers;

EventManager::EventManager()
{
	closeEvent = false;
	initKeysDown();
}

EventManager::EventManager(sf::RenderWindow* window)
{
	setWindow(window);
	closeEvent = false;
	initKeysDown();
}

void EventManager::initKeysDown()
{
	for(int i = 0; i < sf::Keyboard::KeyCount; i++)
		keysDown[i] = false;
}

void EventManager::resetLoopKeys()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		keysReleased[i] = false;
		keysPressed[i] = false;
	}
}

EventManager::~EventManager()
{
}

void EventManager::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void EventManager::pollAll()
{
	sf::Event events;

	// reinitilize all keys from the loop for new interactions
	resetLoopKeys();

	while (window->pollEvent(events))
	{
		// Check if the user Closed the window
		if (events.type == sf::Event::Closed)
		{
			closeEvent = true;
		}
		// Checks if the user Released any key
		else if(events.type == sf::Event::KeyReleased)
		{
			keysReleased[events.key.code] = true;
			keysDown[events.key.code] = false;
		}
			// Checks if the user pressed any key
		else if(events.type == sf::Event::KeyPressed)
		{
			keysPressed[events.key.code] = true;
			keysDown[events.key.code] = true;
		}
	}
}

const bool EventManager::isKeyDown(const keyCode key)const
{
	return keysDown[key];
}

const bool EventManager::isKeyPressed(const keyCode key)const
{
	return keysPressed[key];
}

const bool EventManager::isKeyReleased(const keyCode key)const
{
	return keysReleased[key];
}

const std::string EventManager::getStringInput()
{

	std::string input = "";
	for(char i = 0; i < 26; i++)
		if(keysPressed[i])
			input += ('A' + (char)i);

	return input;
}

const bool EventManager::isWindowClosing() const
{
	return closeEvent;
}