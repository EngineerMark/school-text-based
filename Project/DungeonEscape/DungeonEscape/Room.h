#pragma once
#include <vector>
#include "Door.h"
class Room
{
public:
	Room();
	~Room();
	std::vector<Door> doors;
	void DoorsMessage();
	void RebuildRoom();
};

