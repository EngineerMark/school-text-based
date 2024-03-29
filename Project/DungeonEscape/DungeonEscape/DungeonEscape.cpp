#include "pch.h"
#include <ctime>
#include <thread>
#include <iostream>
#include "Game.h"
#include "Debug.h"
#include "ProcessManager.h"
#include "Process.h"
#include "AudioProcess.h"
#include "RenderProcess.h"
#include "InputProcess.h"

ProcessManager* processManager;
Game* game;

int main()
{
	std::srand((unsigned)std::time(0));
	game = new Game();
	processManager = new ProcessManager();

	//Audio Process
	StrongProcessPtr audioProcess = StrongProcessPtr(new AudioProcess());
	audioProcess->AppendGame(game);
	processManager->RegisterProcess(audioProcess);
	//Renderer Process
	StrongProcessPtr renderProcess = StrongProcessPtr(new RenderProcess());
	renderProcess->AppendGame(game);
	processManager->RegisterProcess(renderProcess);
	//Input Process
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