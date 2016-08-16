#ifndef _ENGINE_MEMORY_STATS_H
#define _ENGINE_MEMORY_STATS_H

#include "Types.h"

struct MemoryStats
{
	MemoryStats() : totalAllocated(0), totalFreed(0), currentUsage(0), totalAllocations(0) { }

	int totalAllocated;
	int totalFreed;
	int currentUsage;

	int totalAllocations;
};

#endif