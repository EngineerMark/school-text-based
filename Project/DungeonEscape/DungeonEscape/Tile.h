#pragma once
class Tile
{
private:
	float movementCost;
	bool isTraversable;
public:
	char terrainType;
	Tile() {};
	Tile(float movementCost, bool isTraversable, char type) : movementCost(movementCost), isTraversable(isTraversable), terrainType(type){};

	// Texture tex;
	// Quad info
};

