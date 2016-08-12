#include "ResourceManager.h"

Texture* ResourceManager::LoadTexture(std::string& filePath, Window* window)
{
	if (filePath.empty())
	{
		std::cout << "ResourceManager::LoadTexture: string filePath was empty!" << std::endl;
		exit(EXIT_FAILURE);
	}

	auto iterator = this->m_TextureMap.find(filePath);
	if (iterator != this->m_TextureMap.end())
	{
		iterator->second->AddReference();
		return iterator->second.get();
	}

	std::unique_ptr<Texture> resource = std::make_unique<Texture>(filePath, window);
	resource->AddReference();
	this->m_TextureMap.insert(std::make_pair(filePath, std::move(resource)));
	return this->m_TextureMap.find(filePath)->second.get();
}

void ResourceManager::DestroyTexture(Texture* texture)
{
	if (texture == NULL)
	{
		std::cout << "ResourceManager::DestroyTexture: texture resource was NULL!" << std::endl;
		exit(EXIT_FAILURE);
	}

	auto iterator = this->m_TextureMap.find(texture->GetFilePath());
	if (iterator != this->m_TextureMap.end())
	{
		iterator->second.get()->RemoveReference();
		if (iterator->second.get()->GetReferenceCount() == 0)
		{
			std::cout << "ResourceManager::DestroyTexture: Destroyed: " << iterator->second.get()->GetFileName() << std::endl;
			iterator->second.release();
			this->m_TextureMap.erase(iterator);
		}
	}

	std::cout << "ResourceManager::DestroyTextures: cannot destroy " << texture->GetFileName() << "!" << std::endl;
}

void ResourceManager::FreeResources()
{
	// free textures
	auto textures = this->m_TextureMap.begin();
	while (textures != this->m_TextureMap.end())
	{
		std::cout << "ResourceManager::FreeResources: freed: " << textures->second.get()->GetFileName() << std::endl;
		textures->second.release();
		textures = this->m_TextureMap.erase(textures);
	}
}