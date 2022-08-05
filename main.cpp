#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Player player(&window);

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

        player.Update(deltaTime);

        window.clear(sf::Color::Green);
        player.Draw();
        window.display();
    }

    return 0;
}