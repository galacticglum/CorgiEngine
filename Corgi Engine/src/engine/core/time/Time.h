#ifndef _ENGINE_TIME_H
#define _ENGINE_TIME_H

#include "../../Engine.h"

class Time
{
friend class Game;

public:
	static double GetTime() { return (double)SDL_GetTicks() / 1000.0; }
	static float GetDeltaTime() { return m_DeltaTime; }

	static void Pause(uint32_t milliseconds) { SDL_Delay(milliseconds); }
private:
	static float m_DeltaTime;
};


#endif
