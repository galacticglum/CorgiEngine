#ifndef _ENGINE_MEMORY_H
#define _ENGINE_MEMORY_H

#include "MemoryAllocator.h"

#define cnew new
#define cdelete delete

void* operator new(size_t size)
{
	return MemoryAllocator::Allocate(size);
}

void* operator new[](size_t size)
{
	return MemoryAllocator::Allocate(size);
}

void operator delete(void* block)
{
	MemoryAllocator::Free(block);
}

void operator delete[](void* block)
{
	MemoryAllocator::Free(block);
}

#endif