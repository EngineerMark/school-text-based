#include "pch.h"
#include "InputProcess.h"

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
	try {
		thread = new std::thread(&InputProcess::Loop, this);
	}
	catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		OnAbort();
		return;
	}

}

void InputProcess::OnAbort()
{
	Process::OnAbort();
}
