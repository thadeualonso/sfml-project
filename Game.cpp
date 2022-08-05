#include "Game.h"

void Game::start(sf::RenderWindow& window)
{
    window.setFramerateLimit(30);
}

void Game::update(sf::Event event, int deltaTime)
{

}

void Game::draw(sf::RenderWindow& window, sf::Event event, float deltaTime)
{
    float fps = 1 / deltaTime;
    sf::Text text;
    sf::Font font;

    if(!font.loadFromFile("fonts/PIXEARG_.ttf")){ }

    text.setFont(font);
    text.setString("FPS: " + std::to_string(fps) + "\nDeltaTime: " + std::to_string(deltaTime));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    window.draw(text);
}