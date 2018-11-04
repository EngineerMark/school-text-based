#include "pch.h"
#include "Game.h"

#include "StateIntroduction.h"
#include "StateRoom.h"
#include "StateGameOver.h"

std::vector<State<Game>*> Game::states = std::vector<State<Game>*>();

Game::Game()
{
	// Load all json data containing messages
	messageData = new MessageData("MessageData.json");
	Quit = false;
	room = Room();
	/*Message::Send(messageData->GetMessageTest("welcome").to_str().c_str());*/

	// Setting up statemachine and starting introduction
	stateMachine = new StateMachine<Game>(this);
	states.push_back(new StateIntroduction(messageData));
	states.push_back(new StateRoom(messageData, &room));
	states.push_back(new StateGameOver(messageData));
	stateMachine->ChangeState(states[0]);

}

Game::~Game()
{
	// Deleting all (possibly) existing pointers
	SAFE_DELETE(messageData);
	for (int i = 0; i < states.size(); i++)
		SAFE_DELETE(states[i]);
	states.clear();
	SAFE_DELETE(stateMachine);
}

void Game::Loop() {
	Message::Send(divider);
	// Update statemachine loop
	stateMachine->Update();

	// Check if the current state even wants to switch
	if (stateMachine->GetState()->progressState != GAME_NONE) {
		// States:
		// 0: Introduction
		// 1: Room/Dungeon gameplay
		// 2: Game Over
		// 3: Exit game aka GAME_EXIT
		// Check if game is in introduction state
		if (stateMachine->GetState() == states[0]) {
			// Check if game resumes to next state needed
			if (stateMachine->GetState()->progressState == GAME_CONTINUE) {
				// progress is continue, resume to room state
				stateMachine->ChangeState(states[1]);
			}
		}
		// Game is not in introduction state, check Room state
		else if (stateMachine->GetState() == states[1]) {
			if (stateMachine->GetState()->progressState == GAME_OVER) {
				stateMachine->ChangeState(states[2]);
			}
		}
		// Game is in gameover mode
		else if (stateMachine->GetState() == states[2]) {
			if (stateMachine->GetState()->progressState == GAME_CONTINUE) {
				stateMachine->ChangeState(states[0]);
			}
		}
		// Game is exiting (state 3)
		if (stateMachine->GetState()->progressState == GAME_EXIT) {
			Message::Send(messageData->GetMessageTest("exit").to_str().c_str());
			QuitGame();
		}
	}

	/*char buffer[4096];
	char msg[4096];
	Message::Send(divider);
	std::cin >> buffer;
	if (strcmp(buffer, messageData->GetCommand("exit").to_str().c_str()) == 0) {
		Message::Send(messageData->GetMessageTest("exit").to_str().c_str());
		QuitGame();
	}
	else if (isdigit(buffer[0])) {
		int n = buffer[0] - 48;
		if (n <= room.doors.size()) {
			sprintf_s(msg, messageData->GetMessageTest("doorSelection").to_str().c_str(), n);
			Message::Send(msg);
			steps++;
			Door door = room.doors.at(n - 1);
			if (door.HasRoom == true) {
				Message::Send(messageData->GetMessageTest("nextRoom").to_str().c_str());
				room.RebuildRoom();
			}
			else {
				Message::Send(messageData->GetMessageTest("blockedDoor").to_str().c_str());
			}
		}
		else {
			sprintf_s(msg, messageData->GetMessageTest("doorNonExistant").to_str().c_str(), n);
			Message::Send(msg);
		}
	}
	else if (strcmp(buffer, messageData->GetCommand("stps").to_str().c_str()) == 0) {
		sprintf_s(msg, messageData->GetMessageTest("stepCount").to_str().c_str(), steps);
		Message::Send(msg);
	}
	else if (strcmp(buffer, messageData->GetCommand("hlp").to_str().c_str()) == 0) {
		Message::Send(messageData->GetMessageTest("help").to_str().c_str());
	}
	else {
		Message::Send(messageData->GetMessageTest("commandNonExistant").to_str().c_str());
	}*/
}
