#pragma once

#include <string>

class Debug
{
public:
	Debug();
	~Debug();
	static void Log(std::string message);
	static void WarningLog(std::string message);
	static void ErrorLog(std::string message);
};

