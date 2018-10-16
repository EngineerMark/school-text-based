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
	StateMachine()
	{
		currentState = nullptr;
		previousState = nullptr;
		Debug::Log("statemachine created");
	};
	~StateMachine(){};

	void ChangeState(State<T>* newState);
	void Update();
	State<T> GetState();
	void ReturnToPreviousState();
};

