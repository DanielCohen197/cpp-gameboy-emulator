#include <Windows.h>
#include <stdexcept>

#include "HeapBuffer.hpp"

HeapBuffer::~HeapBuffer()
{
	try
	{
		HeapFree(GetProcessHeap(), 0, m_address);
	}
	catch (...) {}
}

uint8_t* HeapBuffer::_s_heap_alloc(const uint32_t size)
{
	const auto allocated_address = reinterpret_cast<uint8_t *>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size));
	if (nullptr == allocated_address)
	{
		throw std::runtime_error("HeapAlloc() failed");
	}

	return allocated_address;
}
