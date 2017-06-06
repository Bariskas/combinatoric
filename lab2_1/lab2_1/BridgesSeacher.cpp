#include "BridgesSeacher.h"
#include <algorithm>

using namespace std;

CBridgesSeacher::CBridgesSeacher(std::vector<std::vector<int>> grapgh)
	: m_grapgh(grapgh)
{
	size_t matrixSize = m_grapgh.size();
	m_usedVertexes = vector<bool>(matrixSize, false);
	m_timerIn.resize(matrixSize);
	m_timerUp.resize(matrixSize);
}

std::vector<std::pair<int, int>> CBridgesSeacher::FindBridges()
{
	for (size_t i = 0; i < m_grapgh.size(); ++i)
	{
		if (!m_usedVertexes[i])
		{
			ProcessVertex(i, -1);
		}
	}

	return m_bridges;
}

void CBridgesSeacher::ProcessVertex(int vertex, int parent)
{
	m_usedVertexes[vertex] = true;
	m_timerIn[vertex] = m_timerUp[vertex] = m_timer++;
	for (size_t i = 0; i < m_grapgh[vertex].size(); ++i)
	{
		int to = m_grapgh[vertex][i];
		if (to == parent)
		{
			continue;
		}
		if (m_usedVertexes[to])
		{
			m_timerUp[vertex] = min(m_timerUp[vertex], m_timerIn[to]);
		}
		else
		{
			ProcessVertex(to, vertex);
			m_timerUp[vertex] = min(m_timerUp[vertex], m_timerUp[to]);
			if (m_timerUp[to] > m_timerIn[vertex])
			{
				m_bridges.push_back(pair<int, int>(vertex, to));
			}
		}
	}
}
