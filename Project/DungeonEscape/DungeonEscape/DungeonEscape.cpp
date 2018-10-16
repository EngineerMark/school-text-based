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

void GameThread(Game game) {
	game.Loop();
}

int main()
{
	std::srand((unsigned)std::time(0));
	//Game game;

	processManager = new ProcessManager();

	StrongProcessPtr renderProcess = StrongProcessPtr(new RenderProcess());
	processManager->RegisterProcess(renderProcess);
	StrongProcessPtr inputProcess = StrongProcessPtr(new InputProcess());
	processManager->RegisterProcess(inputProcess);

	while (true) {
		int err = processManager->UpdateProcesses(0);
		if (processManager->GetProcessCount() == 0) {
			break;
		}
	}

	return 0;
}