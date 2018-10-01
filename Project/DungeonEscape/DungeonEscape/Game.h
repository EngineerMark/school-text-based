#pragma once
#include "Room.h"
class Game
{
private:
	bool Quit;
	const char* divider = "------------------------------------------------------------------";
public:
	bool IsQuitting() { return Quit; };
	void QuitGame() { Quit = true; };
	Game();
	~Game();
	void Loop();
	int steps = 0;
	Room room;
};

