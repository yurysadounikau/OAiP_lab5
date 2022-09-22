#include <iostream>				À¿¡¿ 5.3
#include <time.h>


int main()
{
	srand(time(NULL));

	int** a;

	int rows = 0;
	std::cout << "Enter the number of rows: ";
	std::cin >> rows;
	std::cout << std::endl;

	a = new int*[rows];

	int colums = 0;
	std::cout << "Enter the number of colums: ";
	std::cin >> colums;
	
	std::cout << std::endl;

	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[colums];
	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			a[i][j] = -(colums*rows) + rand() % (colums * rows*2);
		}
	}


	std::cout << "The matrix looks like this: " << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	bool here = false;
	for (int i = 0; i < rows; i++)
	{
		int k = 0;
		for (int j = 0; j < colums; j++)
		{
			if (a[i][j] == 0)
			{
				k++;
			}
		}
		if (k == 0)
		{
			here = true;
			break;
		}
	}


	if (here)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
			{
				if (a[i][j] < 0)
				{
					a[i][j] = 0;
				}
			}
		}
	}



	std::cout << "The new matrix looks like this: " << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}



	for (int i = 0; i < rows; i++)
	{
		delete[]a[i];
	}
	return 0;

}