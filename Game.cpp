#include "Game.h"

Game::Game()
{
	initVariables();
	initWindow();
    initEnemies();
}

Game::~Game()
{
	delete this->window_;
}

const bool Game::isRunning()
{
	return window_->isOpen();
}


void Game::initVariables()
{
	window_ = nullptr;
	videoMode_.height = 600;
	videoMode_.width = 800;
}

void Game::initWindow()
{
	window_ = new sf::RenderWindow(videoMode_, "SFML Game", sf::Style::Titlebar | sf::Style::Close);
    window_->setFramerateLimit(60);
}

void Game::initEnemies()
{
    int totalEnemies = 10;
    enemies_.reserve(totalEnemies);
    for (int i = 0; i < totalEnemies; i++)
    {
        enemies_.push_back(Enemy(i, sf::Vector2f(50.f, 50.f)));
        enemies_[i].setPosition(sf::Vector2f(
            static_cast<float> (rand() % static_cast<int> (window_->getSize().x - enemies_[i].getSize().x)),
            static_cast<float> (rand() % static_cast<int> (window_->getSize().y - enemies_[i].getSize().y))
        ));
    }
}

void Game::start()
{
}

void Game::pollEvents()
{
    while (window_->pollEvent(ev_))
    {
        switch (ev_.type)
        {
            case sf::Event::Closed:
                window_->close();
                break;

            case sf::Event::KeyPressed:
                if (ev_.key.code == sf::Keyboard::Escape)
                    window_->close();
                break;
        }
    }
}

void Game::update()
{
    pollEvents();
    updateMousePositions();

    for (auto &enemy : enemies_)
        enemy.update();
}

void Game::updateMousePositions()
{
    mousePosWindow_ = sf::Mouse::getPosition(*window_);
    std::cout << "Mouse pos: " << mousePosWindow_.x << " " << mousePosWindow_.y << std::endl;
}

void Game::render()
{
    window_->clear();

    for (auto enemy : enemies_)
    {
        enemy.render(window_);
    }

    window_->display();
}