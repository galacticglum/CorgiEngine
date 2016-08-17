#include "MemoryManager.h"

MemoryManager* MemoryManager::s_Instance = nullptr;

const float MemoryManager::GB_SIZE = 1024 * 1024 * 1024;
const float MemoryManager::MB_SIZE = 1024 * 1024;
const float MemoryManager::KB_SIZE = 1024;

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

std::string MemoryManager::BytesToString(int bytes)
{
	std::string result;
	if (bytes >= GB_SIZE)
	{
		result = std::to_string(bytes / GB_SIZE) + " Gigabytes";
	}
	else if (bytes >= MB_SIZE)
	{
		result = std::to_string(bytes / MB_SIZE) + " Megabytes";
	}
	else if (bytes >= KB_SIZE)
	{
		result = std::to_string(bytes / KB_SIZE) + " Kilobytes";
	}
	else
	{
		result = std::to_string((float)bytes) + " Bytes";
	}

	return result;
}