#pragma once
#include <iostream>
#include <string>

constexpr auto SIZE = 10;

class Graph
{
public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				matrix[i][j] = 0;
		vertexCount = 0;
	}
	void addVertex(std::string name);
	void addEdge(std::string name1, std::string name2);
	void delEdge(std::string name1, std::string name2);
	void delVertex(std::string name);
	void findMinDistancesFloyd();
	bool edgeExists(int v1, int v2);
private:
	std::string vertexes[SIZE];
	int vertexCount;
	int matrix[SIZE][SIZE];
};
