#ifndef _ENGINE_INPUT_H
#define _ENGINE_INPUT_H

#include "../../maths/Vector2.h"
#include "../../rendering/primitives/Rectangle.h"
#include "InputDefinitions.h"
#include "../../rendering/Window.h"

class Input
{
public:
	Input(Window* window);
	~Input();

	bool GetKey(int mouseButton) const { return this->m_Keys[mouseButton]; }
	bool GetKeyDown(int mouseButton) const { return this->m_DownKeys[mouseButton]; }
	bool GetKeyUp(int mouseButton) const { return this->m_UpKeys[mouseButton]; }
	bool GetMouseButton(int mouseButton) const { return this->m_MouseButtons[mouseButton]; }
	bool GetMouseButtonDown(int mouseButton) const { return this->m_MouseButtonsDown[mouseButton]; }
	bool GetMouseButtonUp(int mouseButton) const { return this->m_MouseButtonsUp[mouseButton]; }

	Vector2 GetCursorPosition() const { return Vector2((float)this->m_MouseX, (float)this->m_MouseY); }
	int GetCursorPositionX() const { return this->m_MouseX; }
	int GetCursorPositionY() const { return this->m_MouseY; }

	void SetCursorPosition(Vector2& position) const { SDL_WarpMouseInWindow(m_Window->GetWindow(), (int)position.X, (int)position.Y); }
	void SetCursorPosition(int x, int y) const { SDL_WarpMouseInWindow(m_Window->GetWindow(), x, y); }

	void ShowCursor() { SDL_ShowCursor(1); }
	void HideCursor() { SDL_ShowCursor(0); }

	void Update(SDL_Event event);

private:
	bool m_Keys[KEY_COUNT];
	bool m_DownKeys[KEY_COUNT];
	bool m_UpKeys[KEY_COUNT];
	bool m_MouseButtons[MOUSE_BUTTON_COUNT];
	bool m_MouseButtonsDown[MOUSE_BUTTON_COUNT];
	bool m_MouseButtonsUp[MOUSE_BUTTON_COUNT];

	int m_MouseX;
	int m_MouseY;

	Window* m_Window;
};

#endif