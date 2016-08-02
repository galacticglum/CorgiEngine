#include "TestGame.h"

TestGame::TestGame(uint32_t width, uint32_t height, const std::string &title, double frameRate) : Game(width, height, title, frameRate)
{
	this->Run();
}

void TestGame::OnUpdate()
{
	std::cout << this->GetFPS() << std::endl;
}