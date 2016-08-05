#include "game/TestGame.h"

int main(int argc, char* argv[])
{
	std::string title = "Corgi Engine";
	TestGame game(800, 600, title, 60.0);

	return 0;
}