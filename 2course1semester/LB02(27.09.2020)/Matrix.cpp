#include "Matrix.h"

Matrix::Matrix(int size)
{
	this->size = size;
	this->matrix = new int[size * size];
	for (int i = 0; i < size * size; ++i)
	{
		this->matrix[i] = 0;
	}
}

Matrix::Matrix(int** matrix, int size)
{
	setMatrix(matrix, size);
}

Matrix::Matrix(const Matrix& matrix)
{
	*this = matrix;
}

void Matrix::setMatrix(int** matrix, int size)
{
	validation(size);
	if (!this->matrix)
	{
		delete[] this->matrix;
	}
	this->size = size;
	this->matrix = new int[size * size];
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			this->matrix[i * size + j] = matrix[i][j];
		}
	}
}

int** Matrix::getMatrix(int& size) const
{
	size = this->size;
	int** buffer = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		buffer[i] = new int[size] {0};
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			buffer[i][j] = matrix[i * size + j];
		}
	}
	return buffer;
}

int Matrix::getSize() const
{
	return size;
}

int Matrix::det()
{
	int** buffer = transform(matrix, size);
	int det = determinant(buffer, size);
	for (int i = 0; i < size; ++i)
	{
		delete[] buffer[i];
	}
	delete[] buffer;
	return det;
}

bool Matrix::operator==(const Matrix& matrix)
{
	if (this->size != size)
	{
		return false;
	}
	for (int i = 0; i < size * size; ++i)
	{
		if (this->matrix[i] != matrix.matrix[i])
		{
			return false;
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
	if (this->size != matrix.getSize())
	{
		throw std::invalid_argument("Error");
	}
	this->matrix = product(this->matrix, matrix.matrix, size);
	return *this;
}

Matrix Matrix::operator-(const Matrix& matrix)
{
	Matrix copy = *this;
	return copy -= matrix;
}

Matrix Matrix::operator-=(const Matrix& matrix)
{
	if (this->size != matrix.getSize())
	{
		throw std::invalid_argument("Error");
	}
	this->matrix = difference(this->matrix, matrix.matrix, size);
	return *this;
}

Matrix Matrix::operator+(const Matrix& matrix)
{
	Matrix copy = *this;
	return copy += matrix;
}

Matrix Matrix::operator+=(const Matrix& matrix)
{
	if (this->size != matrix.getSize())
	{
		throw std::invalid_argument("Error");
	}
	this->matrix = sum(this->matrix, matrix.matrix, size);
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
		delete[] this->matrix;
	}
	this->size = matrix.getSize();
	this->matrix = new int[size * size];
	for (int i = 0; i < size * size; ++i)
	{
		this->matrix[i] = matrix.matrix[i];
	}
	return *this;
}

Matrix::~Matrix()
{
	delete[] matrix;
}

int* Matrix::product(int* lhs, int* rhs, int size)
{
	int* product = new int[size * size]{ 0 };
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			for (int k = 0; k < size; ++k)
			{
				product[i * size + j] += lhs[i * size + k] * rhs[k * size + j];
			}
		}
	}

	return product;
}

int* Matrix::sum(int* lhs, int* rhs, int size)
{
	int* sum = new int[size * size]{ 0 };
	for (int i = 0; i < size * size; ++i)
	{
		sum[i] = lhs[i] + rhs[i];
	}

	return sum;
}

int* Matrix::difference(int* lhs, int* rhs, int size)
{
	int* difference = new int[size * size]{ 0 };
	for (int i = 0; i < size * size; ++i)
	{
		difference[i] = lhs[i] - rhs[i];
	}

	return difference;
}

void Matrix::validation(int number)
{
	if (number < 0)
	{
		throw std::invalid_argument("Error");
	}
}

int** Matrix::transform(int* array, int size)
{
	int** buffer = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		buffer[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			buffer[i][j] = array[i * size + j];
		}
	}

	return buffer;
}

int Matrix::determinant(int** array, int size)
{
	if (size == 2)
	{
		return(array[0][0] * array[1][1] - array[0][1] * array[1][0]);
	}
	else if (size == 1)
	{
		return array[0][0];
	}
	else if (size >= 3)
	{
		int** buffer = new int* [size - 1];
		for (int i = 0; i < size - 1; ++i)
		{
			buffer[i] = new int[size - 1];
		}

		int det = 0;
		int a, b;

		for (int i = 0; i < size; ++i)
		{
			a = 0;
			for (int j = 1; j < size; ++j)
			{
				b = 0;
				for (int k = 0; k < size; ++k)
				{
					if (k != i)
					{
						buffer[a][b] = array[j][k];
						++b;
					}
				}
				++a;
			}
			det += pow(-1, (double)i + 2) * array[0][i] * determinant(buffer, size - 1);
		}
		return det;
	}
}

ostream& operator<<(ostream& stream, const Matrix& matrix)
{
	int size = matrix.getSize();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			stream << matrix.matrix[i * size + j] << " ";
		}
		stream << endl;
	}
	return stream;
}

istream& operator>>(istream& stream, Matrix& matrix)
{
	int size = matrix.getSize() * matrix.getSize();
	for (int i = 0; i < size; ++i)
	{
		stream >> matrix.matrix[i];
	}
	return stream;
}
