#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SFML/Graphics.hpp"
#include "Aircraft.h"
#include <iostream>

class Game
{
private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::Text mFpsText;
	TextureHolder mTextureHolder;
	FontHolder mFontHolder;
	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingRight = false;
	bool mIsMovingLeft = false;

public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};