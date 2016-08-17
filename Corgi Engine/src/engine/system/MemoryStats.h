#ifndef _ENGINE_MEMORY_STATS_H
#define _ENGINE_MEMORY_STATS_H

#include "Types.h"

struct MemoryStats
{
	MemoryStats() : TotalAllocated(0), TotalFreed(0), CurrentUsage(0), TotalAllocations(0), TotalDeallocations(0) { }

	int TotalAllocated;
	int TotalDeallocations;
	int TotalFreed;
	int CurrentUsage;

	int TotalAllocations;
};

#endif