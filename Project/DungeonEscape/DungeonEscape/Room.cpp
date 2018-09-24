#include "pch.h"
#include "Room.h"
#include "Random.h"

#include <iostream>

Room::Room()
{
	doors = std::list<Door>();
	int doorAmount = Random::RandomInt(5);
	for (int i = 0; i < doorAmount; i++)
	{
		Door door;
		doors.push_back(door);
	}
}

Room::~Room()
{
}

void Room::DoorsMessage() {
	std::cout << "In the room you are now, there exist " << doors.size() << " doors.\n";
}