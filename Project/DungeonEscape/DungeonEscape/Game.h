#pragma once
#include "Room.h"
#include "StateMachine.h"
#include <vector>
class Game
{
private:
	bool Quit;
	const char* divider = "------------------------------------------------------------------";
	//StateMachine<Game> stateMachine;
public:
	bool IsQuitting() { return Quit; };
	void QuitGame() { Quit = true; };
	Game();
	~Game();
	void Loop();
	int steps = 0;
	Room room;
};

