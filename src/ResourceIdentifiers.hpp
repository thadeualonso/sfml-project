#pragma once

namespace sf
{
class Texture;
}

namespace Textures
{
enum ID
{
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