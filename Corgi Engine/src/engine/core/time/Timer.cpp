#include "Timer.h"

void Timer::Start()
{
	// We are already running, no need to start.
	if (this->m_Running)
	{
		return;
	}

	this->m_StartTime = Time::GetTime();
	this->m_Running = true;
	this->m_Paused = false;

	// Reset variables
	this->m_StopTime = 0;
	this->m_PausedTime = 0;
}

void Timer::Stop()
{
	// We aren't running, no need to stop.
	if (!this->m_Running)
	{
		return;
	}

	this->m_StopTime = Time::GetTime();
	this->m_Running = false;
	this->m_Paused = false;
}

void Timer::Restart()
{
	this->Stop();
	this->Start();
}

void Timer::Pause()
{
	// We aren't running or we are already paused, no need to pause the timer.
	if (!this->m_Running || this->m_Paused)
	{
		return;
	}

	this->m_Running = false;
	this->m_Paused = true;
	this->m_PausedTime = (Time::GetTime()) - this->m_StartTime;
}

void Timer::Unpause()
{
	// We aren't paused or we are already running, no need to unpause the timer.
	if (!this->m_Paused || this->m_Running)
	{
		return;
	}

	this->m_Running = true;
	this->m_Paused = false;

	this->m_StartTime = (Time::GetTime()) - this->m_PausedTime;
	this->m_PausedTime = 0;
}

uint32_t Timer::GetDeltaTime()
{
	if (this->m_Running)
	{
		return this->GetTime();
	}

	if (this->m_Paused)
	{
		return this->m_PausedTime;
	}

	if (this->m_StartTime == 0)
	{
		// This shouldn't happen!
		// TODO: Log this.
		return 0;
	}
}
