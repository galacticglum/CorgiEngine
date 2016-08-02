#include "Time.h"

double Time::m_DeltaTime;

double Time::GetTime()
{
	return SDL_GetTicks() / 1000.0;
}

