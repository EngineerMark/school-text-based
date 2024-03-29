#pragma once
#include <vector>
#include <iostream>
#include "Door.h"
#include "Random.h"
#include "Message.h"
#include "Puzzle.h"
#include "Enemy.h"

class Room
{
private:
	bool possible = false;
	Puzzle* leftPuzzle;
	Puzzle* rightPuzzle;
	Enemy* enemy = NULL;
public:
	Room();
	~Room();
	std::vector<Door> doors;
	void DoorsMessage();
	void RebuildRoom();
	bool HasRoom() { return possible; };

	Puzzle* GetLeftPuzzle() { return leftPuzzle; };
	Puzzle* GetRightPuzzle() { return rightPuzzle; };
	Enemy* GetEnemy() { return enemy; };
};

