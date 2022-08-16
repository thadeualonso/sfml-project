#include "Aircraft.h"
#include "ResourceIdentifiers.hpp"
#include <iostream>

Aircraft::Aircraft(Type type) :
	mType(type)
{
	std::cout << mType << std::endl;
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}