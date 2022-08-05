#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"

class Player
{
public:
    Player(sf::RenderWindow* window);
    ~Player();
    void Update(float deltaTime);
    void Draw();
    void move(Animation* animation, float x, float y, float deltaTime);

private:
    sf::RenderWindow* window;
    sf::RectangleShape shape;
    sf::Texture texture;
    Animation idleAnimation;
    Animation walkAnimation;
};