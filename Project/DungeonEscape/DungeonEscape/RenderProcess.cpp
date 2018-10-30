#include "pch.h"
#include "RenderProcess.h"
#include "Debug.h"

GLFWwindow* window;

const int WIDTH = 1280;
const int HEIGHT = 720;

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

void RenderProcess::initWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Dungeon Escape Render Window", nullptr, nullptr);
}

void RenderProcess::initVulkan() {
	
}

void RenderProcess::loop() {
	glfwPollEvents();
}

void RenderProcess::cleanup() {
	
	glfwDestroyWindow(window);
	glfwTerminate();
}

RenderProcess::RenderProcess()
{
	SetProcessType(PROCESS_VULKAN);
}

RenderProcess::~RenderProcess()
{
	cleanup();
}


void RenderProcess::OnAbort()
{
	cleanup();
}

void RenderProcess::Loop() {
	Process::Loop();
	initWindow();
	initVulkan();
	while (IsAlive()) {
		if (IsPaused())
			continue;
		if (IsDead())
			break;

		//std::cout << "RenderProcess" << std::endl;
		loop();

		if (GetState() == STATE_SUCCEEDED)
			break;
	}
	SetState(STATE_SUCCEEDED);
	Debug::Log("Vulkan Thread loop finished");
}

void RenderProcess::OnUpdate(float deltaTime)
{
	SetState(STATE_RUNNING);
}

void RenderProcess::OnInit()
{
	Process::OnInit();
	try {
		thread = new std::thread(&RenderProcess::Loop, this);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		OnAbort();
		//return EXIT_FAILURE;
		return;
	}
}
