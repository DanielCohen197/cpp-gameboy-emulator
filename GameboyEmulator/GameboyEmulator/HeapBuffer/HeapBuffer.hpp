#pragma once

#include <cstdint>
#include <memory>

class HeapBuffer
{
public:
	explicit HeapBuffer(const uint32_t size) :
		m_size(size),
		m_address(_s_heap_alloc(size))
	{}
	~HeapBuffer();

	HeapBuffer(const HeapBuffer&) = delete;
	HeapBuffer& operator=(HeapBuffer) = delete;

	uint32_t size() const { return m_size; }
	uint8_t* address() const { return m_address; }

private:
	static uint8_t* _s_heap_alloc(uint32_t size);

private:
	const uint32_t m_size;
	uint8_t* m_address;
};

using HeapBufferUPtr = std::unique_ptr<HeapBuffer>;