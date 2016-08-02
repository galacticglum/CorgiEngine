#include "Game.h"

Game::Game(uint32_t width, uint32_t height, const std::string &title, double frameCap) : m_Window(nullptr)
{
	if (frameCap <= 0)
	{
		std::cout << "Game::Game: Could not initialize Game! Framecap has an invalid value (auto default to 60)." << std::endl;
		frameCap = 60.0;
	}

	this->m_FrameTime = (1.0 / frameCap);

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		std::cout << "Game::Game: Could not initialize SDL: " << SDL_GetError() << std::endl;
		return;
	}

	this->m_Window = new Window(width, height, title);
	m_Running = true;
}

Game::~Game()
{
	this->Destroy();
}

void Game::Run()
{
	double lastTime = Time::GetTime();
	double frameTimer = 0;
	double gapTime = 0;

	int frames = 0;

	while (this->m_Running)
	{
		bool doRender = false;

		double startTime = Time::GetTime();
		double deltaTime = startTime - lastTime;
		lastTime = startTime;

		gapTime += deltaTime;
		frameTimer += deltaTime;

		if (frameTimer >= 1.0)
		{
			this->m_FPS = frames;
			frames = 0;
			frameTimer = 0;
		}

		while (gapTime > (this->m_FrameTime))
		{
			Time::SetDeltaTime(deltaTime);
			this->Update();
			doRender = true;

			gapTime -= (this->m_FrameTime);
		}

		if (doRender)
		{
			this->Render();
			frames++;
		}
		else
		{
			SDL_Delay(1);
		}
	}
}

void Game::ProcessEvents()
{
	if (SDL_PollEvent(&this->m_Event))
	{
		switch (this->m_Event.type)
		{
		case SDL_QUIT:
		{
			this->m_Running = false;
		}
		}
	}
}

void Game::Update()
{
	ProcessEvents();
	//Input::Update();
	this->OnUpdate();
}

void Game::Render()
{
	this->m_Window->Clear();
	this->OnRender();
	this->m_Window->SwapBuffers();
}

void Game::Destroy()
{
	OnQuit();

	SDL_Quit();

	// Destroy our window
	delete this->m_Window;
	this->m_Window = nullptr;
}
