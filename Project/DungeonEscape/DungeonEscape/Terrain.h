#pragma once
#include <vector>
#include <iostream>
#include "Component.h"
#include "Tile.h"
#include "Random.h"

class Terrain : public Component
{
private:
	int width;
	int height;

	std::vector<std::vector<Tile>> tiles;
public:
	Terrain() {};
	Tile* grassTile;
	Tile* rockTile;
	Tile* waterTile;
	void GenerateTerrain() {
		grassTile = new Tile(1, true, '@');
		rockTile = new Tile(1, true, '#');
		waterTile = new Tile(1, true, '~');

		for (size_t x = 0; x < width; x++)
		{
			for (size_t y = 0; y < height; y++)
			{
				int rand = Random::RandomInt(3);
				if (rand == 1) {
					tiles[x][y] = (*grassTile);
				}
				else if(rand==2){
					tiles[x][y] = (*rockTile);
				}
				else {
					tiles[x][y] = (*waterTile);
				}
			}
		}

		for (size_t x = 0; x < width; x++)
		{
			for (size_t y = 0; y < height; y++)
			{
				std::cout << tiles[x][y].terrainType<<" ";
			}
			std::cout << std::endl;
		}
	}

	Terrain(int width, int height) : width(width), height(height) {
		tiles.resize(width);
		for (size_t i = 0; i < tiles.size(); i++)
			tiles[i].resize(height);

		GenerateTerrain();
	};
};

