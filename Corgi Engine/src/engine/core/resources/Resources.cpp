#include "Resources.h"

ResourceManager* Resources::m_ResourceManager;

void Resources::Initialize()
{
	// initialize our managers
	m_ResourceManager = new ResourceManager();
}

Texture* Resources::LoadTexture(std::string& filePath, Window* window)
{
	return m_ResourceManager->LoadTexture(filePath, window);
}

void Resources::Destroy()
{
	delete m_ResourceManager;
}