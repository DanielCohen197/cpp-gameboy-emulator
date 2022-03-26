#pragma once
#include <string>

class EmulatorRunner
{
public:
	EmulatorRunner(const std::wstring& game_path) :
		m_game_path(game_path)
	{}

	~EmulatorRunner() = default;

	EmulatorRunner(const EmulatorRunner&) = delete;
	EmulatorRunner& operator=(EmulatorRunner) = delete;

	void run();

private:
	std::wstring m_game_path;
};
