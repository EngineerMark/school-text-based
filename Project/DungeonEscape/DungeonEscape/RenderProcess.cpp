#include "pch.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
//#include "Window.h"
#include "Process.h"
#include "RenderProcess.h"

GLFWwindow* window;

void RenderProcess::initWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(1280, 720, "vulkan", nullptr, nullptr);
}

void RenderProcess::initVulkan() {
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "DungeonEscape";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;

	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, nullptr, &instance)) {
		throw std::runtime_error("failed to create vulkan instance");
	}

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	//std::cout << "available extensions: " << std::endl;

}

void RenderProcess::loop() {
	glfwPollEvents();
}

void RenderProcess::cleanup() {
	vkDestroyInstance(instance, nullptr);
	glfwDestroyWindow(window);
	glfwTerminate();
}

RenderProcess::RenderProcess()
{
	
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
	}
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
