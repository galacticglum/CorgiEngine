#ifndef _GAME_TESTGAME_H
#define _GAME_TESTGAME_H

#include "../Corgi.h"

class TestGame : Game
{
public:
	TestGame(unsigned int width, unsigned int height, const std::string &title) : TestGame(width, height, title, 60.0) {}
	TestGame(unsigned int width, unsigned int height, const std::string &title, double frameRate);

	void OnUpdate() override;
};

#endif