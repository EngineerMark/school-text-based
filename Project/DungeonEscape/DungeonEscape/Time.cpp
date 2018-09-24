#include "pch.h"
#include "Time.h"

#include <iostream>
#include <ctime>
#include <iomanip>
#include "string"


Time::Time()
{
}


Time::~Time()
{
}

std::string Time::GetTime() {
	std::time_t val = std::time(NULL);
	struct tm timeinfo;
	localtime_s(&timeinfo, &val);
	char buffer[100];
	sprintf_s(buffer, "[%02d:%02d:%02d]: ", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
	std::string stringtime(buffer);
	return stringtime;
}
