#pragma once
#include "ResourceHolder.hpp"
#include "SFML/Graphics.hpp"

namespace Textures
{
enum ID
{
	Airplane,
	Landscape,
	Missile
};
}

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
	ResourceHolder<sf::Texture, Textures::ID> mTextureHolder;
	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingRight = false;
	bool mIsMovingLeft = false;
};