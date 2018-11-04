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
	Message::Send(messages->GetMessageTest("introduction").to_str().c_str());
}

void StateIntroduction::Execute(Game* game)
{
	if (GetUserInput() == messages->GetCommand("start").to_str().c_str()) {
		Message::Send(messages->GetMessageTest("gameStarted").to_str().c_str());
		progressState = GAME_CONTINUE;
	}
}

void StateIntroduction::Exit(Game* game)
{
}
