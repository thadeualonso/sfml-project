#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <memory>
#include <string>

namespace Textures
{
enum ID
{
	Landscape,
	Airplane,
	Missile
};
}

class TextureHolder
{
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

public:
	TextureHolder();
	~TextureHolder();
	void load(Textures::ID id, const std::string& filename);
	sf::Texture& get(Textures::ID id);
	const sf::Texture& get(Textures::ID id) const;
};