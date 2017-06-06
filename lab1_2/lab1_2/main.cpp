#include <cstdlib>
#include <iostream>
#include <ctime>
#include <functional>

/**
 * k = 5;
 * time without print, time with print
 * N = 10: 0.000 0.416
 * N = 15: 0.000 5.282
 * N = 20: 0.000 5.254
 * N = 25: 0.000 5.222
*/

using namespace std;

void printArr(const int arr[], int N);
void generateCombinations(const int N, const int k);
void executeFunctionWithTimeLog(function<void()> funcToExecute);

int main(int argc, char* argv[])
{
	int N = 15;//atoi(argv[1]);
	int k = 5;

	executeFunctionWithTimeLog(bind(generateCombinations, N, k));

	std::getchar();
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

void generateCombinations(const int N, const int k)
{
	int* c = new int[k + 1];
	c[0] = -1;
	for (int i = 1; i <= k; i++)
	{
		c[i] = i;
	}

	int j = 1;
	while (j != 0)
	{
		printArr(c, k);
		j = k;
		while(c[j] == N - k + j)
		{
			--j;
		}
		++c[j];
		for (int i = j + 1; i <= k; i++)
		{
			c[i] = c[i - 1] + 1;
		}
	}
}

void printArr(const int arr[], int arrSize)
{
	for (int i = 1; i <= arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}