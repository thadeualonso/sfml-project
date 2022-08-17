#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.h"
#include "Aircraft.h"
#include "SpriteNode.h"
#include <array>

class World : public sf::NonCopyable
{
private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	TextureHolder mTextureHolder;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;

public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();

private:
	void loadTextures();
	void buildScene();
};