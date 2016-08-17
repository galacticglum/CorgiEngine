#include "Input.h"

Input::Input(Window* window) : m_Window(window), m_MouseX(0), m_MouseY(0)
{
	// Initialize arrays
	memset(this->m_Keys, 0, KEY_COUNT * sizeof(bool));
	memset(this->m_DownKeys, 0, KEY_COUNT * sizeof(bool));
	memset(this->m_UpKeys, 0, KEY_COUNT * sizeof(bool));

	memset(this->m_MouseButtons, 0, MOUSE_BUTTON_COUNT * sizeof(bool));
	memset(this->m_MouseButtonsDown, 0, MOUSE_BUTTON_COUNT * sizeof(bool));
	memset(this->m_MouseButtonsUp, 0, MOUSE_BUTTON_COUNT * sizeof(bool));
}

Input::~Input()
{

}

void Input::Update(SDL_Event event)
{
	// Reset up, down keys and mouse buttons but NOT "holding" keys/buttons.
	for (int i = 0; i < KEY_COUNT; i++)
	{
		this->m_DownKeys[i] = false;
		this->m_UpKeys[i] = false;
	}

	for (int i = 0; i < MOUSE_BUTTON_COUNT; i++)
	{
		this->m_MouseButtonsDown[i] = false;
		this->m_MouseButtonsUp[i] = false;
	}

	if( event.type == SDL_MOUSEMOTION)
	{
		this->m_MouseX = event.motion.x;
		this->m_MouseY = event.motion.y;
	}
	if (event.type == SDL_KEYDOWN)
	{
		int scancode = event.key.keysym.scancode;

		this->m_Keys[scancode] = true;
		this->m_DownKeys[scancode] = true;
	}	
	if (event.type == SDL_KEYUP)
	{
		int scancode = event.key.keysym.scancode;

		this->m_Keys[scancode] = false;
		this->m_UpKeys[scancode] = true;
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		int buttonCode = event.button.button;

		this->m_MouseButtons[buttonCode] = true;
		this->m_MouseButtonsDown[buttonCode] = true;
	}
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		int buttonCode = event.button.button;

		this->m_MouseButtons[buttonCode] = false;
		this->m_MouseButtonsUp[buttonCode] = true;
	}
}



