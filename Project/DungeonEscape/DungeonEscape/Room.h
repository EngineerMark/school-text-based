#pragma once
#include <vector>
#include "Door.h"
#include "Enemy.h"
class Room
{
public:
	Room();
	~Room();
	Enemy roomEnemy;
	std::vector<Door> doors;
	void DoorsMessage();
	void RebuildRoom();
};

