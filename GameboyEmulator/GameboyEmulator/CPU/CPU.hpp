#pragma once

#include "MMU/MMU.hpp"
#include "ThirdParty/json.hpp"

class CPU
{
public:
	// TODO change to 0x100
	const uint32_t start_address = 0x150;
	const uint8_t instruction_prefix = 0xCB;

	CPU(MMUUPtr&& MMU, std::unique_ptr<nlohmann::json>&& instruction_dictionaries) :
		m_MMU(std::move(MMU)),
		m_instruction_dictionaries(std::move(instruction_dictionaries)),
		m_instruction_pointer(start_address)
	{}
	~CPU() = default;

	CPU(const CPU&) = delete;
	CPU& operator=(CPU) = delete;

	[[noreturn]] void run();

private:
	nlohmann::json::value_type& get_next_instruction_();

	void fill_in_operands_(nlohmann::json::value_type& instruction);

	// Should be used for debugging purposes
	static void s_print_instruction_(nlohmann::json::value_type& instruction);

private:
	MMUUPtr m_MMU;
	std::unique_ptr<nlohmann::json> m_instruction_dictionaries;
	uint32_t m_instruction_pointer;
};
