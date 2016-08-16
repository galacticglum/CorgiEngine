#ifndef _ENGINE_ALLOCATOR_H
#define _ENGINE_ALLOCATOR_H

#include "Types.h"

class MemoryAllocator
{
public:
	static void* Allocate(size_t size);
	static void Free(void* memoryBlock);
};

#endif