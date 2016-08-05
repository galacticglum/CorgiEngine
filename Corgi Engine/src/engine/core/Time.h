#ifndef _ENGINE_TIME_H
#define _ENGINE_TIME_H

#include "..\Engine.h"

class Time
{
friend class Game;

public:
	static double GetTime();
	inline static double GetDeltaTime() { return m_DeltaTime; }

private:
	static double m_DeltaTime;
	inline static void SetDeltaTime(double deltaTime) { m_DeltaTime = deltaTime; }
};

#endif
