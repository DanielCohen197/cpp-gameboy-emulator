#include "Utils/HexUtils.hpp"
#include "CPU.hpp"

#include <iostream>

void CPU::run()
{
	while (true)
	{
		nlohmann::json::value_type& instruction = get_next_instruction_();

		fill_in_operands_(instruction);

		s_print_instruction_(instruction);
	}
}

nlohmann::json::value_type& CPU::get_next_instruction_()
{
	nlohmann::json& instruction_dictionary = (*m_instruction_dictionaries)["unprefixed"];

	uint8_t opcode = m_MMU->read_byte(m_registers.PC);
	(m_registers.PC)++;

	// Some of the opcodes are prefixed, so get the opcode after after the prefix
	if (instruction_prefix == opcode)
	{
		opcode = m_MMU->read_byte(m_registers.PC);
		(m_registers.PC)++;

		instruction_dictionary = (*m_instruction_dictionaries)["cbprefixed"];
	}

	const auto instruction_string = HexUtils::number_to_string(opcode);

	return instruction_dictionary[instruction_string];
}

void CPU::fill_in_operands_(nlohmann::json::value_type& instruction)
{
	for (auto& operand : instruction["operands"])
	{
		if (operand.contains("bytes"))
		{
			const auto byte_count = operand["bytes"].get<uint8_t>();
			uint16_t value;

			switch (byte_count)
			{
			case 1:
				value = m_MMU->read_byte(m_registers.PC);
				break;
			case 2:
				value = m_MMU->read_word(m_registers.PC);
				break;
			default:
				throw std::runtime_error("Unknown bytes count in operand");
			}
			m_registers.PC += byte_count;
			operand["value"] = value;
		}
	}
}

void CPU::s_print_instruction_(nlohmann::json::value_type& instruction)
{
	std::cout << instruction["mnemonic"].get<std::string>() << "\t\t";

	for (auto& operand : instruction["operands"])
	{
		if (operand.contains("value"))
		{
			std::cout << "0x" << std::uppercase << std::hex << operand["value"].get<uint16_t>() << "\t";
		}
		else
		{
			std::cout << operand["name"].get<std::string>() << "\t";
		}
	}

	std::cout << std::endl;
}
