#pragma once
#include <list>
#include "Door.h"
class Room
{
public:
	Room();
	~Room();
	std::list<Door> doors;
	void DoorsMessage();
};

