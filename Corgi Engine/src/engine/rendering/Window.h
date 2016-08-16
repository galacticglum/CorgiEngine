#ifndef _ENGINE_WINDOW_H
#define _ENGINE_WINDOW_H

#include "../Engine.h"
#include "primitives/Rectangle.h"

class Window
{
public:
	Window(unsigned int width, unsigned int height, const std::string &title);
	void Destroy();

	void RenderTexture(SDL_Texture* texture, Rectangle* source, Rectangle* destination);
	void Clear();
	void SwapBuffers();

	void SetTitle(const std::string& title);

	SDL_Window* GetWindow() { return m_Window; }
	SDL_Renderer* GetRenderer() { return m_Renderer; }

	unsigned int GetWidth() { return this->m_Width; }
	unsigned int GetHeight() { return this->m_Height; }
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	SDL_Event m_Event;

	unsigned int m_Width;
	unsigned int m_Height;
};
#endif
