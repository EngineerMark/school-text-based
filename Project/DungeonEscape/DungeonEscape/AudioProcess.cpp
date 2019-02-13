#include "pch.h"
#include "AudioProcess.h"


AudioProcess::AudioProcess()
{
}


AudioProcess::~AudioProcess()
{
}

void AudioProcess::AudioLoop() {
	sys->playSound(sound, 0, false, &channel);
}

void AudioProcess::Loop()
{
	Process::Loop();

	Common_Init(&extradriverdata);
	res = FMOD::System_Create(&sys);
	ERRCHECK(res);

	res = sys->getVersion(&version);
	ERRCHECK(res);

	if (version < FMOD_VERSION) {
		Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	res = sys->init(32, FMOD_INIT_NORMAL, extradriverdata);
	ERRCHECK(res);

	res = sys->createSound(Common_MediaPath("Pepsi man song.mp3"),FMOD_DEFAULT,0,&sound);
	ERRCHECK(res);

	while (IsAlive()) {
		if (IsPaused())
			continue;
		if (IsDead())
			break;

		AudioLoop();
		if (game->IsQuitting() || GetState() == STATE_SUCCEEDED)
			break;
	}
	SetState(STATE_SUCCEEDED);
	Debug::Log("Input Thread loop finished");
}

void AudioProcess::OnUpdate(float deltaTime)
{
	SetState(STATE_RUNNING);
}

void AudioProcess::OnInit()
{
	Process::OnInit();
	try {
		thread = new std::thread(&AudioProcess::Loop, this);
	}
	catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		OnAbort();
		//return EXIT_FAILURE;
		return;
	}
}

void AudioProcess::OnAbort()
{
	Process::OnAbort();
	res = sound->release();
	ERRCHECK(res);
	res = sys->close();
	ERRCHECK(res); 
	res = sys->release();
	ERRCHECK(res);

	Common_Close();
}
