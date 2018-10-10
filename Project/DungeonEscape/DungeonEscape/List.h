#pragma once
template <class T>
class List
{
public:
	List();
	~List();
	T Begin();
	T End();
	T Next();
	void Remove();
	void Add(T* t);
};

