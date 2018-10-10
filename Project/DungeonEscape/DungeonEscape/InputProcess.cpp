#include "pch.h"
#include <iostream>
#include "InputProcess.h"
#include "Process.h"


InputProcess::InputProcess()
{
	
}


InputProcess::~InputProcess()
{
}

void InputProcess::OnUpdate(float deltaTime)
{
	char buffer[100];

	std::cin >> buffer;

	std::cout << buffer << " - WOW WORKS!" << std::endl;
}

void InputProcess::OnInit()
{
	Process::OnInit();
}

void InputProcess::OnAbort()
{
	Process::OnAbort();
}
