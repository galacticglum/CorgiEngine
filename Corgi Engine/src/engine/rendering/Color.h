#ifndef _ENGINE_COLOR_H
#define _ENGINE_COLOR_H

struct Color
{
	Color(float r, float g, float b) : Color(r, g, b, 255) {}
	Color(float r, float g, float b, float a) : R(r), G(g), B(b), A(a) { }

	float R, G, B, A;
};

#endif