#include "pch.h"
#include "Random.h"
#include <cstdlib>


Random::Random()
{
}


Random::~Random()
{
}

int Random::RandomInt(int max) {
	return (std::rand() % max) + 1;
}