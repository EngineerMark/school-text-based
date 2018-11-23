#include "pch.h"
#include "StateGameOver.h"

StateGameOver::StateGameOver(MessageData* msg)
{
	messages = msg;
}

StateGameOver::~StateGameOver()
{
}

void StateGameOver::Enter(Game* game)
{
	Message::Send(messages->GetMessageTest("gameover").to_str().c_str());
	progressState = GAME_CONTINUE;
}
