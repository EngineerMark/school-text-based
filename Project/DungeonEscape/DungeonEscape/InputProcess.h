#pragma once
#include <iostream>
#include "Game.h"
#include "Process.h"
#include "Debug.h"
class InputProcess: public Process
{
public:
	InputProcess();
	~InputProcess();
	void Loop() override;
	void OnUpdate(float deltaTime) override;
	void OnInit() override;
	void OnAbort() override;
};

