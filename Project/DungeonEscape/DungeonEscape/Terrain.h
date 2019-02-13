#pragma once
#include <vector>
#include "Component.h"
#include "Tile.h"

class Terrain: Component
{
private:
	float movementCost;
	bool isTraversable;
	int width;
	int height;

	std::vector<std::vector<Tile>> tiles;
public:
	Terrain(float movementCost, bool isTraversable,int width,int height) : movementCost(movementCost), isTraversable(isTraversable), width(width), height(height) {
		tiles.resize(width);
		for (size_t i = 0; i < tiles.size(); i++)
			tiles[i].resize(height);
	};
	~Terrain();
};

