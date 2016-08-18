#ifndef _ENGINE_COLOR_H
#define _ENGINE_COLOR_H

#include "../Engine.h"

struct Color
{
	Color(Uint8 r, Uint8 g, Uint8 b) : Color(r, g, b, 255) {}
	Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : R(r), G(g), B(b), A(a) { }

	SDL_Color GetSDLColour() { return{ this->R, this->G, this->B, this->A }; }

	Uint8 R, G, B, A;
};

#endif