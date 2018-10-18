#include "pch.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>

#include <optional>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
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
	CreateInstance();
	setupDebugCallback();
	findPhysicalDevice();
	createLogicalDevice();
}

void RenderProcess::CreateInstance() {
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
}


struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;

	bool isComplete() {
		return graphicsFamily.has_value();
	}
};

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) {
	QueueFamilyIndices indices;

	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

	int i = 0;
	for (const auto& queueFamily : queueFamilies) {
		if (queueFamily.queueCount > 0 && queueFamily.queueFlags&VK_QUEUE_GRAPHICS_BIT) {
			indices.graphicsFamily = i;
		}

		if (indices.isComplete()) {
			break;
		}
	}

	return indices;
}

bool isDeviceSuitable(VkPhysicalDevice device) {
	QueueFamilyIndices indices = findQueueFamilies(device);

	return indices.isComplete();
}

void RenderProcess::setupDebugCallback()
{

}

void RenderProcess::findPhysicalDevice()
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

	if (deviceCount == 0) {
		throw std::runtime_error("You do not have a GPU with Vulkan support");
	}

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	for (const auto& device : devices) {
		if (isDeviceSuitable(device)) {
			physicalDevice = device;
			break;
		}
	}
	if (physicalDevice == VK_NULL_HANDLE) {
		throw std::runtime_error("No suitable GPU was found");
	}
}

void RenderProcess::createLogicalDevice()
{
	QueueFamilyIndices indices = findQueueFamilies(physicalDevice);

	VkDeviceQueueCreateInfo queueCreateInfo = {};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.value();
	queueCreateInfo.queueCount = 1;

	float queuePriority = 1.0f;
	queueCreateInfo.pQueuePriorities = &queuePriority;

	VkPhysicalDeviceFeatures deviceFeatures = {};

	VkDeviceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.pQueueCreateInfos = &queueCreateInfo;
	createInfo.queueCreateInfoCount = 1;
	createInfo.pEnabledFeatures = &deviceFeatures;

	createInfo.enabledExtensionCount = 0;
	createInfo.enabledLayerCount = 0;

	if (vkCreateDevice(physicalDevice, &createInfo, nullptr, &device) != VK_SUCCESS) {
		throw std::runtime_error("Error when creating logical device");
	}

	/*if (enableValidationLayers) {

	}*/
	vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);
}

void RenderProcess::loop() {
	glfwPollEvents();
}

void RenderProcess::cleanup() {
	vkDestroyDevice(device, nullptr);
	vkDestroyInstance(instance, nullptr);
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
