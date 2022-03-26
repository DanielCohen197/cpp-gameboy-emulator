#include "EmulatorRunner/EmulatorRunner.hpp"

std::wstring game_path = L"..\\..\\Additional Items\\snake.gb";

int main()
{
	EmulatorRunner emulator_runner(game_path);
	emulator_runner.run();

	return 0;
}
