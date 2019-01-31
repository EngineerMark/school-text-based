#pragma once
#include <string>
class Message
{
public:
	static void Send(const char* message);
	static void Send(std::string message);
};

