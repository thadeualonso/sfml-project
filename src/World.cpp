#include "World.h"

World::World(sf::RenderWindow& window)
	: mWindow(window),
	mWorldView(window.getDefaultView()),
	mWorldBounds(sf::FloatRect(0.f, 0.f, mWindow.getSize().x, 2000.f)),
	mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y),
	mTextureHolder(),
	mSceneGraph(),
	mSceneLayers(),
	mScrollSpeed(-50.f),
	mPlayerAircraft(nullptr)
{
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

	sf::Vector2f playerPosition = mPlayerAircraft->getPosition();
	sf::Vector2f playerVelocity = mPlayerAircraft->getVelocity();

	if(playerPosition.x <= mWorldBounds.left + 150
	|| playerPosition.x >= mWorldBounds.left + mWorldBounds.width - 150)
	{
		playerVelocity.x = -playerVelocity.x;
		mPlayerAircraft->setVelocity(playerVelocity);
	}

	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}
void World::loadTextures()
{
	mTextureHolder.load(Textures::PlayerShip, "content/textures/ship_0010.png");
	mTextureHolder.load(Textures::Landscape, "content/textures/tile_desert.png");
}
void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& landscapeTexture = mTextureHolder.get(Textures::Landscape);
	sf::IntRect textureRect(mWorldBounds);
	landscapeTexture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite = std::make_unique<SpriteNode>(landscapeTexture, textureRect);
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	backgroundSprite->setScale(2.f, 2.f);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Aircraft> leader = std::make_unique<Aircraft>(Aircraft::Player, mTextureHolder);
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
	mPlayerAircraft->setScale(2.f, 2.f);
	mSceneLayers[Air]->attachChild(std::move(leader));

	std::unique_ptr<Aircraft> leftEscort = std::make_unique<Aircraft>(Aircraft::Player, mTextureHolder);
	leftEscort->setPosition(-80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	std::unique_ptr<Aircraft> rightEscort = std::make_unique<Aircraft>(Aircraft::Player, mTextureHolder);
	rightEscort->setPosition(80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(rightEscort));
}