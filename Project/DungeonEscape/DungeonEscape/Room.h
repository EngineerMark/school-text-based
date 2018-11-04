#pragma once
#include <vector>
#include "Door.h"
#include "Enemy.h"
#include "Random.h"
#include <iostream>
class Room
{
private:
	bool possible = false;
public:
	Room();
	~Room();
	Enemy roomEnemy;
	std::vector<Door> doors;
	void DoorsMessage();
	void RebuildRoom();
	bool HasRoom() { return possible; };
};

