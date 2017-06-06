#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // min
#include "CutPointsSeacher.h"
#include "BridgesSeacher.h"

using namespace std;

int InitGraph(vector<vector<int>>& adjacencyMatrix)
{
	ifstream graphFileStream;
	graphFileStream.open("grapgh.txt");

	if (!graphFileStream.is_open())
	{
		cout << "Error open file" << endl;
		return 1;
	}

	string firstLine;
	getline(graphFileStream, firstLine);

	stringstream sStream(firstLine);

	int vertixCount;
	int edgeCount;
	sStream >> vertixCount;
	if (sStream.good())
	{
		sStream >> edgeCount;
	}
	else
	{
		cout << "wrong first row second argument" << endl;
		return 1;
	}

	adjacencyMatrix.resize(vertixCount);

	if (!graphFileStream.good())
	{
		cout << "error while read second row" << endl;
		return 1;
	}
	for (int i = 0; i < edgeCount; i++)
	{
		int firstVertix;
		int secondVertix;

		string tempString;
		getline(graphFileStream, tempString);
		sStream.clear();
		sStream.str(tempString);
		sStream >> firstVertix;

		if (firstVertix >= vertixCount)
		{
			cout << firstVertix << " wrong index of vertix in row" << i + 2 << endl;
			return 1;
		}

		if (sStream.good())
		{
			sStream >> secondVertix;
		}
		else
		{
			cout << "wrong " << i + 2 << " row structure" << endl;
			return 1;
		}

		if (secondVertix >= vertixCount)
		{
			cout << firstVertix << " wrong index of vertix in row " << i + 2 << endl;
			return 1;
		}

		adjacencyMatrix[firstVertix].push_back(secondVertix);
		adjacencyMatrix[secondVertix].push_back(firstVertix);
	}

	return 0;
}

int main(int argc, char** argv[])
{
	vector<vector<int>> graph;
	InitGraph(graph);

	CCutPointsSeacher cutPointsSeacher(graph);
	vector<int> articularPoints = cutPointsSeacher.FindArticulationPoints();

	CBridgesSeacher bridgesSeacher(graph);
	vector<pair<int, int>> bridges = bridgesSeacher.FindBridges();
	
	cout << "Cut points:" << endl;
	for (size_t i = 0; i < articularPoints.size(); ++i)
	{
		cout << articularPoints[i] << " ";
	}
	cout << endl;

	cout << "Bridges:" << endl;
	for (size_t i = 0; i < bridges.size(); ++i)
	{
		cout << bridges[i].first << "-" << bridges[i].second << " ";
	}
	cout << endl;

	getchar();
}