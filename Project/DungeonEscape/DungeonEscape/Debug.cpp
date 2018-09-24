#include "pch.h"
#include "ConsoleColor.h"
#include "Debug.h"
#include "Time.h"
#include <iostream>
#include <string>


Debug::Debug()
{
}


Debug::~Debug()
{
}

void Debug::Log(std::string message) {
	std::cout << Time::GetTime() << message << std::endl;
}

void Debug::WarningLog(std::string message) {
	std::cout << yellow << Time::GetTime() << message << white << std::endl;
}

void Debug::ErrorLog(std::string message) {
	std::cout << red << Time::GetTime() << message << white << std::endl;
}