#include "MMU.hpp"

#include "CartridgeStructs.hpp"

uint8_t MMU::read_byte(const uint32_t address) const
{
	if (m_memory_buffer->size() < address)
	{
		throw std::runtime_error("Address given out of address space");
	}
	return m_memory_buffer->address()[address];
}

HeapBufferUPtr MMU::_s_read_cartridge(std::unique_ptr<std::ifstream>&& game_file)
{
	auto memory = std::make_unique<HeapBuffer>(sizeof Cartridge);
	game_file->read(reinterpret_cast<char *>(memory->address()), memory->size());

	return memory;
}
