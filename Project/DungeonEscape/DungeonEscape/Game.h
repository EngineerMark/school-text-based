#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <cstring>
#include "MessageData.h"
#include "StateMachine.h"
#include "Room.h"
#include "picojson.h"
#include "ConsoleColor.h"
#include "Message.h"
#include "Debug.h"

class Game
{
private:
	bool Quit;
	const char* divider = "------------------------------------------------------------------";
	MessageData* messageData;
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

