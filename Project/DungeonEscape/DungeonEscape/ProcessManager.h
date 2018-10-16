#pragma once
#include <list>
#include <memory>
#include "Process.h"

typedef std::shared_ptr<Process> StrongProcessPtr;
typedef std::weak_ptr<Process> WeakProcessPtr;
typedef std::list<StrongProcessPtr> ProcessList;

class ProcessManager
{
public:
	static bool isRunning;
	ProcessList* processList;
	ProcessManager();
	~ProcessManager();
	void RegisterProcess(StrongProcessPtr process);
	unsigned int UpdateProcesses(float deltaTime);
	void AbortAllProcesses(bool immediately);
	int GetProcessCount();
};

