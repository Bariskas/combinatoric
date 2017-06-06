#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "StrongConnectivityChecker.h"

using namespace std;


bool initAdjacencyMatrix(vector<vector<int>>& matrix);

int main(int argc, char** argv[])
{
	vector<vector<int>> adjacencyMatrix;
	if (!initAdjacencyMatrix(adjacencyMatrix))
	{
		return 1;
	}

	CStrongConnectivityChecker checker(adjacencyMatrix);

	if (checker.Check())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << "Press any key to continue" << endl;
	getchar();
	return 0;
}

bool initAdjacencyMatrix(vector<vector<int>>& adjacencyMatrix)
{
	ifstream graphFileStream;
	graphFileStream.open("grapgh.txt");

	if (!graphFileStream.is_open())
	{
		cout << "Error open file" << endl;
		return false;
	}

	string firstLine;
	getline(graphFileStream, firstLine);

	stringstream sStream(firstLine);

	int vertexCount;
	sStream >> vertexCount;
	if (vertexCount < 1 || vertexCount > 400)
	{
		cout << "Wrong vertex count" << endl;
		return false;
	}

	adjacencyMatrix.resize(vertexCount);

	if (!graphFileStream.good())
	{
		cout << "error while read second row" << endl;
		return false;
	}
	for (int i = 0; i < vertexCount; i++)
	{
		adjacencyMatrix[i].resize(vertexCount);
		string tempString;
		getline(graphFileStream, tempString);
		sStream.clear();
		sStream.str(tempString);
		for (int j = 0; j < vertexCount; j++)
		{
			if (!sStream.good())
			{
				cout << "Bad row" << i + 2 << endl;
				return false;
			}

			sStream >> adjacencyMatrix[i][j];
		}
	}

	return true;
}