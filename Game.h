#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
    public:
        void start(sf::RenderWindow& window);
        void update(sf::Event event, int deltaTime);
        void draw(sf::RenderWindow& window, sf::Event event, float deltaTime);

};

#endif