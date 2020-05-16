#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int rows, int columns)
{
	validation(rows, columns);
	this->rows = rows;
	this->columns = columns;
	for (int i = 0; i < rows * columns; ++i)
	{
		matrix[i] = 0;
	}
}

void Matrix::setMatrix(int* array, int rows, int columns)
{
	validation(rows, columns);
	this->rows = rows;
	this->columns = columns;
	for (int i = 0; i < rows * columns; ++i)
	{
		this->matrix[i] = array[i];
	}
}

Matrix::Matrix(int* array, int rows, int columns)
{
	setMatrix(array, rows, columns);
}

Matrix::Matrix(int** matrix, int rows, int columns)
{
	setMatrix(matrix, rows, columns);
}

Matrix::Matrix(const Matrix& other)
{
	this->rows = other.rows;
	this->columns = other.columns;
	for (int i = 0; i < rows * columns; ++i)
	{
		this->matrix[i] = other.matrix[i];
	}
}

int* Matrix::productMatrix(int* lhs, int* rhs, int lhsRows, int lhsColumns, int rhsRows, int rhsColumns)
{
	if (lhsColumns != rhsRows)
	{
		throw std::invalid_argument("Such matricec cannot be multiplied.");
	}
	int* result = new int[lhsRows * rhsColumns]{ 0 };
	for (int i = 0; i < lhsRows; i++)
	{
		for (int j = 0; j < rhsColumns; j++)
		{
			for (int k = 0; k < lhsColumns; k++)
			{
				result[i * rhsColumns + j] += lhs[i * lhsColumns + k] * rhs[k * rhsColumns + j];
			}
		}
	}
	return result;
}

void Matrix::validation(int rows, int columns)
{
	if (rows < 0 || columns < 0)
	{
		throw std::invalid_argument("This matrix doesn't exist.");
	}
}

int* Matrix::transformMatrix(int** matrix, int rows, int columns)
{
	int* array = new int[rows * columns]{ 0 };
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			array[i * columns + j] = matrix[i][j];
		}
	}
	return array;
}

void Matrix::setMatrix(int** matrix, int rows, int columns)
{
	validation(rows, columns);
	this->rows = rows;
	this->columns = columns;
	int* array = new int[rows * columns]{ 0 };
	array = transformMatrix(matrix, rows, columns);
	for (int i = 0; i < rows * columns; ++i)
	{
		this->matrix[i] = array[i];
	}
	delete[] array;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	this->rows = other.rows;
	this->columns = other.columns;
	for (int i = 0; i < rows * columns; ++i)
	{
		this->matrix[i] = other.matrix[i];
	}
	return *this;
}

Matrix& Matrix:: operator*(const Matrix& rhs)
{
	int* buffer = new int[rhs.rows * rhs.columns]{ 0 };
	for (int i = 0; i < rhs.rows * rhs.columns; ++i)
	{
		buffer[i] = rhs.matrix[i];
	}
	int* result = new int[this->rows * rhs.columns]{ 0 };
	result = productMatrix(this->matrix, buffer, this->rows, this->columns, rhs.rows, rhs.columns);
	setMatrix(result, this->rows, rhs.columns);
	delete[] result, buffer;
	return *this;
}

ostream& operator<<(ostream& stream, Matrix& matrix)
{
	for (int i = 0; i < matrix.rows; ++i)
	{
		for (int j = 0; j < matrix.columns; ++j)
		{
			stream.width(4);
			stream << matrix.matrix[i * matrix.columns + j];
		}
		stream << endl;
	}
	return stream;
}

istream& operator>>(istream& stream, Matrix& matrix)
{
	int n = matrix.rows * matrix.columns;
	for (int i = 0; i < n; ++i)
	{
		stream >> matrix.matrix[i];
	}
	return stream;
}
