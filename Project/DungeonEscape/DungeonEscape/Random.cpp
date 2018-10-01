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
	return (std::rand() % max) + 1;
}