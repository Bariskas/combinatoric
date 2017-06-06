#include "CutPointsSeacher.h"
#include <algorithm>

using namespace std;

CCutPointsSeacher::CCutPointsSeacher(std::vector<std::vector<int>> grapgh)
	: m_grapgh(grapgh), m_timer(0)
{
	size_t matrixSize = m_grapgh.size();
	m_usedVertexes = vector<bool>(matrixSize, false);
	m_timerIn.resize(matrixSize);
	m_timerUp.resize(matrixSize);
}

std::vector<int> CCutPointsSeacher::FindArticulationPoints()
{
	ProcessVertex(0, -1);

	return m_cutPoints;
}

void CCutPointsSeacher::ProcessVertex(int vertex, int parent)
{
	m_usedVertexes[vertex] = true;
	m_timerIn[vertex] = m_timerUp[vertex] = m_timer++;
	int children = 0;
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
			if (m_timerUp[to] >= m_timerIn[vertex] && parent != -1)
			{
				m_cutPoints.push_back(vertex);
			}
			++children;
		}
	}
	if (parent == -1 && children > 1)
	{
		m_cutPoints.push_back(vertex);
	}
}