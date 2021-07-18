//
// Created by forestileao on 18/07/2021.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace Managers
{
	class Events
	{

	public: typedef sf::Keyboard::Key keyCode;

	private:

		sf::RenderWindow* window; // Pointer to the window where the events are loaded

		bool keysPressed[sf::Keyboard::KeyCount]; // Marks all keys that where pressed
		bool keysReleased[sf::Keyboard::KeyCount]; // Mark all released keys of last verification
		bool keysDown[sf::Keyboard::KeyCount]; // Marks all keys that are still pressed

		bool closeEvent; // Marks if the used tried to close the window

	public:
		Events(sf::RenderWindow* window);
		Events();

		// Destructor
		~Events();

		/* Basic methods */
		void setWindow(sf::RenderWindow* window);
		void pollAll(); // Process all events

		/* Functions to search for keys interaction */
		const bool keyPressed(const keyCode key) const; // Searches for a pressed key in list
		const bool keyReleased(const keyCode key) const;// Searches for a released keu int list
		const bool keyDown(const keyCode key) const; // Searches for a down key in list

		const std::string getStringInput();
		const bool isWindowCLosed() const;
	};
}

#endif //EVENTMANAGER_H
