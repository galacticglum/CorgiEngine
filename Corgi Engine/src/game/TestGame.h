#ifndef _GAME_TESTGAME_H
#define _GAME_TESTGAME_H

#include "../Corgi.h"
#include "scenes\GameScene.h"

class TestGame : public Game
{
public:
	TestGame(unsigned int width, unsigned int height, const std::string &title) : TestGame(width, height, title, 60.0) { }
	TestGame::TestGame(uint32_t width, uint32_t height, const std::string &title, double frameRate) : Game(width, height, title, frameRate)
	{
		this->Run();
	}

	void OnInitialize() override
	{
		m_GameScene = new GameScene();
		std::string sceneName = "GameScene";
		this->GetSceneManager()->Load(sceneName, this->m_GameScene);
	}
private:
	GameScene* m_GameScene;
};

#endif