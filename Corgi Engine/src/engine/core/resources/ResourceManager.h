#ifndef _ENGINE_RESOURCE_MANAGER_H
#define _ENGINE_RESOURCE_MANAGER_H

#include "../../Engine.h"
#include "../../rendering/Window.h"
#include "../../rendering/resources/Texture.h"
#include "Resource.h"

class ResourceManager
{
public:
	ResourceManager() { }
	~ResourceManager() { this->FreeResources(); }

	Texture* LoadTexture(std::string& filePath, Window* window);
	void DestroyTexture(Texture* resource);
private:
	std::unordered_map<std::string, Texture*> m_TextureMap;

	ResourceManager(const ResourceManager&) { }
	ResourceManager& operator=(const ResourceManager&) { return *this; }

	void FreeResources();
};

#endif


