#pragma once
#include "Process.h"
class InputProcess: public Process
{
public:
	InputProcess();
	~InputProcess();
	void OnUpdate(float deltaTime) override;
	void OnInit() override;
	void OnAbort() override;
};

