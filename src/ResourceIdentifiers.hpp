#pragma once
#include <SFML/Graphics.hpp>

namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		PlayerShip,
		EnemyShip,
		Airplane,
		Landscape,
		Missile
	};
}

namespace Fonts
{
	enum ID
	{
		MiniSquare
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;