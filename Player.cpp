#include "Player.h"

Player::Player(sf::RenderWindow* window) : idleAnimation(&texture, sf::Vector2u(23, 4), 0.1f, 0, 0), walkAnimation (&texture, sf::Vector2u(23, 4), 0.1f, 1, 4)
{
    this->shape = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
    this->texture.loadFromFile("textures/characters.png");
    this->window = window;
    shape.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
    shape.setSize(sf::Vector2f(64, 64));
    shape.setOrigin(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
    shape.setTexture(&texture);
}

Player::~Player()
{
    
}

void Player::Update(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move(&walkAnimation, 1.0f, 0.0f, deltaTime);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        move(&walkAnimation, -1.0f, 0.0f, deltaTime);
    }
    else
    {
        idleAnimation.Update(1, deltaTime);
        shape.setTextureRect(idleAnimation.uvRect);
    }
}
void Player::Draw()
{
    window->draw(shape);
}

void Player::move(Animation* animation, float x, float y, float deltaTime)
{
    if(x < 0.0f)
        shape.setScale(sf::Vector2f(-1.0f, 1.0f));
    else
        shape.setScale(sf::Vector2f(1.0f, 1.0f));

    shape.move(x * 0.5f, y * 0.5f);
    shape.setTextureRect(animation->uvRect);
    animation->Update(1, deltaTime);
}