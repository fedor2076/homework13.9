#include "graph.h"

void Graph::addVertex(std::string name)
{
	vertexes[vertexCount++] = name;

}

void Graph::addEdge(std::string name1, std::string name2)
//для рукопожатия вес ребра равен 1 
//или можно рассмотреть true ребро есть или его нет false  
{
	int v1, v2;
	for (int k = 0; k < SIZE; k++)
	{
		if (name1 == vertexes[k])
			v1 = k;

		if (name2 == vertexes[k])
			v2 = k;



	}
	matrix[v1][v2] = 1;
	matrix[v2][v1] = 1;

}
void Graph::delVertex(std::string name)
{
	int vnumber;
	// обнуляем столбец и строку матрицы
	for (int k = 0; k < SIZE; k++)
		if (name == vertexes[k])
			vnumber = k;
	for (int i = 0; i < SIZE; i++)
	{
		matrix[i][vnumber] = 0;
		matrix[vnumber][i] = 0;
	}
	// удаляем вершину из списка вершин

	vertexCount--;
	for (int i = vnumber; i < vertexCount; i++)
	{
		vertexes[i] = vertexes[i + 1];
	}
}

void Graph::delEdge(std::string name1, std::string name2)
{
	int v1, v2;
	for (int k = 0; k < SIZE; k++)
	{
		if (name1 == vertexes[k])
			v1 = k;
		if (name2 == vertexes[k])
			v2 = k;
	}
	matrix[v1][v2] = 0;
	matrix[v2][v1] = 0;
}

bool Graph::edgeExists(int v1, int v2)
{
	return matrix[v1][v2] != 0;
}

#define VERYBIGINT 1000000000

void Graph::findMinDistancesFloyd()
{
	int weights[SIZE][SIZE]; // матрица путей
	// инициализаци матрицы
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j)
			{
				weights[i][j] = 0; // путь до самой себя равен 0
			}
			else 
			{
				if (!edgeExists(i, j))
				{
					weights[i][j] = VERYBIGINT; // если ребра нет
				}
				else
				{
					weights[i][j] = matrix[i][j]; // если ребро есть
				}
			}

		}
	}

	for (int k = 0; k < vertexCount; k++) // итерации по k
	{
		int ck = k; // возьмем номер вершины
		for (int i = 0; i < vertexCount; i++)
		{
			if (i == k)
				continue;
			int ci = i;
			for (int j = 0; j < vertexCount; j++)
			{
				if (j == k)
					continue;
				int cj = j;
				
				if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj])
				{
					// пересчет матрицы путей					
					weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
				}
			}
		}
	}

	for (int i = 0; i < vertexCount; i++)
	{
		for (int j = i; j < vertexCount; j++)
		{
			if (weights[j][i] <= 3 && weights[j][i]!=0)
				std::cout << vertexes[j]<< " " << vertexes[i] << ": " << weights[j][i] << " - handshake \n";
		}
	}

}



