#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[columns];
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			this->matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int** matrix, int rows, int columns)
{
	setMatrix(matrix, rows, columns);
}

Matrix::Matrix(const Matrix& matrix)
{
	*this = matrix;
}

void Matrix::setMatrix(int** matrix, int rows, int columns)
{
	validation(rows, columns);
	if (!this->matrix)
	{
		for (int i = 0; i < this->rows; ++i)
		{
			delete[] this->matrix[i];
		}
		delete[] this->matrix;
	}
	this->rows = rows;
	this->columns = columns;
	this->matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		this->matrix[i] = new int[columns];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

int** Matrix::getMatrix(int& rows, int& columns) const
{
	rows = this->rows;
	columns = this->columns;
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		buffer[i] = new int[columns] {0};
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			buffer[i][j] = matrix[i][j];
		}
	}
	return buffer;
}

void Matrix::getRowsAndColumns(int& rows, int& columns) const
{
	rows = this->rows;
	columns = this->columns;
}

bool Matrix::operator==(const Matrix& matrix)
{
	if (this->rows != matrix.rows || this->columns != matrix.columns)
	{
		return false;
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (this->matrix[i][j] != matrix.matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

Matrix Matrix::operator*(const Matrix& matrix)
{
	Matrix copy = *this;
	return copy *= matrix;
}

Matrix Matrix::operator*=(const Matrix& matrix)
{
	setMatrix(product(this->matrix, matrix.matrix, this->rows, this->columns, matrix.rows, matrix.columns),this->rows,matrix.columns);
	return *this;
}

Matrix Matrix::operator-(const Matrix& matrix)
{
	Matrix copy = *this;
	return copy -= matrix;
}

Matrix Matrix::operator-=(const Matrix& matrix)
{
	this->matrix = difference(this->matrix, matrix.matrix, this->rows, this->columns, matrix.rows, matrix.columns);
	return *this;
}

Matrix Matrix::operator+(const Matrix& matrix)
{
	Matrix copy = *this;
	return copy += matrix;
}

Matrix Matrix::operator+=(const Matrix& matrix)
{
	this->matrix = sum(this->matrix, matrix.matrix, this->rows, this->columns, matrix.rows, matrix.columns);
	return *this;
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (&matrix == this)
	{
		return *this;
	}
	if (!this->matrix)
	{
		for (int i = 0; i < this->rows; ++i)
		{
			delete[] this->matrix[i];
		}
		delete[] this->matrix;
	}
	this->rows = matrix.rows;
	this->columns = matrix.columns;

	this->matrix = new int* [rows];
	for (int i = 0; i <rows; ++i)
	{
		this->matrix[i] = new int[columns] {0};
	}

	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->columns; ++j)
		{
			this->matrix[i][j]=matrix.matrix[i][j];
		}
	}
	
	return *this;
}

Matrix::~Matrix()
{
	if (this->matrix)
	{
		for (int i = 0; i < rows; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}

int** Matrix::product(int** lhs, int** rhs, int lhsRows, int lhsColumns, int rhsRows, int rhsColumns)
{
	if (lhsColumns != rhsRows)
	{
		throw std::invalid_argument("Error");
	}
	int** product = new int* [lhsRows];
	for (int i = 0; i < lhsRows; ++i)
	{
		product[i] = new int[rhsColumns] {0};
	}
	for (int i = 0; i < lhsRows; ++i)
	{
		for (int j = 0; j < rhsColumns; ++j)
		{
			for (int k = 0; k < lhsColumns; ++k)
			{
				product[i][j] += lhs[i][k] * rhs[k][j];
			}
		}
	}

	return product;
}

int** Matrix::sum(int** lhs, int** rhs, int lhsRows, int lhsColumns, int rhsRows, int rhsColumns)
{
	if (lhsRows != rhsRows || lhsColumns != rhsColumns)
	{
		throw std::invalid_argument("Error");
	}

	int** sum = new int* [rhsRows];

	for (int i = 0; i < rhsRows; ++i)
	{
		sum[i] = new int[rhsColumns] {0};
	}

	for (int i = 0; i < rhsRows; ++i)
	{
		for (int j = 0; j < rhsColumns; ++j)
		{
			sum[i][j] = lhs[i][j] + rhs[i][j];
		}
	}
	return sum;
}

int** Matrix::difference(int** lhs, int** rhs, int lhsRows, int lhsColumns, int rhsRows, int rhsColumns)
{
	if (lhsRows != rhsRows || lhsColumns != rhsColumns)
	{
		throw std::invalid_argument("Error");
	}

	int** difference = new int* [rhsRows];

	for (int i = 0; i < rhsRows; ++i)
	{
		difference[i] = new int[rhsColumns] {0};
	}

	for (int i = 0; i < rhsRows; ++i)
	{
		for (int j = 0; j < rhsColumns; ++j)
		{
			difference[i][j] = lhs[i][j] - rhs[i][j];
		}
	}

	return difference;
}

void Matrix::validation(int number1, int number2)
{
	if (number1 < 0 || number2 < 0)
	{
		throw std::invalid_argument("Error");
	}
}

ostream& operator<<(ostream& stream, const Matrix& matrix)
{
	int rows = 0, columns = 0;
	matrix.getRowsAndColumns(rows, columns);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			stream << matrix.matrix[i][j] << " ";
		}
		stream << endl;
	}
	return stream;
}

istream& operator>>(istream& stream, Matrix& matrix)
{
	int rows = 0, columns = 0;
	matrix.getRowsAndColumns(rows, columns);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			stream >> matrix.matrix[i][j];
		}
	}
	return stream;
}

