#pragma once
#include "State.h"
#include "GameProgression.h"
#include "Game.h"

class StateWin: public State<Game>
{
public:
	MessageData* messages;
	StateWin(MessageData* msg);
	~StateWin();
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;
};

