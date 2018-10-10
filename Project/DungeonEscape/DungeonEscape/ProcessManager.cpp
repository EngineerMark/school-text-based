#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <future>
#include "ProcessManager.h"
#include "RenderProcess.h"

using namespace std;

typedef list<StrongProcessPtr> ProcessList;
typedef list<Thread*> ThreadList;
//ProcessList processList;

ProcessManager::ProcessManager() {
	processList = new ProcessList();
	/*Process* renderProcess = new RenderProcess();
	renderProcess->OnInit();
	processList->push_back(renderProcess);*/
}

ProcessManager::~ProcessManager() {

}

struct P {
	static void Update(Process* process, float deltaTime) {
		if (process->IsAlive()) {
			process->OnUpdate(deltaTime);
			cout << "UPDATEEEEEE" << endl;
		}
	}
};

void ProcessManager::RegisterProcess(StrongProcessPtr process)
{
	//process->processThread = new Thread(P::Update, process, 0);
	cout << "thread created" << endl;
	process->OnInit();
	processList->push_back(process);
}


unsigned int ProcessManager::UpdateProcesses(float deltaTime)
{
	unsigned short int successCount = 0;
	unsigned short int failCount = 0;

	ProcessList::iterator it = processList->begin();
	ProcessList::iterator end = processList->end();
	while (processList->end() != it) {
		if (_kbhit()) {
			StrongProcessPtr p = (*it);
			p->OnUpdate(0);
			++it;
		}
	}

	/*ThreadList threadList;

	for (it = processList->begin(); it != end; it++)
	{
		if ((*it)->IsDead()) {
			(*it)->processThread->join();
		}
	}*/

	return ((successCount << 16) | failCount);
}

int ProcessManager::GetProcessCount() {
	return processList->size();
}

void ProcessManager::AbortAllProcesses(bool immediately)
{
}
