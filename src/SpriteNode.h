#pragma once
#include <SFML/Graphics.hpp>
#include "SceneNode.h"

class SpriteNode : public SceneNode
{
private:
	sf::Sprite mSprite;

public:
	explicit SpriteNode(const sf::Texture& texture);
	SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};