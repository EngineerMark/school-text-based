#include "pch.h"
#include "Door.h"
#include "Random.h"

#include <iostream>


Door::Door()
{
	int randomizeRoomContaining = Random::RandomInt(2);
	if (randomizeRoomContaining == 1) {
		HasRoom = true;
	}
	else {
		HasRoom = false;
	}
}


Door::~Door()
{
}
