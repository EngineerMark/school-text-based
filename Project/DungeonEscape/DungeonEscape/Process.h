#pragma once
#include <thread>
#include "Game.h"
//#include "Thread.h"

enum ProcessState {
	STATE_UNINITIALISED,
	STATE_RUNNING,
	STATE_PAUSED,
	STATE_REMOVED,
	STATE_FAILED,
	STATE_SUCCEEDED,
	STATE_ABORT,
};


enum ProcessType {
	PROCESS_INPUT,
	PROCESS_VULKAN
};

class Process
{
private:
	ProcessState state;
	ProcessType processType;
	//friend class ProcessManager;
protected:
	Game* game;
public:
	std::thread* thread;
	virtual void Loop() {};
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnInit() { state = STATE_PAUSED; };
	virtual void OnAbort() { state = STATE_ABORT; SAFE_DELETE(thread); };

	ProcessState GetState() const { return state; };
	void SetState(ProcessState state) { this->state = state; };

	ProcessType GetProcessType() const { return processType; };
	void SetProcessType(ProcessType type) { this->processType = type; };

	bool IsAlive() const { return state == STATE_RUNNING || state == STATE_PAUSED; };
	bool IsDead() const { return state == STATE_REMOVED || state == STATE_FAILED || state == STATE_ABORT; };
	bool IsRemoved() const { return state == STATE_REMOVED; };
	bool IsPaused() const { return state == STATE_PAUSED; };
	bool IsDone() const { return state == STATE_SUCCEEDED; };

	void AppendGame(Game* game) {
		this->game = game;
	}
};