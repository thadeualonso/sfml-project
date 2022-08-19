#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"

class Game
{
private:
	sf::RenderWindow mWindow;
	World mWorld;
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