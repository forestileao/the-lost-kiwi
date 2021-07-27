#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

namespace Managers
{
	typedef sf::Rect<int> spriteRect;
	typedef int uniqueId;

	class GraphicManager
	{

	private:
		std::map<const char*, uniqueId> loadedTextures;
		sf::RenderWindow window;
		const int screenWidth, screenHeight;

		std::vector<sf::Texture*> textures;
		std::vector<sf::Sprite*> sprites;
		std::vector<sf::Font*> fonts;
		std::vector<sf::Text*> texts;

		uniqueId backgroundSprite;

	public:
		GraphicManager(int screenWidth = 800, int screenHeight = 600, const char* windowTitle = "Some Game");
		~GraphicManager();

		sf::RenderWindow* getWindowPointer();

		const bool isWindowOpen()const;
		void closeWindow();

		const uniqueId loadTexture(const char* file);

		const uniqueId createSprite(uniqueId baseTexture);
		void removeSprite(uniqueId sprite);
		void setSpriteRect(uniqueId sprite, spriteRect& rect);
		void setSpritePosition(uniqueId sprite, float x, float y);
		void drawSprite(uniqueId sprite);

		const uniqueId loadFont(const char* file);
		const uniqueId createText(uniqueId baseFont, std::string text, int size);
		void setTextPosition(uniqueId text, float x, float y);
		void setTextColor(uniqueId text, const unsigned int hexColor=0xffffffff);
		void setString(uniqueId text, std::string newText);
		void drawText(uniqueId text);

		void setBackground(uniqueId sprite);

		void draw();
	};
}