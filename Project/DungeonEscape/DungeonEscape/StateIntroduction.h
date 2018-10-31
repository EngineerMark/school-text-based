#pragma once
#include "State.h"
#include "Game.h"

class StateIntroduction: public State<Game>
{
public:
	MessageData* messages;
	StateIntroduction(MessageData* msg);
	~StateIntroduction();
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;
};
