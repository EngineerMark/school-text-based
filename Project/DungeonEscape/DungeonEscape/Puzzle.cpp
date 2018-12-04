#include "pch.h"
#include "Puzzle.h"


Puzzle::Puzzle()
{
	type = PuzzleType(rand() % 3);
}


Puzzle::~Puzzle()
{
}

void Puzzle::VisualizePuzzle() {

}
