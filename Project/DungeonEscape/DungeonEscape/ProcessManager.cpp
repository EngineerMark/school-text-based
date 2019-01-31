#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <future>
#include "ProcessManager.h"
#include "RenderProcess.h"
#include "List.h"

typedef std::list<StrongProcessPtr> ProcessList;
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
			it++;
		}
	}
	processList->empty();
}

void ProcessManager::RegisterProcess(StrongProcessPtr process)
{
	//cout << "thread created" << endl;
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
		StrongProcessPtr p = (*it);
		/*if (p->thread == NULL)
			continue;*/

		if (p->IsDone()) {
			if (p->GetProcessType() == PROCESS_INPUT) {
				AbortAllProcesses(false);
			}
		}
		else if (p->IsAlive()) {
			p->OnUpdate(0);
			//std::cout << (*it) << " updated" << std::endl;
		}
		++it;
	}
	return ((successCount << 16) | failCount);
}

int ProcessManager::GetProcessCount() {
	return processList->size();
}

void ProcessManager::AbortAllProcesses(bool immediately)
{
	ProcessList::iterator it = processList->begin();
	ProcessList::iterator end = processList->end();
	if (immediately) {
		while (processList->end() != it) {
			if ((*it)->thread == NULL)
				continue;
			(*it)->OnAbort();
			processList->remove((*it));
			++it;
		}
	}
	else {
		while (processList->end() != it) {
			if ((*it)->thread == NULL)
				continue;
			(*it)->SetState(STATE_SUCCEEDED);
			processList->remove((*it));

			++it;
		}
	}
}
