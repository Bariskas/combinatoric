#include <cstdlib>
#include <iostream>
#include <ctime>
#include <functional>

using namespace std;

void printArr(const int arr[], int N);
void generateRandomPermutation(const int N);
void executeFunctionWithTimeLog(function<void()> funcToExecute);

int main(int argc, char* argv[])
{
	int N = 10;//atoi(argv[1]);

	srand(unsigned(time(0)));
	executeFunctionWithTimeLog(bind(generateRandomPermutation, N));

	std::getchar();
}

void generateRandomPermutation(const int N)
{
	int* permutation = new int[N];
	for (int i = 0; i < N; i++)
	{
		permutation[i] = i + 1;
	}

	for (int i = 0; i < N - 1; i++)
	{
		swap(permutation[i], permutation[rand() % (N - i) + i]);
	}

	printArr(permutation, N);
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
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}
