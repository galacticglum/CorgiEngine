#ifndef _GAME_TESTGAME_H
#define _GAME_TESTGAME_H

#include "../Corgi.h"

class TestGame : Game
{
public:
	TestGame(unsigned int width, unsigned int height, const std::string &title) : TestGame(width, height, title, 60.0) { }
	TestGame::TestGame(uint32_t width, uint32_t height, const std::string &title, double frameRate) : Game(width, height, title, frameRate), m_SpriteX(1.f), m_SpriteY(0.f)
	{
		this->Run();
	}

	void OnInitialize() override
	{
		std::string filePath = "res/textures/player.png";
		this->m_Sprite = new Sprite(this->GetWindow(), filePath, SDL_BLENDMODE_BLEND);
	}

	void OnUpdate() override
	{
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

	void OnQuit() override
	{
		delete this->m_Sprite;
		this->m_Sprite = nullptr;
	}

private:
	Sprite* m_Sprite;

	float m_SpriteX;
	float m_SpriteY;

	Color* m_SpriteColour;
};

#endif