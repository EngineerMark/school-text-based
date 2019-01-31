#pragma once
#include "fmod.hpp"
#include "Process.h"

class AudioProcess : public Process
{
public:
	AudioProcess();
	~AudioProcess();
	void Loop() override;
	void OnUpdate(float deltaTime) override;
	void OnInit() override;
	void OnAbort() override;
};

