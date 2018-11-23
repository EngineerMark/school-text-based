#pragma once
#include "Entity.h"
#include "LookDirection.h"

class Player: public Entity
{
public:
	Player();
	~Player();
	void SetLookDirection(LookDirection dir);
	LookDirection GetLookDirection() { return lookDirection; };
};

