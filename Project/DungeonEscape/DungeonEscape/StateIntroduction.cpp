#include "pch.h"
#include "StateIntroduction.h"

StateIntroduction::StateIntroduction(MessageData* msg)
{
	messages = msg;
}

StateIntroduction::~StateIntroduction()
{
}

void StateIntroduction::Enter(Game* game)
{
	State::Enter(game);
	Message::Send(messages->GetMessageTest("introduction").to_str().c_str());
}

void StateIntroduction::Execute(Game* game)
{
	std::string input = GetUserInput();	

	/*if (input == "inv") {
		ItemList* items = testInv->GetItems();

		ItemList::iterator it = items->begin();
		ItemList::iterator end = items->end();

		while (it != end) {
			Message::Send((*it)->GetName().c_str());
			it++;
		}
	}
*/

	if (input == "easy") {
		Message::Send(messages->GetMessageTest("difficultyEasy").to_str().c_str());
		Message::Send(messages->GetMessageTest("startQuestion").to_str().c_str());
		game->SetDifficulty(GAME_EASY);
	}
	else if (input == "normal") {
		Message::Send(messages->GetMessageTest("difficultyNormal").to_str().c_str());
		Message::Send(messages->GetMessageTest("startQuestion").to_str().c_str());
		game->SetDifficulty(GAME_NORMAL);
	}
	else if (input == "hard") {
		Message::Send(messages->GetMessageTest("difficultyHard").to_str().c_str());
		Message::Send(messages->GetMessageTest("startQuestion").to_str().c_str());
		game->SetDifficulty(GAME_HARD);
	}
	if (game->GetDifficulty()!=GAME_UNSET) {
		if (input == messages->GetCommand("start").to_str().c_str()) {
			Message::Send(messages->GetMessageTest("gameStarted").to_str().c_str());
			progressState = GAME_CONTINUE;
		}
	}
	else {
		Message::Send(messages->GetMessageTest("noDifficulty").to_str().c_str());
	}
}

void StateIntroduction::Exit(Game* game)
{
}
