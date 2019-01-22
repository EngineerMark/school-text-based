#include "pch.h"
#include <iostream>
#include "InputProcess.h"
#include "Process.h"
#include "Debug.h"

InputProcess::InputProcess()
{
	SetProcessType(PROCESS_INPUT);
}


InputProcess::~InputProcess()
{
}

void InputProcess::Loop() {
	Process::Loop();
	while (IsAlive()) {
		if (IsPaused())
			continue;
		if (IsDead())
			break;

		//char buffer[100];
		////std::cout << "InputProcess" << std::endl;

		//std::cin >> buffer;

		//std::cout << buffer << " - WOW WORKS!" << std::endl;
		game->Loop();
		if (game->IsQuitting() || GetState()==STATE_SUCCEEDED)
			break;
	}
	SetState(STATE_SUCCEEDED);
	Debug::Log("Input Thread loop finished");
}

void InputProcess::OnUpdate(float deltaTime)
{
	SetState(STATE_RUNNING);
}

void InputProcess::OnInit()
{
	Process::OnInit();
	/*Function* func = OnUpdate;
	Thread* tprocessThread = new Thread(func);*/
	try {
		thread = new std::thread(&InputProcess::Loop, this);
	}
	catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		OnAbort();
		//return EXIT_FAILURE;
		return;
	}

}

void InputProcess::OnAbort()
{
	Process::OnAbort();
}
