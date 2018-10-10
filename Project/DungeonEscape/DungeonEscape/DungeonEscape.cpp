#include "pch.h"
#include <ctime>
#include <thread>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>
//#include "Window.h"
#include "Game.h"
#include "Debug.h"
#include "ProcessManager.h"
#include "Process.h"
#include "RenderProcess.h"
#include "InputProcess.h"

//int VulkanThread() {
//	Window appWindow;
//	try {
//		appWindow.Run();
//	}
//	catch (const std::exception& e) {
//		std::cerr << e.what() << std::endl;
//		return EXIT_FAILURE;
//	}
//
//	return EXIT_SUCCESS;
//}

void GameThread(Game game) {
	game.Loop();
}

int main()
{
	std::srand((unsigned)std::time(0));
	//Game game;

	ProcessManager processManager;

	StrongProcessPtr renderProcess = StrongProcessPtr(new RenderProcess());
	processManager.RegisterProcess(renderProcess);
	StrongProcessPtr inputProcess = StrongProcessPtr(new InputProcess());
	processManager.RegisterProcess(inputProcess);
	/*renderProcess->OnInit();
	processManager.processList->push_back(renderProcess);

	inputProcess->OnInit();
	processManager.processList->push_back(inputProcess);*/

	while (true) {
		int err = processManager.UpdateProcesses(0);
		/*if (err > 0) {
			break;
		}*/
	}

	//std::thread vulkanthread(VulkanThread);
	//std::thread gamethread(GameThread, game);

	//vulkanthread.join();
	//gamethread.join();

	return 0;
}