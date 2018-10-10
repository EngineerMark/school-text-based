#pragma once
#include "State.h"
template <class T> class StateMachine
{
private:
	T* t;
	State<T> *previousState;
	State<T> *currentState;
public:
	StateMachine(T owner);
	~StateMachine();

	void ChangeState(State<T>* newState);
	void Update();
	State<T> GetState();
	void ReturnToPreviousState();
};

