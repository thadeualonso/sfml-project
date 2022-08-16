#pragma once
#include "Entity.h"
#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor
	};

	explicit Aircraft(Type type);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};
