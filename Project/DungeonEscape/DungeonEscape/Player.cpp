#include "pch.h"
#include "Player.h"


Player::Player()
{
	lookDirection = (LookDirection)LDIR_FORWARD;
}


Player::~Player()
{
}

void Player::SetLookDirection(LookDirection dir) {
	if (lookDirection != dir)
		lookDirection = dir;
}