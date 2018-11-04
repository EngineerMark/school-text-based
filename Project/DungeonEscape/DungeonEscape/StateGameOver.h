#pragma once
#include "State.h"
#include "Game.h"

class StateGameOver: public State<Game>
{
public:
	MessageData* messages;
	StateGameOver(MessageData* msg);
	~StateGameOver();
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;
};

