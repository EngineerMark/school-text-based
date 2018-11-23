#pragma once
#include "Room.h"
#include "LookDirection.h"

class Entity
{
protected:
	LookDirection lookDirection;
	int health;
	Room* location;
public:
	Entity();
	~Entity();

	void RemoveHealth(int amount) {
		health -= amount;
	};

	int GetHealth() {
		return health;
	}

	void SetRoom(Room* room) {
		this->location = room;
	}

	Room* GetRoom() {
		return location;
	}
};

