#include "MemoryAllocator.h"

#include <malloc.h>
#include "MemoryManager.h"

#define C_ALLOC(size) _aligned_malloc(size, 16)
#define C_FREE(block) _aligned_free(block);

void* MemoryAllocator::Allocate(size_t size)
{
	MemoryManager::GetInstance()->m_MemoryStats.totalAllocated += size;
	MemoryManager::GetInstance()->m_MemoryStats.currentUsage += size;
	MemoryManager::GetInstance()->m_MemoryStats.totalAllocations++;

	size_t memorySize = size + sizeof(size_t);
	uint8_t* memory = (uint8_t*)C_ALLOC(memorySize);
	memset(memory, 0, memorySize);
	memcpy(memory, &memorySize, sizeof(size_t));
	memory += sizeof(size_t);
	return memory;
}

void MemoryAllocator::Free(void* block)
{
	uint8_t* memory = ((uint8_t*)block) - sizeof(size_t);
	size_t size = (size_t)*memory;

	MemoryManager::GetInstance()->m_MemoryStats.totalFreed += size;
	MemoryManager::GetInstance()->m_MemoryStats.currentUsage -= size;
	MemoryManager::GetInstance()->m_MemoryStats.totalDeallocated++;

	C_FREE(memory);
}