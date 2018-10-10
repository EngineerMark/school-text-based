#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vulkan/vulkan.h>
#include "Process.h"
class RenderProcess: public Process
{
private:
	void initWindow();
	void initVulkan();
	void loop();
	void cleanup();
public:
	VkInstance instance;
	RenderProcess();
	~RenderProcess();
	void OnUpdate(float deltaTime) override;
	void OnInit() override;
	void OnAbort() override;
};

