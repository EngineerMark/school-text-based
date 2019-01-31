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
	State::Enter(game);
	Message::Send(messages->GetMessageTest("welcome").to_str().c_str());
	room->DoorsMessage();
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
		if (input == "inventory") {
			Message::Send("Your inventory:");

			ItemList* items = game->inventory->GetItems();

			ItemList::iterator it = items->begin();
			ItemList::iterator end = items->end();

			while (it != end) {
				Item* item = (*it);

				//Message::Send("- "+item->GetName());

				it++;
			}
		}
		else if (input == "look left") {
			game->GetPlayer()->SetLookDirection(LDIR_LEFT);
			Message::Send("You are now looking to the left.");
			// Send puzzle-left msg
			if (room->GetLeftPuzzle()) {
				Message::Send("This side gives you an question to solve:");
				Message::Send(room->GetLeftPuzzle()->Equation());
				Message::Send("Use the answer of this question on the corresponding door");
			}
			else {
				Message::Send("There is nothing of use");
			}
		}
		else if (input == "look right") {
			game->GetPlayer()->SetLookDirection(LDIR_RIGHT);
			Message::Send("You are now looking to the right.");
			// Send puzzle-right msg
			if (room->GetRightPuzzle()) {

			}
			else {
				Message::Send("There is nothing of use");
			}
		}
		else if (input == "look at doors") {
			game->GetPlayer()->SetLookDirection(LDIR_FORWARD);
			Message::Send("You are looking at the doors again.");
		}
		else if (isdigit(input.c_str()[0]) && game->GetPlayer()->GetLookDirection()== LDIR_FORWARD) {
			int n = input.c_str()[0] - 48;
			if ((size_t)n <= room->doors.size()) {
				sprintf_s(msg, messages->GetMessageTest("doorSelection").to_str().c_str(), n);
				Message::Send(msg);
				steps++;
				Door door = room->doors.at(n - 1);
				if (door.HasRoom == true) {
					Message::Send(messages->GetMessageTest("nextRoom").to_str().c_str());
					game->IncrementPosition();
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
		else if (game->GetPlayer()->GetLookDirection() != LDIR_FORWARD) {
			Message::Send("You are not looking at the doors, so you cannot choose one.");
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
		//Message::Send("NO DOOR HAS A ROOM");
		progressState = GAME_OVER;
	}
}

void StateRoom::Exit(Game* game)
{
}
