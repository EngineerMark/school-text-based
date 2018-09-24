#pragma once
#include "Room.h"
class Game
{
private:
	bool Quit;
	const char *quitString = "quit";
public:
	bool IsQuitting() { return Quit; };
	void QuitGame() { Quit = true; };
	Game();
	~Game();
	void Loop();

	Room room;
};

