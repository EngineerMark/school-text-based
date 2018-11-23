#pragma once
#include <string>
#include "GameProgression.h"
#include "LookDirection.h"

template<class T> class State
{
public:
	GameProgressionStates progressState;
	virtual void Enter(T* t) { progressState = GAME_NONE; };
	virtual void Execute(T* t) {};
	virtual void Exit(T* t) {};


	std::string GetUserInput() {
		std::string input;
		char buffer[256];
		std::cin.getline(buffer, sizeof(buffer));
		std::cin.clear();

		input = (std::string)buffer;

		std::transform(input.begin(), input.end(), input.begin(), tolower);

		return input;
	}
};
