#include "Player.h"

Player::Player(sf::RenderWindow* window) : idleAnimation(&texture, sf::Vector2u(23, 4), 0.1f, 0, 0), walkAnimation (&texture, sf::Vector2u(23, 4), 0.1f, 1, 4)
{
    this->shape = sf::RectangleShape(sf::Vector2f(64.0f, 64.0f));
    this->texture.loadFromFile("textures/characters.png");
    this->window = window;

    sf::Vector2u textureSize = this->texture.getSize();
    textureSize.x /= 23;
    textureSize.y /= 4;

    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(0, 32, textureSize.x, textureSize.y));
    shape.setOrigin(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));
    shape.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
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