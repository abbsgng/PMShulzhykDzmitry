#include  <iostream>
#include "Matrix.h"

using namespace std;

int** createMatrix(int);
void deleteMemory(int**, int);

void initializationMatrixes(Matrix*, int);
Matrix powMatrix(Matrix*, int);

void task();

int main()
{
	Matrix matrix(3);
	cin >> matrix;
	cout << matrix.det();
}

void task()
{
	int count, size, index;
	cout << "Enter the count of matrix:" << endl;
	cin >> count;
	cout << "Enter the size of matrix:" << endl;
	cin >> size;
	Matrix* matrixes = new Matrix[count]{ size };
	initializationMatrixes(matrixes, count);
	for (int i = 0; i < count; ++i)
	{
		cout << matrixes[i] << endl;
	}
	cout << endl;
	cout << "Enter the index:" << endl;
	cin >> index;
	cout << powMatrix(matrixes, index);
	delete[] matrixes;
}

Matrix powMatrix(Matrix* matrix, int index)
{
	return matrix[index] *= matrix[index];
}

void initializationMatrixes(Matrix* matrixes, int count)
{
	int size = matrixes[0].getSize();
	for (int i = 0; i < count; ++i)
	{
		int** buffer = createMatrix(size);
		Matrix Buffer(buffer, size);
		matrixes[i] = Buffer;
		deleteMemory(buffer, size);
	}
}

int** createMatrix(int size)
{
	int** matrix = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = rand() % 10;
		}
	}

	return matrix;
}

void deleteMemory(int** source, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[]  source[i];
	}
	delete[] source;
}