#pragma once
#include <string>
#include <vector>
#include "Composit.h"
#include "Component.h"
#include "Transform.h"

class GameObject : public Composite
{
private:
	std::string name;

	Component* transform;
public:
	GameObject() {
		transform = AddComponent<Transform>();
	};
};