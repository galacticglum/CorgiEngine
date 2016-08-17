#include "MemoryManager.h"

MemoryManager* MemoryManager::s_Instance = nullptr;

MemoryManager* MemoryManager::GetInstance()
{
	if (s_Instance == nullptr)
	{
		s_Instance = (MemoryManager*)malloc(sizeof(MemoryManager));
		s_Instance = new(s_Instance)MemoryManager();
	}
	return s_Instance;
}

void MemoryManager::Quit()
{
	free(s_Instance);
}