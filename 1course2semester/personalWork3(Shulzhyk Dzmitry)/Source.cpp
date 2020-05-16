#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "SetMatrix.h"

using namespace std;

void console();
void matrixToBin(char*, char*);
void matrixFromToBin(char*, char*, char*);
void displayBinMatrix(char*);
void displayBinSet(char*);
int** createMatrix(int, int);
void initializationMatrix(int**, int, int);
void displayMatrix(int**, int, int);
void deleteMemory(int**, int);

const int rows = 5;
const int columns = 4;
const int quantity = 5;

int main()
{
	console();
}

void console()
{

	char file1[16] = "file1.bin";
	char file2[16] = "file2.bin";
	char file3[16] = "file3.bin";
	//matrixToBin(file1, file2);
	matrixFromToBin(file1, file2, file3);
	displayBinSet(file3);
}
void matrixToBin(char* file1, char* file2)
{
	ofstream to1(file1, ios::binary | ios::app), to2(file2, ios::binary | ios::app);

	if (!to1.is_open() || !to2.is_open())
	{
		throw std::invalid_argument("File isn't open.");
	}
	int** bufferMatrix1 = createMatrix(rows, columns);
	int** bufferMatrix2 = createMatrix(columns, 1);
	int bufferSize = sizeof(Matrix);
	for (int i = 0; i < quantity; ++i)
	{
		initializationMatrix(bufferMatrix1, rows, columns);
		initializationMatrix(bufferMatrix2, columns, 1);
		Matrix Matrix1(bufferMatrix1, rows, columns);
		Matrix Matrix2(bufferMatrix1, columns, 1);
		to1.write((char*)&Matrix1, bufferSize);
		to2.write((char*)&Matrix2, bufferSize);
	}
	to1.close();
	to2.close();
	deleteMemory(bufferMatrix1, rows);
	deleteMemory(bufferMatrix2, rows);
}
void matrixFromToBin(char* file1, char* file2, char* file3)
{
	ifstream from1(file1, ios::binary), from2(file2, ios::binary);
	ofstream to(file3, ios::binary | ios::app);

	if (!from1.is_open() || !from2.is_open() || !to.is_open())
	{
		throw std::invalid_argument("File isn't open.");
	}
	Matrix matrix1(rows, columns), matrix2(columns, 1), matrix3(columns, 1), buffer(rows, columns);
	int bufferSize = sizeof(Matrix);
	while (from1.read((char*)&matrix1, bufferSize))
	{
		from2.read((char*)&matrix2, bufferSize);
		buffer = matrix1;
		matrix3 = buffer * matrix2;
		SetMatrix set(matrix1, matrix2, matrix3);
		int bufferSizeSet = sizeof(SetMatrix);
		to.write((char*)&set, bufferSizeSet);
	}
	from1.close();
	from2.close();
	to.close();
}
void displayBinMatrix(char* path)
{
	ifstream from(path, ios::binary);
	if (!from.is_open())
	{
		throw std::invalid_argument("File isnt't open");
	}
	Matrix matrix(rows, columns);
	int bufferSize = sizeof(Matrix);
	while (from.read((char*)&matrix, bufferSize))
	{
		cout << matrix << endl;
	}
	from.close();
}
void displayBinSet(char* path)
{
	ifstream from(path, ios::binary);
	if (!from.is_open())
	{
		throw std::invalid_argument("File isnt't open");
	}

	SetMatrix set;
	int bufferSize = sizeof(SetMatrix);
	while (from.read((char*)&set, bufferSize))
	{
		cout << set << endl;
	}
	from.close();
}
int** createMatrix(int rows, int columns)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[columns];
	}
	return matrix;
}
void initializationMatrix(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = rand() % 10;
		}
	}
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
void deleteMemory(int** matrix, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}