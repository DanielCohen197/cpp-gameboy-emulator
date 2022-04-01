#pragma once

#include "MMU/MMU.hpp"
#include "Registers/Regsiters.hpp"
#include "ThirdParty/json.hpp"

class CPU
{
public:
	// TODO change to 0x100
	static constexpr uint8_t instruction_prefix = 0xCB;

	CPU(MMUUPtr&& MMU, const Registers& registers, std::unique_ptr<nlohmann::json>&& instruction_dictionaries) :
		m_registers(registers),
		m_MMU(std::move(MMU)),
		m_instruction_dictionaries(std::move(instruction_dictionaries))
	{}
	~CPU() = default;

	CPU(const CPU&) = delete;
	CPU& operator=(CPU) = delete;

	[[noreturn]] void run();

private:
	[[nodiscard]] nlohmann::json::value_type& get_next_instruction_();

	void fill_in_operands_(nlohmann::json::value_type& instruction);

	// Should be used for debugging purposes
	static void s_print_instruction_(nlohmann::json::value_type& instruction);

private:
	Registers m_registers;
	MMUUPtr m_MMU;
	std::unique_ptr<nlohmann::json> m_instruction_dictionaries;
};
