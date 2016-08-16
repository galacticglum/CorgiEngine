#include "Game.h"

Game::Game(unsigned int width, unsigned int height, const std::string &title, double frameCap) : m_Running(false), m_Window(nullptr), m_FPS(0), m_UPS(0)
{
	if (frameCap <= 0)
	{
		std::cout << "Game::Game: Could not initialize Game! Framecap has an invalid value (auto default to 60)." << std::endl;
		frameCap = 60.0;
	}

	this->m_FrameCap = (1.0 / frameCap);

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		std::cout << "Game::Game: Could not initialize SDL: " << SDL_GetError() << std::endl;
		return;
	}

	this->m_Window = new Window(width, height, title);
	m_Running = true;

	Resources::Initialize();
	m_Input = new Input(this->m_Window);
}

Game::~Game()
{

	this->Destroy();
}

void Game::Run()
{
	this->OnInitialize();
	double lastTime = Time::GetTime();
	double updateTimer = 0;
	double gapTime = 0;

	int frames = 0;
	int updates = 0;

	while (this->m_Running)
	{
		bool doRender = false;

		double startTime = Time::GetTime();
		double deltaTime = startTime - lastTime;
		lastTime = startTime;

		gapTime += deltaTime;
		updateTimer += deltaTime;

		if (updateTimer >= 1.0)
		{
			this->m_FPS = frames;
			this->m_UPS = updates;
			frames = 0;
			updates = 0;
			updateTimer = 0;
		}

		while (gapTime > this->m_FrameCap)
		{
			Time::m_DeltaTime = (float)m_FrameCap;
			this->Update();	
			updates++;

			doRender = true;
			gapTime -= this->m_FrameCap;
		}

		if (doRender)
		{
			this->Render();
			frames++;
		}
		else
		{
			Time::Pause(1);
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
	m_Input->Update(this->m_Event);
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
	Resources::Destroy();
	delete this->m_Window;
	this->m_Window = nullptr;
	delete this->m_Input;
}
