#include "pch.h"
#include "Debug.h"
#include "StateMachine.h"

template <class T>
StateMachine<T>::StateMachine(T owner)
{
	this->owner = owner;
	previousState = nullptr;
	currentState = nullptr;
}

template <class T>
StateMachine<T>::~StateMachine()
{

}

template <class T>
void StateMachine<T>::Update() {
	if (currentState != nullptr)
		currentState.Execute(t);
}

template<class T>
void StateMachine<T>::ChangeState(State<T>* newState) {
	if (newState == nullptr) {
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
}

template<class T>
State<T> StateMachine<T>::GetState() {
	return currentState;
}

template<class T>
void StateMachine<T>::ReturnToPreviousState() {
	ChangeState(previousState);
}