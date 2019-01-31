#include "pch.h"
#include "Puzzle.h"


Puzzle::Puzzle()
{
	type = PTYPE_MATH;

}


Puzzle::~Puzzle()
{
}

void Puzzle::GenerateEquation(float res)
{
	float t = res;

	//std::cout << puzzles[0] << std::endl;

	for (size_t i = 1; i < 10; i++)
	{
		if ((t / (float)i) == floor(t / (float)i)) {
			equation = "";
			break;
		}
	}
}
