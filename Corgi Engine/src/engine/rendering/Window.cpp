#include "Window.h"

Window::Window(uint32_t width, uint32_t height, const std::string &title)
{
	if (SDL_WasInit(SDL_INIT_VIDEO) == 0)
	{
		std::cout << "Window::Initialize: Could not initialize window, SDL is not initialized!" << std::endl;
		return;
	}

	this->m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if (this->m_Window == nullptr)
	{
		std::cout << "Window::Initialize: Unable to create window!" << std::endl;
		return;
	}

	this->m_Renderer = SDL_CreateRenderer(this->m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (this->m_Renderer == nullptr)
	{
		std::cout << "Window::Initialize: Unable to create renderer!" << std::endl;
		return;
	}

	SDL_SetRenderDrawColor(this->m_Renderer, 255, 0, 0, 255);

	return;
}

void Window::Clear()
{
	SDL_RenderClear(this->m_Renderer);
}

void Window::SwapBuffers()
{
	SDL_RenderPresent(this->m_Renderer);
}

void Window::Destroy()
{
	if (this->m_Renderer)
	{
		SDL_DestroyRenderer(this->m_Renderer);
		this->m_Renderer = nullptr;
	}

	if (this->m_Window)
	{
		SDL_DestroyWindow(this->m_Window);
		this->m_Window = nullptr;
	}
}