#pragma once
#include <string>
#include "GameProgression.h"

template<class T> class State
{
public:
	virtual void Enter(T* t) {};
	virtual void Execute(T* t) {};
	virtual void Exit(T* t) {};

	GameProgressionStates progressState;

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
