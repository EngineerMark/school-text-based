#include "pch.h"
#include "Game.h"

//const char* jsonToChar(picojson::value value) {
//	char buffer[1024];
//	sprintf_s(buffer, value.to_str().c_str());
//	//buffer = value.to_str().c_str();
//	return buffer;
//}

Game::Game()
{
	Quit = false;
	room = Room();
	messageData = new MessageData("MessageData.json");
	Message::Send(messageData->GetMessageTest("welcome").to_str().c_str());
}


Game::~Game()
{
	SAFE_DELETE(messageData);
}

void Game::Loop() {
	//while (!Quit) {
		char buffer[4096];
		char msg[4096];
		Message::Send(divider);
		std::cin >> buffer;
		//if (strcmp(buffer, commands.get("exit").to_str().c_str()) == 0) {
		if (strcmp(buffer, messageData->GetCommand("exit").to_str().c_str()) == 0) {
			//Message::Send(returnMessages.get("exit").to_str().c_str());
			Message::Send(messageData->GetMessageTest("exit").to_str().c_str());
			QuitGame();
		}
		else if (isdigit(buffer[0])) {
			int n = buffer[0] - 48;
			if (n <= room.doors.size()) {
				//sprintf_s(msg, returnMessages.get("doorSelection").to_str().c_str(), n);
				sprintf_s(msg, messageData->GetMessageTest("doorSelection").to_str().c_str(), n);
				Message::Send(msg);
				steps++;
				Door door = room.doors.at(n-1);
				if (door.HasRoom == true) {
					//Message::Send(returnMessages.get("nextRoom").to_str().c_str());
					Message::Send(messageData->GetMessageTest("nextRoom").to_str().c_str());
					room.RebuildRoom();
				}
				else {
					//Message::Send(returnMessages.get("blockedDoor").to_str().c_str());
					Message::Send(messageData->GetMessageTest("blockedDoor").to_str().c_str());
				}
			}
			else {
				//sprintf_s(msg, returnMessages.get("doorNonExistant").to_str().c_str(), n);
				sprintf_s(msg, messageData->GetMessageTest("doorNonExistant").to_str().c_str(), n);
				Message::Send(msg);
			}
		}
		//else if (strcmp(buffer, commands.get("stps").to_str().c_str()) == 0) {
		else if (strcmp(buffer, messageData->GetCommand("stps").to_str().c_str()) == 0) {
			//sprintf_s(msg, returnMessages.get("stepCount").to_str().c_str(), steps);
			sprintf_s(msg, messageData->GetMessageTest("stepCount").to_str().c_str(), steps);
			Message::Send(msg);
		}
		//else if (strcmp(buffer, commands.get("hlp").to_str().c_str()) == 0) {
		else if (strcmp(buffer, messageData->GetCommand("hlp").to_str().c_str()) == 0) {
			//Message::Send(returnMessages.get("help").to_str().c_str());
			Message::Send(messageData->GetMessageTest("help").to_str().c_str());
		}
		else {
			//Message::Send(returnMessages.get("commandNonExistant").to_str().c_str());
			Message::Send(messageData->GetMessageTest("commandNonExistant").to_str().c_str());
		}
	//}
}
