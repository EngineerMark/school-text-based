#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <cstring>
#include <vector>
#include "LookDirection.h"
#include "MessageData.h"
#include "StateMachine.h"
#include "Room.h"
#include "picojson.h"
#include "ConsoleColor.h"
#include "Message.h"
#include "Debug.h"
#include "Player.h"
#include "Inventory.h"

enum Difficulty {
	GAME_UNSET,
	GAME_EASY,
	GAME_NORMAL,
	GAME_HARD
};

class Game
{
private:
	bool Quit;
	const char* divider = "------------------------------------------------------------------";
	static std::vector<State<Game>*> states;
	MessageData* messageData;
	StateMachine<Game>* stateMachine;
	int gameLength;
	int currentPosition = 0;
	Player* player;
	Difficulty gameDifficulty = GAME_UNSET;
public:
	Inventory* inventory;
	bool IsQuitting() { return Quit; };
	void QuitGame() { Quit = true; };
	Game();
	~Game();
	void Loop();
	Room room;
	void SetPlayer(Player* player) { this->player = player; };
	Player* GetPlayer() { return player; };

	void SetDifficulty(Difficulty difficulty) { 
		this->gameDifficulty = difficulty;
		switch (difficulty) {
			case(GAME_UNSET):
				break;
			case(GAME_EASY):
				gameLength = 10;
				break;
			case(GAME_NORMAL):
				gameLength = 15;
				break;
			case(GAME_HARD):
				gameLength = 20;
				break;
		}
		currentPosition = 0;
	};
	Difficulty GetDifficulty() { return gameDifficulty; };

	void IncrementPosition() {
		currentPosition++;
	}

	void ResetGame() {
		SetDifficulty(GAME_UNSET);
		currentPosition = 0;
	}
};

