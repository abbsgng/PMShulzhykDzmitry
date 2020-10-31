#include <iostream>
#include "Matrix.h"
#include "BoolMatrix.h"

using namespace std;

int** createMatrix(int, int);
void displayMatrix(int**, int, int);
void deleteMatrix(int**, int, int);

int main()
{
	int** matrix = createMatrix(3, 5);
	displayMatrix(matrix, 3, 5);
	cout << endl;
	BoolMatrix A;
	A.setMatrix(matrix, 3, 5);
	cout << A.A_canonical();
	deleteMatrix(matrix, 3, 5);
}

int** createMatrix(int rows, int columns)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[columns];
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = rand() % 10;
		}
	}
	return matrix;
}

void displayMatrix(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void deleteMatrix(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
