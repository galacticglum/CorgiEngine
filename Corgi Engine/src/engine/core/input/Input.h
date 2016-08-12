#ifndef _ENGINE_INPUT_H
#define _ENGINE_INPUT_H

#include "../../maths/Vector2.h"
#include "../../rendering/primitives/Rectangle.h"
#include "InputDefinitions.h"

class Input
{
public:
	static Input* GetInstance();

	Input() : m_Keyboard(nullptr), m_Mouse(0), m_MouseX(0), m_MouseY(0), m_CursorLocked(false) { }
	Input(const Input&) {};
	void operator=(const Input&) {};

	void Update();
	
	bool GetKeyDown(int keyCode) const;
	bool GetKeyUp(int keyCode) const;
	bool GetKey(Key key) const;
	// Helpers
	bool GetShift() const;
	bool GetCtrl() const;
	bool GetAlt() const;

	bool GetMouseButtonDown(MouseButton button) const;
	bool GetMouseButtonUp(MouseButton button) const;
	bool GetMouseButton(MouseButton button) const; 
	 
	Vector2 GetMousePosition() const { return Vector2((float)this->m_MouseX, (float)this->m_MouseY); }
	int GetMousePositionX() const { return this->GetMousePosition().X; }
	int GetMousePositionY() const { return this->GetMousePosition().Y; }

	void LockCursor() { this->m_CursorLocked = true; }
	void UnlockCursor() { this->m_CursorLocked = false; }

	void ShowCursor() { SDL_ShowCursor(true); }
	void HideCursor() { SDL_ShowCursor(false); }

	bool GetMouseOver(const Rectangle& rectangle) const;
private:
	static Input* m_Instance;

	SDL_Event m_Event;
	const uint8_t* m_Keyboard;
	uint32_t m_Mouse;
	int m_MouseX;
	int m_MouseY;

	bool m_KeyDown[KEYBOARD_SIZE];
	bool m_KeyUp[KEYBOARD_SIZE];
	bool m_MouseDown[MOUSE_MAX];
	bool m_MouseUp[MOUSE_MAX];

	bool m_CursorLocked;
};

#endif