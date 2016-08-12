#include "TestGame.h"

TestGame::TestGame(uint32_t width, uint32_t height, const std::string &title, double frameRate) : Game(width, height, title, frameRate), m_SpriteX(1.f), m_SpriteY(0.f)
{
	this->Run();
}

void TestGame::OnInitialize()
{
	std::string filePath = "res/textures/sprite.jpg";
	this->m_Sprite = new Sprite(this->GetWindow(), filePath, SDL_BLENDMODE_BLEND);
}

void TestGame::OnUpdate()
{
	//this->m_SpriteX = sin((double)Time::GetTime()) * (double)500;
	if (Input::GetInstance()->GetKey(KEY_W))
	{
		this->m_SpriteY -= 2.f;
	}

	if (Input::GetInstance()->GetKey(KEY_A))
	{
		this->m_SpriteX -= 2.f;
	}

	if (Input::GetInstance()->GetKey(KEY_S))
	{
		this->m_SpriteY += 2.f;
	}

	if (Input::GetInstance()->GetKey(KEY_D))
	{
		this->m_SpriteX += 2.f;
	}
}

void TestGame::OnRender()
{
	this->m_Sprite->Draw(this->m_SpriteX, this->m_SpriteY);
}

void TestGame::OnQuit()
{
	delete this->m_Sprite;
}