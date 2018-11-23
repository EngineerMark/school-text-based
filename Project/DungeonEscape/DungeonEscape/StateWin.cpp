#include "pch.h"
#include "StateWin.h"


StateWin::StateWin(MessageData* msg)
{
	messages = msg;
}


StateWin::~StateWin()
{
}

void StateWin::Enter(Game* game)
{
	State::Enter(game);
	Message::Send(messages->GetMessageTest("winmessage").to_str().c_str());
}

void StateWin::Execute(Game* game)
{
	//std::string input = GetUserInput();
	//if (input == "continue") {
		progressState = GAME_CONTINUE;
	//}
}

void StateWin::Exit(Game* game)
{
}
