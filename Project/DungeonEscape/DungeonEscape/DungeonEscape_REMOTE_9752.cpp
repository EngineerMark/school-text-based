#include "pch.h"
#include <ctime>
#include <thread>
#include <iostream>
#include "Game.h"
#include "Debug.h"
#include "ProcessManager.h"
#include "Process.h"
#include "RenderProcess.h"
#include "InputProcess.h"

ProcessManager* processManager;
Game* game;

int main()
{
	game = new Game();
	std::srand((unsigned)std::time(0));
	//Game game;

	processManager = new ProcessManager();

	StrongProcessPtr renderProcess = StrongProcessPtr(new RenderProcess());
	renderProcess->AppendGame(game);
	processManager->RegisterProcess(renderProcess);
	StrongProcessPtr inputProcess = StrongProcessPtr(new InputProcess());
	inputProcess->AppendGame(game);
	processManager->RegisterProcess(inputProcess);

	while (true) {
		int err = processManager->UpdateProcesses(0);
		if (processManager->GetProcessCount() == 0) {
			break;
		}
	}

	SAFE_DELETE(processManager);
	SAFE_DELETE(game);

	return 0;
}

void limit_fps(int fps) {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
}