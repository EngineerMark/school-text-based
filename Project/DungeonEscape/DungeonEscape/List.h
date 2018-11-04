#pragma once
#include <list>

template <class T>
class List
{
private:
	std::list<T*> _list;
	int index;
public:
	List();
	~List();
	T Begin();
	T End();
	T Next();
	void Remove(T*);
	void Add(T*);
};

