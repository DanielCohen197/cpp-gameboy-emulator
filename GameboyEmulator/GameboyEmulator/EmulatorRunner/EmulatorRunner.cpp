#include <fstream>

#include "EmulatorRunner.hpp"

#include <cassert>

#include "MMU/MMU.hpp"

void EmulatorRunner::run()
{
	auto game_file = std::make_unique<std::ifstream>(m_game_path);

	const MMU mmu(std::move(game_file));

	// Make sure the code starts with a NOP
	assert(0x0 == mmu.read_byte(0x100));
}
