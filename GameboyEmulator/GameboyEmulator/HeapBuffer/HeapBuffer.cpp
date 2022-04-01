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

uint8_t* HeapBuffer::s_heap_alloc_(const uint32_t size)
{
	const auto allocated_address = static_cast<uint8_t *>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size));
	if (nullptr == allocated_address)
	{
		throw std::runtime_error("HeapAlloc() failed");
	}

	return allocated_address;
}
