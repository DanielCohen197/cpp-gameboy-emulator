#pragma once

#include <cstdint>
#include <memory>

struct CartridgeHeader
{
	uint8_t start_code[0x4];
	uint8_t nintendo_logo[0x30];
	uint8_t game_title[0xB];
	uint8_t game_designation[0x4];
	uint8_t color_compatibility[0x1];
	uint8_t new_license_code[0x2];
	uint8_t sgb_compatibility[0x1];
	uint8_t cart_type[0x1];
	uint8_t rom_size[0x1];
	uint8_t ram_size[0x1];
	uint8_t destination_code[0x1];
	uint8_t old_license_code[0x1];
	uint8_t mask_rom_version[0x1];
	uint8_t complement_checksum[0x1];
	uint8_t checksum[0x2];
};

struct ROMBank0
{
	uint8_t vector_table[0x100];
	CartridgeHeader cartridge_header;
	uint8_t data[0xceb0];
};

union Cartridge
{
	struct ParsedCartridge
	{
		ROMBank0 bank_0;
		uint8_t switchable_banks[0x4000];
		uint8_t character_ram[0x1800];
		uint8_t bg_map_data_1[0x400];
		uint8_t bg_map_data_2[0x400];
		uint8_t cartridge_ram[0x2000];
		uint8_t internal_ram_bank_0[0x1000];
		uint8_t internal_ram_switchable_banks[0x1000];
		uint8_t echo_ram[0x1e00];
		uint8_t object_attribute_memory[0xa0];
		uint8_t unusable_memory[0x60];
		uint8_t io_registers[0x80];
		uint8_t zero_page[0x7f];
		uint8_t interrupt_enable_flag[0x1];
	} parsed_cartridge;
	uint8_t address_space[sizeof ParsedCartridge];
};

using CartridgeUPtr = std::unique_ptr<Cartridge>;