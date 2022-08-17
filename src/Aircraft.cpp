#include "Aircraft.h"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID Aircraft::toTextureID(Aircraft::Type type)
{
	Textures::ID textureType;
	switch (type)
	{
		case Aircraft::Player:
			textureType = Textures::PlayerShip;
			break;
		case Aircraft::Enemy:
			textureType = Textures::EnemyShip;
			break;
		default:
			break;
	}
	return textureType;
}

Aircraft::Aircraft(Type type, const TextureHolder& textures) :
	mType(type),
	mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}