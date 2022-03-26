#pragma once

#include <fstream>

#include "HeapBuffer/HeapBuffer.hpp"

class MMU
{
public:
	explicit MMU(std::unique_ptr<std::ifstream>&& game_file) :
		m_memory_buffer(_s_read_cartridge(std::move(game_file)))
	{}
	~MMU() = default;

	MMU(const MMU&) = delete;
	MMU& operator=(MMU) = delete;

	uint8_t read_byte(const uint32_t address) const;

private:
	static HeapBufferUPtr _s_read_cartridge(std::unique_ptr<std::ifstream>&& game_file);

private:
	HeapBufferUPtr m_memory_buffer;
	// CartridgeUPtr m_cartridge;
};
