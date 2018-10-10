#include "pch.h"
#include "Enemy.h"


Enemy::Enemy()
{
	hp = 100;
}


Enemy::~Enemy()
{
}

void Enemy::RemoveHealth(int amount) {
	hp -= amount;
}

int Enemy::GetHealth() {
	return hp;
}