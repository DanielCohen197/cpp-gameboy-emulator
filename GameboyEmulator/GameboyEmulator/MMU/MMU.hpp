#pragma once

#include <fstream>

#include "HeapBuffer/HeapBuffer.hpp"

class MMU
{
public:
	explicit MMU(std::unique_ptr<std::ifstream>&& game_file) :
		m_memory_buffer(s_read_cartridge_(std::move(game_file)))
	{}
	~MMU() = default;

	MMU(const MMU&) = delete;
	MMU& operator=(MMU) = delete;

	// TODO add a read_sized template function
	[[nodiscard]] uint8_t read_byte(const uint32_t address) const;
	[[nodiscard]] uint16_t read_word(const uint32_t address) const;

private:
	[[nodiscard]] static HeapBufferUPtr s_read_cartridge_(std::unique_ptr<std::ifstream>&& game_file);

private:
	HeapBufferUPtr m_memory_buffer;
	// CartridgeUPtr m_cartridge;
};

using MMUUPtr = std::unique_ptr<MMU>;
