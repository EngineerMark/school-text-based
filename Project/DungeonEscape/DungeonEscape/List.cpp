#include "pch.h"
#include "List.h"
#include <list>

template <class T>
List<T>::List()
{
	_list = new std::list<T*>();
}

template <class T>
List<T>::~List()
{
	_list->clear();
	SAFE_DELETE(_list);
}

template <class T>
void List<T>::Add(T* t) {
	_list->push_back(t);
}

template <class T>
void List<T>::Remove(T* t) {
	//_list->remove(t);
	_list->remove();
}

template <class T>
T* List<T>::Next() {
	if (index < _list->size()) {
		index++;
		return _list[index];
	}
}

template <class T>
T* List<T>::Begin() {
	index = 0;
	return _list[index];
}

template <class T>
T* List<T>::End() {
	index = _list->size();
	return _list[index];
}