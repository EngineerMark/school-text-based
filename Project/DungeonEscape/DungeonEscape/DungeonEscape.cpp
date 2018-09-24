#include "pch.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <iostream>
#include "Game.h"
#include "Debug.h"

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow *window = glfwCreateWindow(800, 600, "Dungeon Escape", nullptr, nullptr);

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	glm::mat4 matrix;
	glm::vec4 vec;
	auto test = matrix * vec;

	Game game;

	/*while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}*/

	game.Loop();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}