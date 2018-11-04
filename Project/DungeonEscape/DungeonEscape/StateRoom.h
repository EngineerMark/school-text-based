#pragma once
#include "State.h"
#include "Game.h"

class StateRoom: public State<Game>
{
private:
	Room* room;
	int steps = 0;
public:
	MessageData* messages;
	StateRoom(MessageData* msg, Room* room);
	~StateRoom();
	void Enter(Game* game) override;
	void Execute(Game* game) override;
	void Exit(Game* game) override;
};

