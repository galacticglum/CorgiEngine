#include "MemoryAllocator.h"

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
