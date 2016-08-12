#ifndef _ENGINE_GAME_H
#define _ENGINE_GAME_H

#include "../Engine.h"
#include "../rendering/Window.h"
#include "Time.h"
#include "resources\Resources.h"
#include "input\Input.h"

class Game
{
public:
	inline Game(unsigned int width, unsigned int height, const std::string &title) : Game(width, height, title, 60.0) {}
	Game(unsigned int width, unsigned int height, const std::string &title, double frameRate);
	virtual ~Game();

	virtual void OnInitialize() {}
	virtual void OnUpdate() {}
	virtual void OnRender() {}
	virtual void OnQuit() {}

	void Destroy();

	inline float GetFPS() { return m_FPS; }
protected:
	void Run();

	Window* GetWindow() { return this->m_Window; }
private:
	Window* m_Window;
	SDL_Event m_Event;

	// FPS-
	double m_FrameTime;
	float m_FPS;

	bool m_Running;

	void ProcessEvents();
	void Update();
	void Render();
};

#endif // GAME_H is defined; we can just use the macro definition.