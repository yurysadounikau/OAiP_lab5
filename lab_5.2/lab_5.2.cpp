//
//
//#include <iostream>			
//#include <time.h>
//
//
//int main()
//{
//	srand(time(NULL));
//
//
//	int** a;
//
//
//	int rows = 0;
//	std::cout << "Enter the number of rows: ";
//	std::cin >> rows;
//	std::cout << std::endl;
//
//
//	a = new int* [rows];
//
//
//	int colums = 0;
//	std::cout << "Enter the number of colums: ";
//	std::cin >> colums;
//	std::cout << std::endl;
//
//
//	for (int i = 0; i < rows; i++)
//	{
//		a[i] = new int[colums];
//	}
//
//
//	int* spectr;
//
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < colums; j++)
//		{
//			a[i][j] = -(colums * rows) +  rand() % (colums * rows * 2);
//		}
//	}
//
//
//	std::cout << "The matrix looks like this: " << std::endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < colums; j++)
//		{
//			std::cout << a[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
//
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < colums - 1; j++)
//		{
//			for (int k = 0; k < rows; k++)				
//			{
//				if (a[k][j] > a[k][j + 1])
//				{
//					int temp = a[k][j];
//					a[k][j] = a[k][j + 1];
//					a[k][j + 1] = temp;				
//				}
//			}
//		}
//	}
//
//
//
//
//	std::cout << "The matrix looks like this: " << std::endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < colums; j++)
//		{
//			std::cout << a[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
//
//
//
//	int f_colum = 0;
//	bool bz = true;
//	for (int i = 0; i < colums; i++)
//	{
//		for (int j = 0; j < rows; j++)
//		{
//			if (a[i][j] < 0)
//			{
//				bz = false;
//			}
//		}
//		if (bz)
//		{
//			f_colum = i;
//			break;
//		}
//	}
//
//
//	if (bz)
//	{
//		std::cout << "The number of the first column that does not contain negative elements is equal to: " << f_colum << std::endl;
//	}
//	else
//	{
//		std::cout << "There is no column that does not contain negative elements." << std::endl;
//	}
//
//
//	for (int i = 0; i < rows; i++)
//	{
//		delete[]a[i];
//	}
//
//	return 0;
//}




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
	std::cin >> ROWS;
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
	std::cout<<"Number of repeated elements in a string: " << std::endl;
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
		std::cout<<eq[i] << std::endl;;
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