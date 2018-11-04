#include "pch.h"

#include "StateRoom.h"

StateRoom::StateRoom(MessageData* msg, Room* room)
{
	messages = msg;
	this->room = room;
}

StateRoom::~StateRoom()
{
}

void StateRoom::Enter(Game* game)
{
	Message::Send(messages->GetMessageTest("welcome").to_str().c_str());
}

void StateRoom::Execute(Game* game)
{
	/*bool doorsPossible = false;
	for (auto const& val:room->doors)
	{
		if (val.HasRoom) {
			doorsPossible = true;
			break;
		}
	}*/
	if (room->HasRoom()) {
		char msg[4096];
		// Store input once so it does not require multiple inputs to finish the iteration
		std::string input = GetUserInput();
		if (isdigit(input.c_str()[0])) {
			int n = input.c_str()[0] - 48;
			if (n <= room->doors.size()) {
				sprintf_s(msg, messages->GetMessageTest("doorSelection").to_str().c_str(), n);
				Message::Send(msg);
				steps++;
				Door door = room->doors.at(n - 1);
				if (door.HasRoom == true) {
					Message::Send(messages->GetMessageTest("nextRoom").to_str().c_str());
					room->RebuildRoom();
					room->DoorsMessage();
				}
				else {
					Message::Send(messages->GetMessageTest("blockedDoor").to_str().c_str());
				}
			}
			else {
				sprintf_s(msg, messages->GetMessageTest("doorNonExistant").to_str().c_str(), n);
				Message::Send(msg);
			}
		}
		else if (strcmp(input.c_str(), messages->GetCommand("stps").to_str().c_str()) == 0) {
			sprintf_s(msg, messages->GetMessageTest("stepCount").to_str().c_str(), steps);
			Message::Send(msg);
		}
		else if (strcmp(input.c_str(), messages->GetCommand("hlp").to_str().c_str()) == 0) {
			Message::Send(messages->GetMessageTest("help").to_str().c_str());
		}
		else {
			Message::Send(messages->GetMessageTest("commandNonExistant").to_str().c_str());
		}
	}
	else {
		Message::Send("NO DOOR HAS A ROOM");
		progressState = GAME_OVER;
	}
}

void StateRoom::Exit(Game* game)
{
}
