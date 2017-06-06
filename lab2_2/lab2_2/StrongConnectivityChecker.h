#include <vector>

class CStrongConnectivityChecker
{
public:
	CStrongConnectivityChecker(std::vector<std::vector<int>> matrix);
	bool Check();
private:
	void FirstDfs(int vertex);
	void SecondDfs(int vertex);
	void InitTransposedGraph();
private:
	std::vector<std::vector<int>> m_grapgh;
	std::vector<std::vector<int>> m_transposedGraph;
	std::vector<char> m_used;
	std::vector<int> m_order;
	std::vector<int> m_component;
};
