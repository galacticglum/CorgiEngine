#include "Time.h"
#include "SDL/SDL.h"

double Time::m_DeltaTime;

double Time::GetTime()
{
	return SDL_GetTicks() / 1000.0;
}

