#include "pch.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <cstring>
#include "picojson.h"
#include "ConsoleColor.h"
#include "Game.h"
#include "Message.h"
#include "Debug.h"

using namespace std;

ifstream i("MessageData.json");
string messageData((istreambuf_iterator<char>(i)),(istreambuf_iterator<char>()));
const char *messageBuffer = messageData.c_str();

picojson::value v;
string err = picojson::parse(v, messageBuffer);

picojson::value returnMessages = v.get("returnMessages");
picojson::value commands = v.get("commands");

const char* jsonToChar(picojson::value value) {
	const char* ret = value.to_str().c_str();
	return ret;
}

Game::Game()
{
	Quit = false;
	room = Room();

	Message::Send(returnMessages.get("welcome").to_str().c_str());
}


Game::~Game()
{
}

void Game::Loop() {
	while (!Quit) {
		char buffer[100];
		char msg[100];
		Message::Send(divider);
		cin >> buffer;
		if (strcmp(buffer, commands.get("exit").to_str().c_str()) == 0) {
			Message::Send(returnMessages.get("exit").to_str().c_str());
			QuitGame();
			break;
		}
		else if (isdigit(buffer[0])) {
			int n = buffer[0] - 48;
			if (n <= room.doors.size()) {
				sprintf_s(msg, returnMessages.get("doorSelection").to_str().c_str(), n);
				Message::Send(msg);
				steps++;
				Door door = room.doors.at(n-1);
				if (door.HasRoom == true) {
					Message::Send(returnMessages.get("nextRoom").to_str().c_str());
					room.RebuildRoom();
				}
				else {
					Message::Send(returnMessages.get("blockedDoor").to_str().c_str());
				}
			}
			else {
				sprintf_s(msg, returnMessages.get("doorNonExistant").to_str().c_str(), n);
				Message::Send(msg);
			}
		}
		else if (strcmp(buffer, commands.get("stps").to_str().c_str()) == 0) {
			sprintf_s(msg, returnMessages.get("stepCount").to_str().c_str(), steps);
			Message::Send(msg);
		}
		else if (strcmp(buffer, commands.get("hlp").to_str().c_str()) == 0) {
			Message::Send(returnMessages.get("help").to_str().c_str());
		}
		else {
			Message::Send(returnMessages.get("commandNonExistant").to_str().c_str());
		}
	}
}
