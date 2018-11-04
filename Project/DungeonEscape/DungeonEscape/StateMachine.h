#pragma once
#include <iostream>
#include "Debug.h"
#include "State.h"

template <class T> class StateMachine
{
private:
	T* t;
	State<T> *previousState;
	State<T> *currentState;
public:
	StateMachine(T* t)
	{
		this->t = t;
		currentState = nullptr;
		previousState = nullptr;
	};

	~StateMachine()
	{
		SAFE_DELETE(t);
	};

	void ChangeState(State<T>* newState) {
		if (!newState) {
			Debug::ErrorLog("StateMachine: newState doesn't exist");
			return;
		}
		if (previousState != nullptr) {
			currentState->Exit(t);
			previousState = nullptr;
			previousState = currentState;
		}
		currentState = newState;
		currentState->Enter(t);
		Debug::Log("Entered new state");
	};

	void Update() {
		if (currentState != nullptr)
			currentState->Execute(t);
	};

	State<T>* GetState() {
		return currentState;
	};

	void ReturnToPreviousState() {
		ChangeState(previousState);
	}
};

