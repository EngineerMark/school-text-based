#include "pch.h"
#include "Door.h"
#include "Random.h"


Door::Door()
{
	int randomizeRoomContaining = Random::RandomInt(15);
	if (randomizeRoomContaining < 3) {
		HasRoom = true;
	}
}


Door::~Door()
{
}
