#include "Texture.h"

Texture::~Texture()
{
	this->Destroy();
}

void Texture::Destroy()
{
	SDL_DestroyTexture(this->m_Texture);
}

void Texture::Load()
{
	this->m_Texture = IMG_LoadTexture(this->m_Window->GetSDLRenderer(), this->GetFilePath().c_str());

	if (!this->m_Texture)
	{
		// TODO proper logging
		std::cout << "Texture::Load: couldn't load image '" << GetFileName() << "': " << IMG_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
}