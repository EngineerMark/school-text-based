#pragma once
#include <string>
class Tile
{
private:
	float movementCost;
	bool isTraversable;
public:
	std::string terrainType;
	Tile() {};
	Tile(float movementCost, bool isTraversable, std::string type) : movementCost(movementCost), isTraversable(isTraversable), terrainType(type){};

	// Texture tex;
	// Quad info
};

