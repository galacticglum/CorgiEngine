#include "game/TestGame.h"
#include "engine/system/MemoryManager.h"
#include "engine/system/MemoryStats.h"

#include <iostream>

int main(int argc, char* argv[])
{
	std::string title = "Corgi Engine";
	TestGame game(800, 600, title, 60.0);

  MemoryStats memStats = MemoryManager::GetInstance()->GetMemoryStats();
  std::cerr << "Memory allocated: " << memStats.totalAllocated << "\n";
  std::cerr << "Memory freed: " << memStats.totalFreed << "\n";
  std::cerr << "Memory allocations: " << memStats.totalAllocations << "\n";
  std::cerr << "Unreleased memory: " << memStats.currentUsage << "\n";

	return 0;
}