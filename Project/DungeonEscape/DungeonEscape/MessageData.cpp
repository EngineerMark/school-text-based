#include "pch.h"
#include "MessageData.h"


MessageData::MessageData(std::string file)
{
	std::ifstream i(file);
	std::string messageData((std::istreambuf_iterator<char>(i)), (std::istreambuf_iterator<char>()));
	const char *messageBuffer = messageData.c_str();

	picojson::value v;
	std::string err = picojson::parse(v, messageBuffer);

	messages = v.get("returnMessages");
	commands = v.get("commands");

	SAFE_DELETE(messageBuffer);
}


MessageData::~MessageData()
{
}

picojson::value MessageData::GetMessageTest(std::string key)
{
	return messages.get(key);
}

picojson::value MessageData::GetCommand(std::string key) {
	return commands.get(key);
}