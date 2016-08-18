#ifndef _ENGINE_GAME_H
#define _ENGINE_GAME_H

#include "../Engine.h"
#include "../rendering/Window.h"
#include "resource/Resources.h"
#include "input/Input.h"
#include "time/Time.h"
#include "scene management\SceneManager.h"

#include "../system/MemoryManager.h"
#include "../system/MemoryStats.h"

class Game
{
public:
	Game(unsigned int width, unsigned int height, const std::string &title) : Game(width, height, title, 60.0) {}
	Game(unsigned int width, unsigned int height, const std::string &title, double frameCap);
	virtual ~Game();

	virtual void OnInitialize() {}
	virtual void OnUpdate() {}
	virtual void OnRender() {}
	virtual void OnQuit() {}

	void Destroy();

	int GetFPS() { return m_FPS; }
	int GetUPS() { return m_UPS; }

	Input* GetInput() { return this->m_Input; }
	Window* GetWindow() { return this->m_Window; }
	SceneManager* GetSceneManager() { return this->m_SceneManager; }
protected:
	void Run();
private:
	Window* m_Window;
	Input* m_Input;
	SDL_Event m_Event;
	SceneManager* m_SceneManager;

	// FPS
	double m_FrameCap;
	int m_FPS;
	int m_UPS;

	bool m_Running;

	void ProcessEvents();
	void Update();
	void Render();
};

#endif // GAME_H is defined; we can just use the macro definition.