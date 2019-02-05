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
	//std::cout << puzzles.at(0) << std::endl;

	float randomDivision = Random::RandomInt((int)res);
	float otherHalf = res / randomDivision;
	equation = std::to_string(otherHalf) + "x" + std::to_string(randomDivision);
	//std::cout << equation << std::endl;
}
