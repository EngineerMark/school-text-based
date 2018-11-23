#include "pch.h"
#include "Room.h"

Room::Room()
{
	RebuildRoom();
}

Room::~Room()
{
	SAFE_DELETE(leftPuzzle);
	SAFE_DELETE(rightPuzzle);
}

void Room::DoorsMessage() {
	std::cout << "In the room you are now, there exist " << doors.size() << " doors.\n";
}

void Room::RebuildRoom() {
	possible = false;
	doors = std::vector<Door>();
	int doorAmount = Random::RandomInt(3) + 2;
	for (int i = 0; i < doorAmount; i++)
	{
		Door door;
		doors.push_back(door);
		if (door.HasRoom) {
			possible = true;
		}
	}

	rightPuzzle = new Puzzle();
	leftPuzzle = new Puzzle();
}