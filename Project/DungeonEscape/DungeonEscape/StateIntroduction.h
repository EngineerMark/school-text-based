#pragma once
#include "State.h"
#include "GameProgression.h"
#include "Game.h"
#include "Inventory.h"

class StateIntroduction: public State<Game>
{
private:
	Inventory* testInv;
public:
	MessageData* messages;
	StateIntroduction(MessageData* msg);
	~StateIntroduction();
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;
};
