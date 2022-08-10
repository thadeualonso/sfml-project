#pragma once
#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id, const std::string& filename);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;

private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

template <typename Resource, typename Identifier>
void ResourceHolder::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());

	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	auto inserted = mResourcesMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}
Resource& ResourceHolder::get(Identifier id)
{
}