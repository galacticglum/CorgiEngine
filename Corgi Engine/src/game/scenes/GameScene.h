#ifndef _GAME_GAME_SCENE_H
#define _GAME_GAME_SCENE_H

#include "../../engine/core/scene management/Scene.h"
#include "../../engine/Engine.h"
#include "../../Corgi.h"

class Sprite;
class GameScene : public Scene
{
public:
	void OnLoad() override
	{
		std::string filePath = "res/textures/sprite.jpg";
		this->m_Sprite = new Sprite(this->GetGame()->GetWindow(), filePath, SDL_BLENDMODE_BLEND);

		this->m_FontColour = new Color(0, 0, 0);
		this->m_Font = TTF_OpenFont("res/fonts/FreeSans.ttf", 24);
	}

	void OnUpdate() override
	{
		if (this->GetGame()->GetInput()->GetKeyDown(Key::KEY_F))
		{
		}

		float speed = 100.0f * Time::GetDeltaTime();
		if (this->GetGame()->GetInput()->GetKey(Key::KEY_W))
		{
			this->m_SpriteY -= speed;
		}

		if (this->GetGame()->GetInput()->GetKey(Key::KEY_A))
		{
			this->m_SpriteX -= speed;
		}

		if (this->GetGame()->GetInput()->GetKey(Key::KEY_S))
		{
			this->m_SpriteY += speed;
		}

		if (this->GetGame()->GetInput()->GetKey(Key::KEY_D))
		{
			this->m_SpriteX += speed;
		}
	}

	void OnRender() override
	{
		this->m_Sprite->Draw(this->m_SpriteX, this->m_SpriteY);
		RenderFPS();
	}

	void OnUnload() override
	{
		delete this->m_Sprite;
		this->m_Sprite = nullptr;

		delete this->m_FontColour;
		this->m_FontColour = nullptr;

		SDL_DestroyTexture(this->m_TextTexture);
		this->m_TextTexture = nullptr;

		TTF_CloseFont(this->m_Font);
		this->m_Font = nullptr;
	}

	void RenderFPS()
	{
		// TODO: Elegant and better way of text rendering! For now this is fine.
		std::string text = "FPS: " + std::to_string(this->GetGame()->GetFPS()) + " | UPS: " + std::to_string(this->GetGame()->GetUPS());

		SDL_Surface* surface = TTF_RenderText_Solid(this->m_Font, text.c_str(), this->m_FontColour->GetSDLColour());
		this->m_TextTexture = SDL_CreateTextureFromSurface(this->GetGame()->GetWindow()->GetSDLRenderer(), surface);

		int width = surface->w;
		int height = surface->h;
		SDL_Rect textRect = { 4, 2,  width, height };
		SDL_RenderCopy(this->GetGame()->GetWindow()->GetSDLRenderer(), this->m_TextTexture, NULL, &textRect);

		SDL_FreeSurface(surface);
		surface = nullptr;
	}
private:
	Sprite* m_Sprite;
	float m_SpriteX;
	float m_SpriteY;

	SDL_Texture* m_TextTexture;

	TTF_Font* m_Font;
	Color* m_FontColour;
};

#endif