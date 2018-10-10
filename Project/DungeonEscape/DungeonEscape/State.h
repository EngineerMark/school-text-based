#pragma once
template<class T> class State
{
public:
	State();
	~State();

	virtual void Enter(T* t) {};
	virtual void Execute(T* t) {};
	virtual void Exit(T* t) {};
};

