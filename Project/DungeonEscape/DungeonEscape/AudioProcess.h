#pragma once
#include "fmod.hpp"
#include "common.h"
#include "Process.h"

class AudioProcess : public Process
{
private:
	FMOD::System* sys;
	FMOD::Sound* sound;
	FMOD::Channel* channel = 0;
	FMOD_RESULT res;
	unsigned int version;
	void* extradriverdata = 0;
public:
	AudioProcess();
	~AudioProcess();
	void Loop() override;
	void OnUpdate(float deltaTime) override;
	void OnInit() override;
	void OnAbort() override;
	void AudioLoop();
};

