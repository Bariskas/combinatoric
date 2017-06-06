#pragma once
#include <vector>

class CBridgesSeacher
{
public:
	CBridgesSeacher(std::vector<std::vector<int>> grapgh);
	std::vector<std::pair<int, int>> FindBridges();
private:
	void ProcessVertex(int vertex, int parent);
private:
	std::vector<std::vector<int>> m_grapgh;
	std::vector<std::pair<int, int>> m_bridges;
	std::vector<bool> m_usedVertexes;
	std::vector<int> m_timerIn;
	std::vector<int> m_timerUp;
	int m_timer;
};
