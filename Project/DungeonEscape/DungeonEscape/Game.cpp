#include "pch.h"
#include <iostream>
#include <iterator>
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
		if (strcmp(buffer, "quit") == 0) {
			cout << yellow << red << "Stopping and exiting the game." << white;
			QuitGame();
			break;
		}
		else if (isdigit(buffer[0])) {
			int n = buffer[0] - 48;
			if (n <= room.doors.size()) {
				cout << yellow << "You picked door " << n << "." << endl << white;
				steps++;
				auto selectedDoor = next(room.doors.begin(),n);
				cout << &selectedDoor << endl;
			}
			else {
				cout << yellow << "Door " << n << " does not exist. Pick one that actually is there." << endl << white;
			}
		}
		else if (strcmp(buffer, "steps") == 0) {
			cout << yellow << "Current step count: " << steps << endl << white;
		}
	}
}
