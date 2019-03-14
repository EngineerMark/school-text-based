#pragma once

class Component
{
private:
	int instanceID;
public:
	Component();
	~Component();

	static int ID;

	virtual void Update() {};

	int GetInstanceID() {
		return ID;
	}
};