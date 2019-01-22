#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Vertex.h"

class Mesh {
private:
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
public:
	void SetVertices(std::vector<Vertex> vertices) {
		this->vertices = vertices;
	}

	void SetIndices(std::vector<uint32_t> indices) {
		this->indices = indices;
	}

	std::vector<Vertex> GetVertices() {
		return vertices;
	}

	std::vector<uint32_t> GetIndices() {
		return indices;
	}

	void GenerateModelFromFile(std::string filepath);
};