#include "pch.h"
#include <iostream>
#include "ConsoleColor.h"
#include "Game.h"
#include "Debug.h"

using namespace std;


Game::Game()
{
	Quit = false;
	room = Room();

	cout << yellow << "Welcome to the Dungeon. You fell asleep and found yourself here.\n" << white;
	cout << yellow << "The only way out is to explore to rooms towards the exit.\n" << white;
	cout << yellow << "Each door you check out counts as a step.\n" << white;
	room.DoorsMessage();
}


Game::~Game()
{
}

void Game::Loop() {
	while (!Quit) {
		char buffer[100];
		cin >> buffer;
		if (strcmp(buffer, quitString) == 0) {
			cout << "Stopping and exiting the game.";
			QuitGame();
			break;
		}
		Debug::Log(buffer);
	}
}
