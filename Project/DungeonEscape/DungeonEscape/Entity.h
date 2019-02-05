#pragma once
#include "LookDirection.h"

class Entity
{
protected:
	LookDirection lookDirection;
	int health;
public:
	Entity();
	~Entity();

	void RemoveHealth(int amount) {
		health -= amount;
	};

	int GetHealth() {
		return health;
	}
};

