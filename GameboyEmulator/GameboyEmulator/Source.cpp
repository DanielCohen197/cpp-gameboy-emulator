#include "ThirdParty/json.hpp"
#include "EmulatorRunner/EmulatorRunner.hpp"

std::wstring game_path = L"..\\..\\Additional Items\\snake.gb";
std::wstring instruction_json_path = L"..\\..\\Additional Items\\instruction_json.json";

int main()
{
	EmulatorRunner emulator_runner(game_path, instruction_json_path);
	emulator_runner.run();

	return 0;
}
