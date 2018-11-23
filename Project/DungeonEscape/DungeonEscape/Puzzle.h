#pragma once
#include <cstdlib>

enum PuzzleType {
	PTYPE_MATH,
	PTYPE_KEY
};

class Puzzle
{
private:
	PuzzleType type;
public:
	Puzzle();
	~Puzzle();
	//void GrabKey(Inventory* inv);
};

