#include "Game.h"

Game::Game() :
	mWindow(sf::VideoMode(640, 480), "SFML Application"),
	mPlayer(Aircraft::Eagle, mTextureHolder),
	mFpsText(),
	mTextureHolder(),
	mFontHolder()
{
	mWindow.setFramerateLimit(60);

	try
	{
		mTextureHolder.load(Textures::Airplane, "content/textures/ship_0010.png");
		mFontHolder.load(Fonts::MiniSquare, "content/fonts/k_mini_square.ttf");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return;
	}

	mFpsText.setFont(mFontHolder.get(Fonts::MiniSquare));
	mFpsText.setString("Texto");
	mFpsText.setScale(0.8f, 0.8f);

	sf::Vector2f centerOfScreen(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);
	mPlayer.setPosition(centerOfScreen);
	mPlayer.setScale(2.f, 2.f);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		mFpsText.setString("FPS: " + std::to_string(1.f / timeSinceLastUpdate.asSeconds()) + "\nDeltaTime: " + std::to_string(timeSinceLastUpdate.asSeconds()));

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}

		render();
	}
}

void Game::processEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
			default:
				break;
		}
	}

	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	float velocity = 150.f;

	if (mIsMovingUp)
		movement.y -= velocity;
	if (mIsMovingDown)
		movement.y += velocity;
	if (mIsMovingRight)
		movement.x += velocity;
	if (mIsMovingLeft)
		movement.x -= velocity;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear(sf::Color::Cyan);
	mWindow.draw(mPlayer);
	mWindow.draw(mFpsText);
	mWindow.display();
}