#pragma once
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <vector>
#include <memory>


class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;

public:
	SceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
	void update(sf::Time dt);
	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const; // Only draws the current object, not its children
	void drawChildren(sf::RenderTarget& target, sf::RenderStates& states) const;
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);
};