#pragma once
#include <thread>

typedef std::thread Thread;

enum ProcessState {
	STATE_UNINITIALISED,
	STATE_RUNNING,
	STATE_PAUSED,
	STATE_REMOVED,
	STATE_FAILED,
	STATE_SUCCEEDED,
	STATE_ABORT,
};

class Process
{
private:
	ProcessState state;
	//friend class ProcessManager;
public:
	Thread* processThread;

	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnInit() { state = STATE_RUNNING; };
	virtual void OnAbort() { state = STATE_ABORT; };

	ProcessState GetState() const { return state; };
	void SetState(ProcessState state) { this->state = state; };

	bool IsAlive() const { return state == STATE_RUNNING || state == STATE_PAUSED; };
	bool IsDead() const { return state == STATE_REMOVED || state == STATE_FAILED || state == STATE_ABORT; };
	bool IsRemoved() const { return state == STATE_REMOVED; };
	bool IsPaused() const { return state == STATE_PAUSED; };
	bool IsDone() const { return state == STATE_SUCCEEDED; };
};