#pragma once
#include <vector>

class CCutPointsSeacher
{
public:
	CCutPointsSeacher(std::vector<std::vector<int>> grapgh);
	std::vector<int> FindArticulationPoints();
private:
	void ProcessVertex(int vertex, int parent);
private:
	std::vector<int> m_cutPoints;
	std::vector<std::vector<int>> m_grapgh;
	std::vector<bool> m_usedVertexes;
	std::vector<int> m_timerIn;
	std::vector<int> m_timerUp;
	int m_timer;
};
