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

	static std::string BytesToString(int bytes);
private:
	static MemoryManager* s_Instance;
	MemoryStats m_MemoryStats;

	static const float GB_SIZE; 
	static const float MB_SIZE; 
	static const float KB_SIZE; 
};

#endif