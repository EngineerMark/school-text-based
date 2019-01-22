#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include "string"

class Time
{
public:
	Time();
	~Time();
	static std::string GetTime();
	static float_t DeltaTime();
	static float_t GetStartTime();
};

