//
// Created by forestileao on 18/07/2021.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Managers
{
	class EventManager
	{

	public: typedef sf::Keyboard::Key keyCode;

	private:

		sf::RenderWindow* window; // Pointer to the window where the events are loaded

		bool keysPressed[sf::Keyboard::KeyCount]; // Marks all keys that where pressed
		bool keysReleased[sf::Keyboard::KeyCount]; // Mark all released keys of last verification
		bool keysDown[sf::Keyboard::KeyCount]; // Marks all keys that are still pressed
        bool resizeEvent;
		bool closeEvent; // Marks if the used tried to close the window

		void initKeysDown();
		void resetLoopKeys();

	public:
		EventManager(sf::RenderWindow* window);
		EventManager();

		// Destructor
		~EventManager();

		/* Basic methods */
		void setWindow(sf::RenderWindow* window);
		void pollAll(); // Process all events

		/* Functions to search for keys interaction */
		const bool isKeyPressed(const keyCode key) const; // Searches for a pressed key in list
		const bool isKeyReleased(const keyCode key) const;// Searches for a released keu int list
		const bool isKeyDown(const keyCode key) const; // Searches for a down key in list

		const std::string getStringInput();
		const bool isWindowClosing() const;
		const bool DidWindowResized() const;
	};
}

#endif //EVENTMANAGER_H
