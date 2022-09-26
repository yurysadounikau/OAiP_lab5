
#include <iostream>



int main() {
	srand(time(NULL));


	int** matrix;
	int* eq;


	int ROWS = 0;
	std::cout << "Enter the number of rows: ";
	std::cin >> ROWS;
	std::cout << std::endl;


	matrix = new int* [ROWS];
	eq = new int[ROWS];


	int COLUMS = 0;
	std::cout << "Enter the number of colums: ";
	std::cin >> COLUMS;
	std::cout << std::endl;


	for (int i(0); i < ROWS; i++)
	{
		matrix[i] = new int[COLUMS];
	}


	for (int i(0); i < ROWS; i++)
	{
		eq[i] = 0;
	}


	std::cout << "Initial matrix" << std::endl;
	for (int i(0); i < ROWS; i++)
	{
		for (int j(0); j < COLUMS; j++)
		{
			matrix[i][j] = rand() % (COLUMS + ROWS + 1);
		}
	}
	std::cout << std::endl;


	/*for (int i(0); i < ROWS; i++)
	{
		for (int j(0); j < COLUMS; j++)
		{
			std::cin >> matrix[i][j];
		}
	}*/


	for (int i(0); i < ROWS; i++)
	{
		for (int j(0); j < COLUMS; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}


	int counter = 1;
	for (int i(0); i < ROWS; i++)
	{
		for (int j(0); j < COLUMS - 1; j++)
		{
			for (int k(j + 1); k < COLUMS; k++)
			{
				if (matrix[i][j] == matrix[i][k])
				{
					counter++;
				}
			}
			if (counter > eq[i]) eq[i] = counter;
			counter = 1;
		}
	}
	std::cout << "Number of repeated elements in a string: " << std::endl;
	for (int i(0); i < ROWS; i++)
	{
		std::cout << eq[i] << std::endl;
	}
	std::cout << std::endl;


	for (int i(1); i < ROWS; i++)
	{
		for (int j(ROWS - 1); j >= i; j--)
		{
			if (eq[j] < eq[j - 1])
			{
				int temp = 0;
				for (int k(0); k < COLUMS; k++)
				{
					temp = matrix[j][k];
					matrix[j][k] = matrix[j - 1][k];
					matrix[j - 1][k] = temp;
				}
				temp = eq[j];
				eq[j] = eq[j - 1];
				eq[j - 1] = temp;
			}
		}
	}


	std::cout << "Number of repeated elements in a string: " << std::endl;
	for (int i(0); i < ROWS; i++)
	{
		std::cout << eq[i] << std::endl;;
	}
	std::cout << std::endl;


	std::cout << "Sorted matrix" << std::endl;
	for (int i(0); i < ROWS; i++)
	{
		for (int j(0); j < COLUMS; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}


	delete[] eq;
	for (int i(0); i < ROWS; i++)
	{
		delete[]matrix[i];
	}


	return 0;
}