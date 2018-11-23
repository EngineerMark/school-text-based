#pragma once
#include "pch.h"
#include <list>
#include "Item.h"

typedef std::list<Item*> ItemList;

class Inventory
{
private:
	ItemList* list;
public:
	Inventory() {
		list = new ItemList();
	};
	~Inventory() {
		ItemList::iterator it = list->begin();
		ItemList::iterator end = list->end();
		while (it != end) {
			SAFE_DELETE((*it));
			it++;
		}

		SAFE_DELETE(list);
	};
	void AddItem(Item* item) {
		list->push_back(item);
	}

	ItemList* GetItems() {
		return list;
	}
};

