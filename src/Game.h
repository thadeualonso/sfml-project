#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::Text mFpsText;
	TextureHolder mTextureHolder;
	ResourceHolder<sf::Font, Fonts::ID> mFontHolder;
	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingRight = false;
	bool mIsMovingLeft = false;
};