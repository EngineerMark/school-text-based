#pragma once
#include "Entity.h"
#ifndef ENEMY_H
#define ENEMY_H
#include "Breed.h"

class Breed;
class Enemy: public Entity
{
friend class Breed;
private:
	Enemy(Breed& breed): health_(breed.GetHealth()),breed_(breed){}
	int health_;
	Breed& breed_;
public:
	Breed& GetBreed(){return breed_;}

	const char* GetAttack(){return breed_.GetAttack();}
};
#endif
