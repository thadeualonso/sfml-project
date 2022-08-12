#include "Aircraft.h"
#include "ResourceIdentifiers.hpp"
#include <iostream>

Aircraft::Aircraft(Type type, const TextureHolder& textures) :
	mType(type)
{
	std::cout << mType << std::endl;
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}