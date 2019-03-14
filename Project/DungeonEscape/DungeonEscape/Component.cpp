#include "pch.h"
#include "Component.h"
#include <iostream>

int Component::ID = -20000;

Component::Component() {
	instanceID = ID;
	ID += 2;

	std::cout << "Instanced ID: " << instanceID << " Current ID: " << ID << std::endl;
}

Component::~Component() {
	
}
