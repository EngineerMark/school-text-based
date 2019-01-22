#include "pch.h"
#include "Time.h"

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

float_t Time::GetStartTime() {
	static auto startTime = std::chrono::high_resolution_clock::now();
	auto currentTime = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
	return static_cast<float_t>(time);
}
