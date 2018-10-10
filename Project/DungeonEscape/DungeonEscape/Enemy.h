#pragma once


class Enemy
{
public:
	int hp;
	Enemy();
	~Enemy();
	void RemoveHealth(int amount);
	int GetHealth();
};

