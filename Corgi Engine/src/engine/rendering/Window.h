#ifndef _ENGINE_WINDOW_H
#define _ENGINE_WINDOW_H

#include "../Engine.h"
#include "../maths/Rectangle.h"
#include "../core/time/Time.h"

class Window
{
public:
	Window(unsigned int width, unsigned int height, const std::string &title);
	~Window() { this->Destroy(); }
	void Destroy();

	void RenderTexture(SDL_Texture* texture, Rectangle* source, Rectangle* destination);
	void Clear();
	void SwapBuffers();

	void Update(); 

	void SetTitle(const std::string& title);

	SDL_Window* GetSDLWindow() { return m_Window; }
	SDL_Surface* GetSDLSurface() { return m_ScreenSurface; }
	SDL_Renderer* GetSDLRenderer() { return m_Renderer; }

	unsigned int GetWidth() { return this->m_Width; }
	unsigned int GetHeight() { return this->m_Height; }

	void FadeIn(float speed);
	void FadeOut(float speed);
private:
	SDL_Window* m_Window;
	SDL_Surface* m_ScreenSurface;
	SDL_Renderer* m_Renderer;
	SDL_Event m_Event;

	unsigned int m_Width;
	unsigned int m_Height;

	bool m_FadeIn;
	bool m_FadeOut;
	float m_FadeInSpeed;
	float m_FadeOutSpeed;

	float m_ScreenSurfaceAlpha;
};
#endif
