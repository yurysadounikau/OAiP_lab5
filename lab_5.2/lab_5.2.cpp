

#include <iostream>			
#include <time.h>


int main()
{
	srand(time(NULL));


	int** a;


	int rows = 0;
	std::cout << "Enter the number of rows: ";
	std::cin >> rows;
	std::cout << std::endl;


	a = new int* [rows];


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
			a[i][j] = -(colums * rows) +  rand() % (colums * rows * 2);
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


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums - 1; j++)
		{
			for (int k = 0; k < rows; k++)				
			{
				if (a[k][j] > a[k][j + 1])
				{
					int temp = a[k][j];
					a[k][j] = a[k][j + 1];
					a[k][j + 1] = temp;				
				}
			}
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



	int f_colum = 0;
	bool bz = true;
	for (int i = 0; i < colums; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (a[i][j] < 0)
			{
				bz = false;
			}
		}
		if (bz)
		{
			f_colum = i;
			break;
		}
	}


	if (bz)
	{
		std::cout << "The number of the first column that does not contain negative elements is equal to: " << f_colum << std::endl;
	}
	else
	{
		std::cout << "There is no column that does not contain negative elements." << std::endl;
	}


	for (int i = 0; i < rows; i++)
	{
		delete[]a[i];
	}

	return 0;
}
