#include "pch.h"
#include <iostream>
#include "InputProcess.h"
#include "Process.h"


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
}

void InputProcess::OnUpdate(float deltaTime)
{
	SetState(STATE_RUNNING);
}

void InputProcess::OnInit()
{
	Process::OnInit();
	game = new Game();
	/*Function* func = OnUpdate;
	Thread* tprocessThread = new Thread(func);*/
	thread = new std::thread(&InputProcess::Loop,this);
}

void InputProcess::OnAbort()
{
	Process::OnAbort();
}
