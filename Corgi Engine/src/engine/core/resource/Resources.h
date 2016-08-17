#ifndef _ENGINE_RESOURCES_H
#define _ENGINE_RESOURCES_H

#include "ResourceManager.h"
#include "../../rendering/resources/Texture.h"

class Resources
{
friend class Game;
public:
	static Texture*	LoadTexture(std::string& filePath, Window* window);
	static void DestroyTexture(Texture* texture) { m_ResourceManager->DestroyTexture(texture); }
private:
	static ResourceManager* m_ResourceManager;
	static void Initialize();
	static void Destroy();

	/*

	TODO: Level | State manager
	class Level : State
	{
		// contain it's own resource managers....
		// we will know what resources we want in our level.
		// resource manager will delete itself whne it goes out of scope!
	};

	*/
};

#endif
