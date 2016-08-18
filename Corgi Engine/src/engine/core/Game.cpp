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

	if (TTF_Init() != 0)
	{
		std::cout << "Game::Game: Could not initialize SDL_TTF: " << SDL_GetError() << std::endl;
		return;
	}

	this->m_Window = new Window(width, height, title);
	m_Running = true;

	Resources::Initialize();
	m_Input = new Input(this->m_Window);

	this->m_SceneManager = new SceneManager(this);
}

Game::~Game()
{
	this->Destroy();

	MemoryStats memStats = MemoryManager::GetInstance()->GetMemoryStats();
	std::cerr << "\n----------------------------------------------" << "\n";
	std::cerr << "Memory Allocated: " << MemoryManager::BytesToString(memStats.TotalAllocated) << "\n";
	std::cerr << "Memory Freed: " << MemoryManager::BytesToString(memStats.TotalFreed) << "\n";
	std::cerr << "Current Memory Usage: " << MemoryManager::BytesToString(memStats.CurrentUsage) << "\n";
	std::cerr << "----------------------------------------------" << "\n";
	std::cerr << "Memory Allocations: " << memStats.TotalAllocations << "\n";
	std::cerr << "Memory Deallocations: " << memStats.TotalDeallocations << "\n";
	std::cerr << "----------------------------------------------" << "\n\n";
}

void Game::Run()
{
	this->OnInitialize();
	double lastTime = Time::GetTime();
	double updateTimer = 0;
	double gapTime = 0;

	int frames = 0;
	int updates = 0;

	MemoryStats memStats = MemoryManager::GetInstance()->GetMemoryStats();
	std::cerr << "----------------------------------------------" << "\n";
	std::cerr << "Memory Allocated: " << MemoryManager::BytesToString(memStats.TotalAllocated) << "\n";
	std::cerr << "Memory Freed: " << MemoryManager::BytesToString(memStats.TotalFreed) << "\n";
	std::cerr << "Current Memory Usage: " << MemoryManager::BytesToString(memStats.CurrentUsage) << "\n";
	std::cerr << "----------------------------------------------" << "\n";
	std::cerr << "Memory Allocations: " << memStats.TotalAllocations << "\n";
	std::cerr << "Memory Deallocations: " << memStats.TotalDeallocations << "\n";
	std::cerr << "----------------------------------------------" << "\n\n";

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

	this->OnQuit();
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
	this->m_SceneManager->Update();
	this->OnUpdate();
}

void Game::Render()
{
	this->m_Window->Clear();
	this->m_Window->Update();
	this->m_SceneManager->Render();
	this->OnRender();
	this->m_Window->SwapBuffers();
}

void Game::Destroy()
{
	this->m_SceneManager->Destroy();
	delete this->m_SceneManager;
	this->m_SceneManager = nullptr;

	SDL_Quit();
	Resources::Destroy();

	delete this->m_Window;
	this->m_Window = nullptr;

	delete this->m_Input;
	this->m_Input = nullptr;
}
