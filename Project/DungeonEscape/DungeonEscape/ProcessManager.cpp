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
	if (processList->size() > 0) {
		ProcessList::iterator it = processList->begin();
		ProcessList::iterator end = processList->end();
		while (it != end) {
			StrongProcessPtr p = (*it);
			p->OnAbort();
			SAFE_DELETE(p->thread);
			it++;
		}
	}
	processList->empty();
	SAFE_DELETE(processList);
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
			if ((*it)->IsAlive()) {
				p->OnUpdate(0);
			}
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
	if (immediately) {
		ProcessList::iterator it = processList->begin();
		ProcessList::iterator end = processList->end();
		while (processList->end() != it) {
			(*it)->OnAbort();
			++it;
		}
	}
}
