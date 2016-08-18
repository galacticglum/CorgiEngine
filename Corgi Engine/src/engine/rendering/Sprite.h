#ifndef _ENGINE_SPRITE_H
#define _ENGINE_SPRITE_H

#include "../Engine.h"
#include "Color.h"
#include "Window.h"
#include "../maths/Rectangle.h"
#include "resources/Texture.h"
#include "../core/resource/Resources.h"
#include "../core/resource/Resource.h"

class Sprite 
{
public:
	Sprite(Window* window, std::string& filePath) : Sprite(window, filePath, SDL_BLENDMODE_NONE) { }
	Sprite(Window* window, std::string& filePath, SDL_BlendMode blendMode);
	~Sprite();

	void Crop(const Rectangle& rectangle);
	// TODO: void Clip(const Vector2& positon, int width, int height);

	void SetTint(float r, float g, float b) { SetTint(Color(r, g, b)); }
	void SetTint(float r, float g, float b, float a) { SetTint(Color(r, g, b, a)); }
	void SetTint(Color &color);

	void Draw(float x, float y);
	void Draw(const Vector2 position) { this->Draw(position.X, position.Y); }
	void Refresh();

	void Scale(const Vector2& scale);
	void Scale(float scaleX, float scaleY) { Scale(Vector2(scaleX, scaleY)); }

	int GetWidth() { return this->m_Width; }
	int GetHeight() { return this->m_Height; }

	SDL_BlendMode GetBlendMode();
	void SetBlendMode(SDL_BlendMode blendMode) { SDL_SetTextureBlendMode(this->m_Texture->GetSDLTexture(), blendMode); }
private:
	Window* m_Window;
	Texture* m_Texture;
	SDL_Surface* m_TransformedSurface;
	SDL_Rect m_TransformedRectangle;

	Rectangle* m_Rectangle;

	float m_Angle;
	Vector2 m_Scale;

	float m_Width;
	float m_Height;
};

#endif