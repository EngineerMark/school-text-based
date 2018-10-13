#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <future>
#include "ProcessManager.h"
#include "RenderProcess.h"

using namespace std;

typedef list<StrongProcessPtr> ProcessList;
//ProcessList processList;

ProcessManager::ProcessManager() {
	processList = new ProcessList();
}

ProcessManager::~ProcessManager() {

}

void ProcessManager::RegisterProcess(StrongProcessPtr process)
{
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

	return ((successCount << 16) | failCount);
}

int ProcessManager::GetProcessCount() {
	return processList->size();
}

void ProcessManager::AbortAllProcesses(bool immediately)
{
}
