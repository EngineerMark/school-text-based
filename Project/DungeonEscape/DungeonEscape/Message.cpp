#include "pch.h"
#include <chrono>
#include <thread>
#include "ConsoleColor.h"
#include <iostream>
#include <string>
#include "Message.h"

void Message::Send(const char* message) {
	//std::cout << message << std::endl << white;
	std::string data = message;
	Send(data);
}

void Message::Send(std::string message) {
	std::string data = message;
	for (char& c : data) {
		std::cout << c;
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
	std::cout << std::endl << white;
}