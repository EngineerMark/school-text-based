#include "pch.h"
#include "AudioProcess.h"


AudioProcess::AudioProcess()
{
}


AudioProcess::~AudioProcess()
{
}

void AudioProcess::Loop()
{
	Process::Loop();
}

void AudioProcess::OnUpdate(float deltaTime)
{
}

void AudioProcess::OnInit()
{
	Process::OnInit();
}

void AudioProcess::OnAbort()
{
	Process::OnAbort();
}
