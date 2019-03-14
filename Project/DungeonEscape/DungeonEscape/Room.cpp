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

	if (enemy != NULL && enemy->GetHealth()>0) {
		Message::Send("\n");
		Message::Send(" >> You are being attacked by an enemy");
	}
}

void Room::RebuildRoom() {
	possible = false;
	doors = std::vector<Door>();
	int doorAmount = Random::RandomInt(3) + 2;
	rightPuzzle = new Puzzle();
	leftPuzzle = new Puzzle();
	for (int i = 1; i <= doorAmount; i++)
	{
		Door door;
		doors.push_back(door);
		if (door.HasRoom) {
			possible = true;
			leftPuzzle->GenerateEquation(i);
			rightPuzzle->GenerateEquation(i);
		}
	}
	bool spawnEnemy = false;
	int randomize = Random::RandomInt(10);
	if (randomize <= 3) {
		spawnEnemy = true;
	}

	if (spawnEnemy) {
		enemy = NULL;
	}
	else {
		if (enemy != NULL)
			SAFE_DELETE(enemy);
	}
}