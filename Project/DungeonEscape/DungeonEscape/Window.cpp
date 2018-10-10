#include "pch.h"
//#include "Window.h"
//
//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>
//
//#include <vulkan/vulkan.h>
//
//#include <iostream>
//#include <stdexcept>
//#include <functional>
//#include <cstdlib>
//
//GLFWwindow* window;
//
//const int WIDTH = 1280;
//const int HEIGHT = 720;
//const char* TITLE = "DungeonEscape";
//
//const std::vector<const char*> validationLayers = {
//	"VK_LAYER_LUNARG_standard_validation"
//};
//
//#ifdef NDEBUG
//const bool enableValidationLayers = false;
//#else
//const bool enableValidationLayers = true;
//#endif
//
//Window::Window()
//{
//	
//}
//
//
//Window::~Window()
//{
//}
//
//void Window::Run() {
//	initWindow();
//	initVulkan();
//	cleanup();
//}
//
//void Window::Update() {
//	mainLoop();
//}
//
//void Window::initWindow() {
//	glfwInit();
//
//	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
//
//	window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, nullptr, nullptr);
//}
//
//void Window::initVulkan() {
//	VkApplicationInfo appInfo = {};
//	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
//	appInfo.pApplicationName = "DungeonEscape";
//	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
//	appInfo.pEngineName = "No Engine";
//	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
//	appInfo.apiVersion = VK_API_VERSION_1_0;
//
//	VkInstanceCreateInfo createInfo = {};
//	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
//	createInfo.pApplicationInfo = &appInfo;
//
//	uint32_t glfwExtensionCount = 0;
//	const char** glfwExtensions;
//
//	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
//	createInfo.enabledExtensionCount = glfwExtensionCount;
//	createInfo.ppEnabledExtensionNames = glfwExtensions;
//
//	createInfo.enabledLayerCount = 0;
//
//	if (vkCreateInstance(&createInfo, nullptr, &instance)) {
//		throw std::runtime_error("failed to create vulkan instance");
//	}
//
//	uint32_t extensionCount = 0;
//	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
//
//	std::vector<VkExtensionProperties> extensions(extensionCount);
//	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
//
//	//std::cout << "available extensions: " << std::endl;
//
//}
//
//void Window::mainLoop() {
//	while (!glfwWindowShouldClose(window)) {
//		glfwPollEvents();
//	}
//}
//
//void Window::cleanup() {
//	vkDestroyInstance(instance, nullptr);
//	glfwDestroyWindow(window);
//	glfwTerminate();
//}
//
//bool checkValidationLayerSupport() {
//	uint32_t layerCount;
//	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
//
//	std::vector<VkLayerProperties> availableLayers(layerCount);
//	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
//
//	for (const char* layerName : validationLayers) {
//		bool layerFound = false;
//
//		for (const auto& layerProperties : availableLayers) {
//			if (strcmp(layerName, layerProperties.layerName) == 0) {
//				layerFound = true;
//				break;
//			}
//		}
//
//		if (!layerFound) {
//			return false;
//		}
//	}
//
//	return true;
//}
//
//void createInstance() {
//	if (enableValidationLayers && !checkValidationLayerSupport()) {
//		throw std::runtime_error("validation layers requested, but not available");
//	}
//}