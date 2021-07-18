//
// Created by forestileao on 18/07/2021.
//

#include "../../include/Managers/GraphicsManager.h"
using namespace Managers;

GraphicsManager::GraphicsManager(int screenWidth, int screenHeight, const char* windowTitle):
	screenWidth(screenWidth), screenHeight(screenHeight)
	{
	window.create(sf::VideoMode(screenWidth, screenHeight), windowTitle);
	backgroundSprite = -1;

}
GraphicsManager::~GraphicsManager()
{
	for(int i = 0; i < fonts.size(); i++)
		delete fonts[i];

	for(int i = 0; i < textures.size(); i++)
		delete textures[i];

	for(int i = 0; i < texts.size(); i++)
		delete texts[i];

	for(int i = 0; i < sprites.size(); i++)
		delete sprites[i];
}

sf::RenderWindow* GraphicsManager::getWindowPointer()
{
	return &window;
}

const bool GraphicsManager::isWindowOpen()const{
	return window.isOpen();
}

void GraphicsManager::closeWindow()
{
	window.close();
}

const uniqueId GraphicsManager::loadTexture(const char* file)
{

	auto it = loadedTextures.find(file);

	if(it != loadedTextures.end())//se a textura ja foi carregada
		return it->second;//retorna o id

	else{
		sf::Texture* newTexture = new sf::Texture();

		if(!newTexture->loadFromFile(file))
		{
			printf("error loading file\n");
			return -1;//problema ao carregar o arquivo
		}

		textures.push_back(newTexture);

		loadedTextures[file] = textures.size()-1;//adiciona o id da textura no mapa de texturas carregadas
		return textures.size()-1;//retorna a posicao que guarda a nova textura
	}
}

const uniqueId GraphicsManager::createSprite(uniqueId baseTexture)
{

	if(baseTexture >= textures.size())
	{
		printf("ERROR: texture id out of range\n");
		return -1;
	}
	else{
		sf::Sprite* newSprite = new sf::Sprite(*textures[baseTexture]);

		auto i = sprites.begin();
		uniqueId newSpriteID = 0;
		for(newSpriteID, i; i != sprites.end() && *i != NULL; i++, newSpriteID++);//procura por uma posicao vaga ou pelo fim

		if(i == sprites.end())
		{//nao encontrou posicao vaga insere no fim
			sprites.push_back(newSprite);
		}
		else{
			*i = newSprite;
		}

		return newSpriteID;

	}
}

void GraphicsManager::removeSprite(uniqueId sprite)
{

	if(sprite >= sprites.size())
		printf("ERROR: sprite id out of range\n");
	else{
		auto i = sprites.begin();
		for(sprite; sprite > 0; i++, sprite--)
			delete *i;

		if(sprite == sprites.size()-1)
			sprites.erase(i);
		else
			*i = NULL;
	}
}

void GraphicsManager::setSpriteRect(uniqueId sprite, const spriteRect& rect)
{

	if(sprite >= sprites.size())
		printf("ERROR: sprite id out of range\n");
	else
		sprites[sprite]->setTextureRect(rect);

}

void GraphicsManager::setSpritePosition(uniqueId sprite, float x, float y)
{

	if(sprite >= sprites.size())
		printf("ERROR: sprite id out of range\n");
	else{
		sf::Vector2f pos(x, y);
		sprites[sprite]->setPosition(pos);
	}
}

void GraphicsManager::drawSprite(uniqueId sprite)
{

	if(sprite >= sprites.size())
		printf("ERROR: sprite id out of range\n");
	else
		window.draw(*sprites[sprite]);

}

void GraphicsManager::setBackground(uniqueId sprite)
{
	if(sprite >= sprites.size())
		printf("ERROR: sprite id out of range\n");
	else{
		backgroundSprite = sprite;
		float factorX = (float)screenWidth/sprites[sprite]->getTextureRect().width;
		float factorY = (float)screenHeight/sprites[sprite]->getTextureRect().height;
		sprites[sprite]->setScale(factorX, factorY);
		sprites[sprite]->setPosition(0, 0);
	}
}

const uniqueId GraphicsManager::loadFont(const char* file)
{
	sf::Font* newFont = new sf::Font();

	if (!newFont->loadFromFile(file))
		return -1;

	fonts.push_back(newFont);
	return fonts.size()-1;

}

const uniqueId GraphicsManager::createText(uniqueId baseFont, std::string text, int size)
{
	sf::Text* newText = new sf::Text(text, *fonts[baseFont], size);

	texts.push_back(newText);
	return texts.size()-1;
}

void GraphicsManager::setTextColor(uniqueId text, int red, int green, int blue, int alpha)
{

	texts[text]->setFillColor(sf::Color(red, green, blue, alpha));
}

void GraphicsManager::setString(uniqueId text, std::string newText)
{
	texts[text]->setString(newText);
}

void GraphicsManager::drawText(uniqueId text)
{
	window.draw(*texts[text]);

}

void GraphicsManager::setTextPosition(uniqueId text, float x, float y)
{

	sf::Vector2f pos(x, y);
	texts[text]->setPosition(pos);
}

void GraphicsManager::draw()
{
	if(window.isOpen())
	{
		window.display();
		window.clear();
		if(backgroundSprite >= 0)//se houver um plano de fundo definido
			window.draw(*sprites[backgroundSprite]);
	}
}