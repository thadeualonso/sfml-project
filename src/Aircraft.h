#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "Entity.h"
#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity
{
public:
	enum Type
	{
		Player,
		Enemy
	};

	explicit Aircraft(Type type, const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;

	Textures::ID toTextureID(Aircraft::Type type);
};
