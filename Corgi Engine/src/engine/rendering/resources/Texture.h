#ifndef _ENGINE_TEXTURE_H
#define _ENGINE_TEXTURE_H

#include "../../core/resources/Resource.h"
#include "../Window.h"

class Texture : public Resource
{
friend class Resources;
public:
	Texture(std::string& filePath, Window* window) : m_Window(window), Resource(filePath) { this->Load(); }
	~Texture();

	SDL_Texture* GetSDLTexture() { return this->m_Texture; }
protected:
	void Load() override;

private:
	void Destroy();

	SDL_Texture* m_Texture;
	Window* m_Window;
};

#endif
