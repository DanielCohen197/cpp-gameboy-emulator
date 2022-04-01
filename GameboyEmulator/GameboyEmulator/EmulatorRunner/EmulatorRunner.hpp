#pragma once
#include <string>

class EmulatorRunner
{
public:
	EmulatorRunner(std::wstring game_path, std::wstring json_path) :
		m_game_path(std::move(game_path)),
		m_instruction_json_path(std::move(json_path))
	{}

	~EmulatorRunner() = default;

	EmulatorRunner(const EmulatorRunner&) = delete;
	EmulatorRunner& operator=(EmulatorRunner) = delete;

	void run();

private:
	std::wstring m_game_path;
	std::wstring m_instruction_json_path;
};
