#pragma once
#include "State.h"
#include "Enemy.h"

class EnemyStateSleep :State<Enemy>
{
public:
	EnemyStateSleep();
	~EnemyStateSleep();
};

class EnemyStateAttack :State<Enemy>
{
public:
	EnemyStateAttack();
	~EnemyStateAttack();
};
