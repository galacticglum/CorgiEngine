#include "Input.h"

Input* Input::m_Instance = nullptr;

Input* Input::GetInstance()
{
	if (!m_Instance)
	{
		m_Instance = new Input();
	}

	return m_Instance;
}

void Input::Update()
{
	for (int i = 0; i < KEYBOARD_SIZE; i++)
	{
		this->m_KeyDown[i] = false;
		this->m_KeyUp[i] = false;
	}

	for (int i = 0; i < MOUSE_MAX; i++)
	{
		this->m_MouseUp[i] = false;
		this->m_MouseDown[i] = false;
	}

	while (SDL_PollEvent(&this->m_Event))
	{
		switch (this->m_Event.type)
		{
		case SDL_KEYDOWN:
		{
			this->m_Keyboard = SDL_GetKeyboardState(nullptr);

			int scancode = this->m_Event.key.keysym.scancode;
			this->m_KeyDown[scancode] = true;
		}
		break;

		case SDL_KEYUP:
		{
			this->m_Keyboard = SDL_GetKeyboardState(nullptr);

			int scancode = this->m_Event.key.keysym.scancode;
			this->m_KeyUp[scancode] = true;
		}
		break;

		case SDL_MOUSEMOTION:
		{
			this->m_MouseX = this->m_Event.motion.x;
			this->m_MouseY = this->m_Event.motion.y;
		}
		break;

		case SDL_MOUSEBUTTONDOWN:
		{
			this->m_Mouse = SDL_GetMouseState(&(this->m_MouseX), &(this->m_MouseY));

			if (this->m_Event.button.button == SDL_BUTTON_LEFT)
			{
				this->m_MouseDown[MOUSE_LEFT] = true;
			}
			else if (this->m_Event.button.button = SDL_BUTTON_RIGHT)
			{
				this->m_MouseDown[MOUSE_RIGHT] = true;
			}
		}
		break;

		case SDL_MOUSEBUTTONUP:
		{
			this->m_Mouse = SDL_GetMouseState(&(this->m_MouseX), &(this->m_MouseY));

			if (this->m_Event.button.button = SDL_BUTTON_LEFT)
			{
				this->m_MouseUp[MOUSE_LEFT] = true;
			}
			else if (this->m_Event.button.button = SDL_BUTTON_RIGHT)
			{
				this->m_MouseUp[MOUSE_RIGHT] = true;
			}
		}
		break;

		case SDL_MOUSEWHEEL:
		{
			// TODO: Scrollwheel
			// if negative; scrolled to the right
			// if positive; scrolled to the left
			//this->m_Event.wheel.x;

			// if negative; scrolled to the down
			// if positive; scrolled to the up
			//this->m_Event.wheel.y;
		}
		break;

		default:
			break;
		}
	}
}

bool Input::GetKeyDown(int keyCode) const
{
	if (keyCode < 0 || keyCode >= KEYBOARD_SIZE)
	{
		return false;
	}

	return (this->m_KeyDown[keyCode]);
}

bool Input::GetKeyUp(int keyCode) const
{
	if (keyCode < 0 || keyCode >= KEYBOARD_SIZE)
	{
		return false;
	}

	return (this->m_KeyUp[keyCode]);
}

bool Input::GetKey(Key key) const
{
	if (!this->m_Keyboard)
	{
		return false;
	}

	int scancode = static_cast<int>(key);
	if (this->m_Keyboard[scancode])
	{
		return true;
	}
	return false;
}

bool Input::GetShift() const
{
	return(this->GetKey(KEY_LEFT_SHIFT) || this->GetKey(KEY_RIGHT_SHIFT));
}

bool Input::GetCtrl() const
{
	return(this->GetKey(KEY_LEFT_CTRL) || this->GetKey(KEY_RIGHT_CTRL));
}

bool Input::GetAlt() const
{
	return(this->GetKey(KEY_LEFT_ALT) || this->GetKey(KEY_RIGHT_ALT));
}

bool Input::GetMouseButtonDown(MouseButton button) const
{
	if (button == MOUSE_MAX)
	{
		return false;
	}

	return this->m_MouseDown[button];
}

bool Input::GetMouseButtonUp(MouseButton button) const
{
	if (button == MOUSE_MAX)
	{
		return false;
	}

	return this->m_MouseUp[button];
}

bool Input::GetMouseButton(MouseButton button) const
{
	switch (button)
	{
	case MOUSE_LEFT:
	{
		if (this->m_Mouse & SDL_BUTTON(1))
		{
			return true;
		}
	}
	break;

	case MOUSE_RIGHT:
	{
		if (this->m_Mouse & SDL_BUTTON(3))
		{
			return true;
		}
	}
	break;

	default:
		break;
	}

	return false;
}

bool Input::GetMouseOver(const Rectangle& rectangle) const
{
	if ((this->m_MouseX >= rectangle.GetPosition().X) && 
		(this->m_MouseX <= rectangle.GetPosition().X + rectangle.GetWidth()) && 
		(this->m_MouseY >= rectangle.GetPosition().Y) && 
	    (this->m_MouseY <= rectangle.GetPosition().Y + rectangle.GetHeight()))
	{
		return true;
	}
}

