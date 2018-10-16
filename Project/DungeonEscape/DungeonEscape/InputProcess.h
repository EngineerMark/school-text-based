#pragma once
#include "Game.h"
#include "Process.h"
class InputProcess: public Process
{
private:
	Game* game;
public:
	InputProcess();
	~InputProcess();
	void Loop() override;
	void OnUpdate(float deltaTime) override;
	void OnInit() override;
	void OnAbort() override;
};

