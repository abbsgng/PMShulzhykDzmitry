#include <iostream>
#include "Matrix.h"

using namespace std;

template<typename T>
T** createMatrix(int);
template<typename T>
void display(T**, int);
template<typename T>
void deleteMatrix(T**, int);

int main()
{
	char** matrix1 = createMatrix<char>(5);
	display<char>(matrix1, 5);
	cout << endl;
	Matrix<char> generic1(matrix1, 5);
	cout << generic1;
	deleteMatrix<char>(matrix1, 5);
	cout <<"\n"<< endl;

	int** matrix2 = createMatrix<int>(5);
	display<int>(matrix2, 5);
	cout << endl;
	Matrix<int> generic2(matrix2, 5);
	cout << generic2;
	deleteMatrix<int>(matrix2, 5);
	cout << "\n" << endl;

	bool** matrix3 = createMatrix<bool>(5);
	display<bool>(matrix3, 5);
	cout << endl;
	Matrix<bool> generic3(matrix3, 5);
	cout << generic3;
	deleteMatrix<bool>(matrix3, 5);
	return 0;
}

template <typename T>
T** createMatrix(int size)
{
	T** matrix = new T * [size];
	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new T[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = rand() % 100;
		}
	}
	return matrix;
}

template <typename T>
void display(T** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void deleteMatrix(T** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}