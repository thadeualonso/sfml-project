#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int index, sf::Vector2f size)
{
    index_ = index;
    rect_.setSize(size);
    rect_.setFillColor(sf::Color::Red);
    rect_.setOutlineColor(sf::Color::White);
    rect_.setOutlineThickness(1.0f);
    rect_.setOrigin(sf::Vector2f(rect_.getSize().x / 2.0f, rect_.getSize().y / 2.0f));
}

sf::Vector2f Enemy::getSize()
{
    return rect_.getSize();
}

void Enemy::rotate(float angle)
{
    rect_.rotate(angle);
}

void Enemy::setPosition(sf::Vector2f position)
{
    rect_.setPosition(position);
}

void Enemy::update()
{
    rect_.move(0.f, 1.f);
}

void Enemy::render(sf::RenderWindow* window)
{
    window->draw(rect_);
}
