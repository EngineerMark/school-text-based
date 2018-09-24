#include "pch.h"
#include "Random.h"
#include <cstdlib>
#include <ctime>


Random::Random()
{
}


Random::~Random()
{
}

int Random::RandomInt(int max) {
	std::srand(std::time(nullptr));
	return (std::rand() % max) + 1;
}