#ifndef _GAME_GAME_SCENE_H
#define _GAME_GAME_SCENE_H

#include "../../engine/core/scene management/Scene.h"
#include "../../Corgi.h"

class Sprite;
class GameScene : public Scene
{
public:
	void OnLoad() override
	{
		std::string filePath = "res/textures/sprite.jpg";
		this->m_Sprite = new Sprite(this->GetWindow(), filePath, SDL_BLENDMODE_BLEND);
	}

	void OnUpdate() override
	{
		if (GetInput()->GetKeyDown(Key::KEY_F))
		{
		}

		float speed = 100.0f * Time::GetDeltaTime();
		if (GetInput()->GetKey(Key::KEY_W))
		{
			this->m_SpriteY -= speed;
		}

		if (GetInput()->GetKey(Key::KEY_A))
		{
			this->m_SpriteX -= speed;
		}

		if (GetInput()->GetKey(Key::KEY_S))
		{
			this->m_SpriteY += speed;
		}

		if (GetInput()->GetKey(Key::KEY_D))
		{
			this->m_SpriteX += speed;
		}
	}

	void OnRender() override
	{
		this->m_Sprite->Draw(this->m_SpriteX, this->m_SpriteY);
	}

	void OnUnload() override
	{
		delete this->m_Sprite;
		this->m_Sprite = nullptr;
	}
private:
	Sprite* m_Sprite;
	float m_SpriteX;
	float m_SpriteY;
};

#endif