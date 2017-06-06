#include "StrongConnectivityChecker.h"
#include <iostream>

using namespace std;

CStrongConnectivityChecker::CStrongConnectivityChecker(vector<vector<int>> matrix)
	: m_grapgh(matrix)
{
	InitTransposedGraph();
}

void CStrongConnectivityChecker::InitTransposedGraph()
{
	m_transposedGraph = vector<vector<int>>(m_grapgh.size(), vector<int>(m_grapgh.size()));
	for (size_t i = 0; i < m_grapgh.size(); ++i)
	{
		for (size_t j = 0; j < m_grapgh[i].size(); ++j)
		{
			m_transposedGraph[j][i] = m_grapgh[i][j];
		}
	}
}

void CStrongConnectivityChecker::FirstDfs(int vertex)
{
	m_used[vertex] = true;
	for (size_t i = 0; i < m_grapgh[vertex].size(); ++i)
	{
		if (!m_used[i] && m_grapgh[vertex][i] != 0)
		{
			FirstDfs(i);
		}
	}
	m_order.push_back(vertex);
}

void CStrongConnectivityChecker::SecondDfs(int vertex)
{
	m_used[vertex] = true;
	m_component.push_back(vertex);
	for (size_t i = 0; i < m_transposedGraph[vertex].size(); ++i)
	{
		if (!m_used[i] && m_transposedGraph[vertex][i] != 0)
		{
			SecondDfs(i);
		}
	}
}

bool CStrongConnectivityChecker::Check()
{
	m_used.assign(m_grapgh.size(), false);
	for (size_t i = 0; i < m_grapgh.size(); ++i)
	{
		if (!m_used[i])
		{
			FirstDfs(i);
		}
	}

	m_used.assign(m_grapgh.size(), false);
	SecondDfs(m_order[m_grapgh.size() - 1]);

	return m_component.size() == m_grapgh.size();
}