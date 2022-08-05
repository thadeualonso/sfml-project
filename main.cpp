#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::RectangleShape player(sf::Vector2f(64.0f, 64.0f));
    sf::Texture playerTexture;

    playerTexture.loadFromFile("textures/characters.png");
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 23;
    textureSize.y /= 4;

    player.setTexture(&playerTexture);
    player.setTextureRect(sf::IntRect(0, 32, textureSize.x, textureSize.y));
    player.setOrigin(sf::Vector2f(player.getSize().x / 2.0f, player.getSize().y / 2.0f));
    player.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));

    Animation idleAnim(&playerTexture, sf::Vector2u(23, 4), 0.1f, 0, 0);
    Animation walkAnim(&playerTexture, sf::Vector2u(23, 4), 0.1f, 1, 4);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;    

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        idleAnim.Update(1, deltaTime);

        window.clear(sf::Color::Green);
        window.draw(player);
        window.display();
    }

    return 0;
}