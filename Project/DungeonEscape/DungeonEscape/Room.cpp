#include "pch.h"
#include "Room.h"
#include "Random.h"

#include <iostream>

Room::Room()
{
	RebuildRoom();
}

Room::~Room()
{
}

void Room::DoorsMessage() {
	std::cout << "In the room you are now, there exist " << doors.size() << " doors.\n";
}

void Room::RebuildRoom() {
	doors = std::vector<Door>();
	int doorAmount = Random::RandomInt(3) + 2;
	for (int i = 0; i < doorAmount; i++)
	{
		Door door;
		doors.push_back(door);
	}
	DoorsMessage();
}