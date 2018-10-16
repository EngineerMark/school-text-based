#pragma once
#include <map>
#include <string>
#include "State.h"
#include "Game.h"
class StateGameExample:State<Game>
{
private:
	//std::map<std::string, std::string> map;
public:
	StateGameExample();
	~StateGameExample();
};

