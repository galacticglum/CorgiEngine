#ifndef _ENGINE_MEMORY_MANAGER_H
#define _ENGINE_MEMORY_MANAGER_H

#include "../Engine.h"
#include "MemoryStats.h"

class MemoryManager
{
friend class MemoryAllocator;

public:
	MemoryManager() { }

	static void Quit();

	static MemoryManager* GetInstance();
	MemoryStats GetMemoryStats() const { return this->m_MemoryStats; }
private:
	static MemoryManager* s_Instance;
	MemoryStats m_MemoryStats;
};

#endif