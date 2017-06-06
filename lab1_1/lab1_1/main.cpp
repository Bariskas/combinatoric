#include <cstdlib>
#include <iostream>
#include <ctime>
#include <functional>

/**
 * time without print
 * N = 10: 0.043 
 * N = 11: 0.469 
 * N = 12: 5.426
 * N = 13: 70.8
 * N = 14: 940.809
 */

using namespace std;

void printArr(const int arr[], int N);
void generatePermutations(const int N);
void executeFunctionWithTimeLog(function<void()> funcToExecute);

int main(int argc, char* argv[])
{ 
	int N = 14;//atoi(argv[1]);

	executeFunctionWithTimeLog(bind(generatePermutations, N));

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

void printArr(const int arr[], int N)
{
	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

void generatePermutations(const int N)
{
	int* P = new int[N + 2];
	int* p = new int[N + 2];
	int* d = new int[N + 2];
	for (int i = 1; i <= N; ++i)
	{
		P[i] = p[i] = i;
		d[i] = -1;
	}
	d[1] = 0;

	int m;
	P[0] = P[N + 1] = m = N + 1;

	while (m != 1)
	{
		//printArr(P, N);

		m = N;
		while (P[p[m] + d[m]] > m)
		{
			d[m] = -d[m];
			m--;
		}

		int pm = p[m];
		int temp = P[pm + d[m]];
		P[pm + d[m]] = P[pm];
		P[pm] = temp;
		temp = p[m];
		p[m] = p[P[pm]];
		p[P[pm]] = temp;
	}
}