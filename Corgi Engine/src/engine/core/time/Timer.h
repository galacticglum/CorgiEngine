#ifndef _ENGINE_TIMER_H
#define _ENGINE_TIMER_H

#include "../../Engine.h"
#include "Time.h"

class Timer
{
public:
	Timer() : m_StartTime(0), m_StopTime(0), m_PausedTime(0), m_Running(0), m_Paused(0) { }
	
	void Start();
	void Stop();
	void Restart();

	void Pause();
	void Unpause();

	bool IsRunning() { return this->m_Running; }
	bool IsPaused() { return this->m_Paused; }

	uint32_t GetDeltaTime();
	uint32_t GetDeltaTime_MS() { return this->GetDeltaTime() % 1000; }
	uint32_t GetDeltaTime_S() { return this->GetDeltaTime() / 1000; }
	uint32_t GetTime() { return (Time::GetTime() - this->m_StartTime); }

private:
	uint32_t m_StartTime;
	uint32_t m_StopTime;
	uint32_t m_PausedTime;

	bool m_Running;
	bool m_Paused;
};

#endif