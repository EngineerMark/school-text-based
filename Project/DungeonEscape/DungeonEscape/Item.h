#pragma once
#include <string>

class Item
{
private:
	std::string itemName;
public:
	Item(std::string name) {
		itemName = name;
	};
	~Item() {

	};

	std::string GetName() {
		return itemName;
	}
};

