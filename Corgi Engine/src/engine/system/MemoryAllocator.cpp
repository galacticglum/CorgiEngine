#include "MemoryAllocator.h"

#include <malloc.h>
#include "MemoryManager.h"

#define C_ALLOC(size) _aligned_malloc(size, 16)
#define C_FREE(block) _aligned_free(block);

void* MemoryAllocator::Allocate(size_t size)
{
	MemoryManager::GetInstance()->m_MemoryStats.TotalAllocated += size;
	MemoryManager::GetInstance()->m_MemoryStats.CurrentUsage += size;
	MemoryManager::GetInstance()->m_MemoryStats.TotalAllocations++;

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

	MemoryManager::GetInstance()->m_MemoryStats.TotalFreed += size;
	MemoryManager::GetInstance()->m_MemoryStats.CurrentUsage -= size;
	MemoryManager::GetInstance()->m_MemoryStats.TotalDeallocations++;

	C_FREE(memory);
}

/*

MemoryAllocator::Allocate: 0x00000276accb81b0
MemoryAllocator::Allocate: 0x00000276accc7e70
MemoryAllocator::Allocate: 0x00000276b307a5e0
MemoryAllocator::Allocate: 0x00000276b3075360
MemoryAllocator::Allocate: 0x00000276acce5910
MemoryAllocator::Allocate: 0x00000276acce4e10
MemoryAllocator::Allocate: 0x00000276b3075410
MemoryAllocator::Allocate: 0x00000276b3075500
MemoryAllocator::Allocate: 0x00000276acce5990
MemoryAllocator::Allocate: 0x00000276acd059f0
MemoryAllocator::Allocate: 0x00000276b3075e80
MemoryAllocator::Allocate: 0x00000276accbf810
MemoryAllocator::Allocate: 0x00000276acce5290
MemoryAllocator::Allocate: 0x00000276acce5a90
MemoryAllocator::Allocate: 0x00000276acd04e20
MemoryAllocator::Allocate: 0x00000276acce5c10
MemoryAllocator::Free: 0x00000276acce5c10
MemoryAllocator::Allocate: 0x00000276acce5c10
MemoryAllocator::Allocate: 0x00000276acd054e0
MemoryAllocator::Allocate: 0x00000276b3076950
MemoryAllocator::Allocate: 0x00000276acce4e90
MemoryAllocator::Free: 0x00000276acce5c10
MemoryAllocator::Allocate: 0x00000276acce4d10
MemoryAllocator::Free: 0x00000276acd059f0
MemoryAllocator::Free: 0x00000276acce5990
MemoryAllocator::Free: 0x00000276acd04e20
MemoryAllocator::Free: 0x00000276acce5a90
MemoryAllocator::Free: 0x00000276acce5290
MemoryAllocator::Free: 0x00000276accbf810
MemoryAllocator::Free: 0x00000276acd054e0
MemoryAllocator::Free: 0x00000276acce4e90
MemoryAllocator::Free: 0x00000276b3076950
MemoryAllocator::Free: 0x00000276acce4d10
MemoryAllocator::Free: 0x00000276b3075e80
MemoryAllocator::Free: 0x00000276b3075410
MemoryAllocator::Free: 0x00000276acce4e10
MemoryAllocator::Free: 0x00000276b3075360
MemoryAllocator::Free: 0x00000276acce5910
MemoryAllocator::Free: 0x00000276b307a5e0
MemoryAllocator::Free: 0x00000276accc7e70
MemoryAllocator::Free: 0x00000276b3075500
MemoryAllocator::Free: 0x00000276accb81b0


*/