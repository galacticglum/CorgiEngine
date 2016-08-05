#ifndef _ENGINE_SPRITE_H
#define _ENGINE_SPRITE_H

#include "../Engine.h"
#include "Color.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	void Load(const std::string &fileName);
	void SetTint(float r, float g, float b);
	void SetTint(float r, float g, float b, float a);
	void SetTint(Color &color);

	void Draw();

	inline SDL_Rect GetRect() { return m_Rect; }
private:
	SDL_Rect m_Rect;
};

#endif