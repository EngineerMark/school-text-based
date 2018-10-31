#include "pch.h"
#include "Game.h"

#include "StateIntroduction.h"

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
	// Update statemachine loop
	stateMachine->Update();
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
