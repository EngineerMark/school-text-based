#pragma once
#include <fstream>
#include <iterator>
#include <string>
#include "picojson.h"

class MessageData
{
private:
	picojson::value messages;
	picojson::value commands;
public:
	MessageData(std::string file);
	~MessageData();
	picojson::value GetMessageTest(std::string key);
	picojson::value GetCommand(std::string key);
};

