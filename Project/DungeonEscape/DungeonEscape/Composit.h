#pragma once
#include "Component.h"
#include <vector>
#include <cstdarg>

class Composite : public Component
{
private:
	std::vector<Component*> components;
public:
	Composite() {

	};
	~Composite() {

	};
	
	void Update() override {
		Component::Update();
	};

	template <class T>
	T* AddComponent() {
		if (!std::is_base_of<Component, T>::value)
			return nullptr;

		T* t = new T();
		components.push_back(t);

		return t;
	}

	Component* AddComponent(Component* component) {
		components.push_back(component);
		return component;
	}

	template <class T>
	T* GetComponent() {
		if (!std::is_base_of<Component, T>::value)
			return nullptr;

		for (size_t i = 0; i < components.size(); i++)
		{
			if (typeid(T) == typeid(components[i]))
				return reinterpret_cast<T*>(components[i]);
		}

		return nullptr;
	}
	
	/*template <class T>
	T* AddComponent(T* c) { 
		if (std::is_base_of<Component, T>::value))
			return nullptr;

		

		return default(T); 
	};

	template <class T>
	T* GetComponent() {
		for (size_t i = 0; i < components.size; i++)
		{

		}
	};*/
};

