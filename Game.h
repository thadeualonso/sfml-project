#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.h"

class Game
{
private:
	sf::RenderWindow* window_;
	sf::Event ev_;
	sf::VideoMode videoMode_;

	// Mouse positions
	sf::Vector2i mousePosWindow_;

	// Game Objects
	std::vector<Enemy> enemies_;

	void initVariables();
	void initWindow();
	void initEnemies();
public:
	Game();
	virtual ~Game();

	const bool isRunning();

	void start();
	void pollEvents();
	void update();
	void updateMousePositions();
	void render();
};