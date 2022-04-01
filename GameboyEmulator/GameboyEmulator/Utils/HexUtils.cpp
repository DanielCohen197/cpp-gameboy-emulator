#include <sstream>

#include "HexUtils.hpp"

std::string HexUtils::number_to_string(const uint8_t number)
{
	std::ostringstream instruction_string;
	instruction_string << "0x" << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << static_cast<uint16_t>(number);

	return instruction_string.str();
}