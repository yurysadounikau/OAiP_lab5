#include <iostream>		À¿¡¿ 5.1
#include <stdlib.h>
#include <time.h>

int main()
{

	srand(time(NULL));


	float** a;

	std::cout << "Enter the number of rows: ";
	int n = 0;
	std::cin >> n;

	std::cout << "Enter the number of colums: ";
	int m = 0;
	std::cin >> m;
	std::cout << std::endl;


	a = new float* [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new float[m];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % (n * m);
		}
	}



	std::cout << "The matrix looks like this: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;


	for (int i = 0; i < n; i++)
	{
		int max = 0;
		int min = 0;

		for (int j = 0; j < m; j++)
		{

			if (a[i][j] > a[i][max])
			{
				max = j;
			}

			if (a[i][j] < a[i][min])
			{
				min = j;
			}

		}

		int buff = a[i][max];
		a[i][max] = a[i][min];
		a[i][min] = buff;

	}


	std::cout << "The matrix looks like this: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i;
		sum += a[i][j];
	}
	std::cout << "The sum of the elements on the main diagonal is: " << sum;



	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
	}


	return 0;
}