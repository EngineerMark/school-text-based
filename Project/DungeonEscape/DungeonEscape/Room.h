#pragma once
#include <vector>
#include <iostream>
#include "Door.h"
//#include "Enemy.h"
#include "Random.h"
#include "Message.h"
#include "Puzzle.h"

class Room
{
private:
	bool possible = false;
	Puzzle* leftPuzzle;
	Puzzle* rightPuzzle;
public:
	Room();
	~Room();
	//Enemy roomEnemy;
	std::vector<Door> doors;
	void DoorsMessage();
	void RebuildRoom();
	bool HasRoom() { return possible; };
};

