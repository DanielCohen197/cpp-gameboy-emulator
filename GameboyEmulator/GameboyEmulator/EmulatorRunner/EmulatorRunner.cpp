#include <fstream>

#include "EmulatorRunner.hpp"

#include <cassert>
#include <iostream>

#include "CPU/CPU.hpp"
#include "MMU/MMU.hpp"
#include "ThirdParty/json.hpp"

void EmulatorRunner::run()
{
	auto game_file = std::make_unique<std::ifstream>(m_game_path, std::ios::binary);
	auto mmu = std::make_unique<MMU>(std::move(game_file));

	std::ifstream instruction_file(m_instruction_json_path);
	nlohmann::json instruction_dictionaries;
	instruction_file >> instruction_dictionaries;

	// Make sure the code starts with a NOP
	assert(0x0 == mmu->read_byte(0x100));
	
	CPU cpu(std::move(mmu), std::make_unique<nlohmann::json>(instruction_dictionaries));
	cpu.run();
}
