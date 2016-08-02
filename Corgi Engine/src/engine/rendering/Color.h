#ifndef _ENGINE_COLOR_H
#define _ENGINE_COLOR_H

struct Color
{
public:
	Color(float r, float g, float b) : Color(r, g, b, 255) {}
	Color(float r, float g, float b, float a);
};

#endif