#pragma once
#include <vector>
#include <iostream>
#include "Component.h"
#include "Tile.h"
#include "Random.h"
#include "ConsoleColor.h"

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
		grassTile = new Tile(1, true, "\033[42m  \033[40m");
		rockTile = new Tile(1, true, "\033[47m  \033[40m");
		waterTile = new Tile(1, true, "\033[44m  \033[40m");

		for (size_t x = 0; x < (size_t)width; x++)
		{
			for (size_t y = 0; y < (size_t)height; y++)
			{
				float val = Random::RandomInt(200)/100.0f;
				//std::cout << val << std::endl;
				if (val > 0.3 && val < 0.4) {
					tiles[x][y] = (*rockTile);
				}
				else if (val >= 0.4) {
					tiles[x][y] = (*grassTile);
				}
				else {
					tiles[x][y] = (*waterTile);
				}
			}
		}

		for (size_t x = 0; x < (size_t)width; x++)
		{
			for (size_t y = 0; y < (size_t)height; y++)
			{
				std::cout << tiles[x][y].terrainType << "";
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

