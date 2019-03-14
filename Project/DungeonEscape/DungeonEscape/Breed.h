#pragma once
#ifndef BREED_H
#define BREED_H
#include "Enemy.h"

class Enemy;
class Breed
{
private:
	int health_;
	const char* attack_;
	Enemy* enemy;
public:
	Breed(int health, const char* attack):health_(health),attack_(attack){}
	int GetHealth(){return health_;}
	const char* GetAttack(){return attack_;}
	Enemy* newEnemy(){
		Enemy* enemy = new Enemy(*this);
		return enemy;
	}
};
#endif // BREED_H
