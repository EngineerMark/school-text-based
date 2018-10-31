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
	Message::Send(messages->GetMessageTest("welcome").to_str().c_str());
}

void StateIntroduction::Execute(Game* game)
{
	if (GetUserInput() == messages->GetCommand("start").to_str().c_str()) {
		Message::Send(messages->GetMessageTest("gameStarted").to_str().c_str());
	}
}

void StateIntroduction::Exit(Game* game)
{
}
