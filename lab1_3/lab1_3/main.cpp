#include <cstdlib>
#include <iostream>
#include <ctime>
#include <functional>
#include <vector>

/**
* time without print
* N = 10: 0.043
*/

using namespace std;

void printArr(const vector<int> arr, int N);
void generateTuples(const int N, const int k);
void executeFunctionWithTimeLog(function<void()> funcToExecute);

int main(int argc, char* argv[])
{
	int N = 10;//atoi(argv[1]);
	int k = 5;

	function<void()> func = bind(generateTuples, N, k);
	executeFunctionWithTimeLog(func);

	std::getchar();
}

bool nextTuple(vector<int>& P, int N, int k)
{
	int j;
	do
	{
		j = N - 2;
		while (j != -1 && P[j] >= P[j + 1])
		{
			j--;
		}

		if (j == -1)
		{
			return false;
		}

		int tempIndex = N - 1;
		while (P[j] >= P[tempIndex])
		{
			tempIndex--;
		}
		swap(P[j], P[tempIndex]);

		int leftIndex = j + 1;
		int rightIndex = N - 1;
		while (leftIndex < rightIndex)
		{
			swap(P[leftIndex], P[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	} while (j > k - 1);
	return true;
}

void generateTuples(const int N, const int k)
{
	vector<int> P(N);

	for (int i = 0; i < N; i++)
	{
		P[i] = i + 1;
	}

	printArr(P, k);

	while (nextTuple(P, N, k))
	{
		printArr(P, k);
	}
}

void executeFunctionWithTimeLog(function<void()> funcToExecute)
{
	std::clock_t clock;
	double duration;
	clock = std::clock();

	funcToExecute();

	duration = (std::clock() - clock) / static_cast<double>(CLOCKS_PER_SEC);

	std::cout << "Time: " << duration << '\n';
}

void printArr(const vector<int> arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}