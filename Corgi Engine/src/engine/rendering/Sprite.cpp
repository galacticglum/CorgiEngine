#include "Sprite.h"

Sprite::Sprite(Window* window, std::string& filePath, SDL_BlendMode blendMode) : m_Window(window), m_Texture(nullptr), m_Rectangle(nullptr), m_Width(0), m_Height(0)
{
	this->m_Texture = Resources::LoadTexture(filePath, this->m_Window);
	if (!this->m_Texture->GetSDLTexture())
	{
		// TODO: logging
		std::cout << "Sprite::Sprite: failed to load sprite: '" << this->m_Texture->GetFilePath() << "'" << std::endl;
		exit(EXIT_FAILURE);
	}

	int width;
	int height;
	SDL_QueryTexture(this->m_Texture->GetSDLTexture(), nullptr, nullptr, &width, &height);

	this->m_Width = width;
	this->m_Height = height;

	this->Crop(Rectangle(0, 0, this->m_Width, this->m_Height));
	SDL_SetTextureBlendMode(this->m_Texture->GetSDLTexture(), blendMode);
}

Sprite::~Sprite()
{
	if (this->m_Texture->GetSDLTexture())
	{
		Resources::DestroyTexture(this->m_Texture);
	}

	if (this->m_Rectangle)
	{
		delete this->m_Rectangle;
	}
}

void Sprite::Crop(const Rectangle& rectangle)
{
	if (!this->m_Rectangle)
	{
		this->m_Rectangle = new Rectangle;
	}

	this->m_Rectangle->Copy(rectangle);
}

void Sprite::SetTint(Color& color)
{
	SDL_SetTextureColorMod(this->m_Texture->GetSDLTexture(), (Uint8)color.R, (Uint8)color.G, (Uint8)color.B);
	if (color.A >= 0)
	{
		SDL_SetTextureAlphaMod(this->m_Texture->GetSDLTexture(), (Uint8)color.A);
	}
}

void Sprite::Draw(float x, float y)
{
	Rectangle destination(x, y, this->m_Rectangle->GetWidth(), this->m_Rectangle->GetHeight());
	this->m_Window->RenderTexture(this->m_Texture->GetSDLTexture(), this->m_Rectangle, &destination);
}

void Sprite::Refresh()
{
	this->Crop(Rectangle(0, 0, this->m_Width, this->m_Height));
}

SDL_BlendMode Sprite::GetBlendMode()
{
	SDL_BlendMode blendMode;
	SDL_GetTextureBlendMode(this->m_Texture->GetSDLTexture(), &blendMode);
	return blendMode;
}
