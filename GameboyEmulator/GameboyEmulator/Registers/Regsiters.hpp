// ReSharper disable CppClangTidyClangDiagnosticNestedAnonTypes
#pragma once
#include <cstdint>

enum Flags
{
	carry_flag = 1 << 4,
	half_carry_flag = 1 << 5,
	subtraction_flag = 1 << 6,
	zero_flag = 1 << 7,
};

struct Registers
{
	union
	{
		struct
		{
			uint8_t F;
			uint8_t A;
		};
		uint16_t AF;
	};
	union
	{
		struct
		{
			uint8_t C;
			uint8_t B;
		};
		uint16_t BC;
	};
	union
	{
		struct
		{
			uint8_t E;
			uint8_t D;
		};
		uint16_t DE;
	};
	union
	{
		struct
		{
			uint8_t L;
			uint8_t H;
		};
		uint16_t HL;
	};
	uint16_t SP;
	// Programs start at 0x100 by default
	uint16_t PC = 0x100;
};
