#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
public:
	int index_;
	sf::RectangleShape rect_;
	Enemy(int index, sf::Vector2f size);

	sf::Vector2f getSize();

	void rotate(float angle);
	void setPosition(sf::Vector2f position);
	
	void update();
	void render(sf::RenderWindow* window);
};