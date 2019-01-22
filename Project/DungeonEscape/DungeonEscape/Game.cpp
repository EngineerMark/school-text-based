#include "pch.h"
#include "Game.h"

#include "StateIntroduction.h"
#include "StateRoom.h"
#include "StateGameOver.h"
#include "StateWin.h"

#include "MeshRenderer.h"

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
	states.push_back(new StateRoom(messageData, &room));
	states.push_back(new StateGameOver(messageData));
	states.push_back(new StateWin(messageData));
	stateMachine->ChangeState(states[0]);

	inventory = new Inventory();

	player = new Player();

	/*sceneManager = new SceneManager();

	Scene* introScene = sceneManager->CreateScene("IntroScene");*/

	/*GameObject* test = introScene->AddGameObject(new GameObject());
	MeshRenderer* testComponent = test->AddComponent<MeshRenderer>();
	testComponent->SetMesh(new Mesh());
	testComponent->GetMesh()->GenerateModelFromFile("Models/chalet.obj");*/
}

Game::~Game()
{
	// Deleting all (possibly) existing pointers
	SAFE_DELETE(sceneManager);
	SAFE_DELETE(player);
	SAFE_DELETE(inventory);
	SAFE_DELETE(messageData);
	for (int i = 0; i < states.size(); i++)
		SAFE_DELETE(states[i]);
	states.clear();
	SAFE_DELETE(stateMachine);
}

void Game::Loop() {
	//Message::Send(divider);
	// Update statemachine loop
	stateMachine->Update();

	// Check if the current state even wants to switch
	if (stateMachine->GetState()->progressState != GAME_NONE) {
		// States:
		// 0: Introduction
		// 1: Room/Dungeon gameplay
		// 2: Game Over
		// 3: Exit game aka GAME_EXIT
		// Check if game is in introduction state
		if (stateMachine->GetState() == states[0]) {
			// Check if game resumes to next state needed
			if (stateMachine->GetState()->progressState == GAME_CONTINUE) {
				// progress is continue, resume to room state
				stateMachine->ChangeState(states[1]);
			}
		}
		// Game is not in introduction state, check Room state
		else if (stateMachine->GetState() == states[1]) {
			if (stateMachine->GetState()->progressState == GAME_OVER) {
				stateMachine->ChangeState(states[2]);
			}
			else if (stateMachine->GetState()->progressState == GAME_WON) {
				stateMachine->ChangeState(states[3]);
			}
		}
		// Game is in gameover mode
		else if (stateMachine->GetState() == states[2]) {
			if (stateMachine->GetState()->progressState == GAME_CONTINUE) {
				stateMachine->ChangeState(states[0]);
				ResetGame();
			}
		}
		// Game is exiting (state 3)
		if (stateMachine->GetState()->progressState == GAME_EXIT) {
			Message::Send(messageData->GetMessageTest("exit").to_str().c_str());
			QuitGame();
		}
	}
}
