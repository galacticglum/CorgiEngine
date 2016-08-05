#ifndef _ENGINE_WINDOW_H
#define _ENGINE_WINDOW_H

#include "../Engine.h"

class Window
{
public:
	Window(unsigned int width, unsigned int height, const std::string &title);
	void Destroy();

	void Clear();
	void SwapBuffers();

	inline SDL_Window* GetWindow() { return m_Window; }
	inline SDL_Renderer* GetRenderer() { return m_Renderer; }
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	SDL_Event m_Event;
};
#endif
