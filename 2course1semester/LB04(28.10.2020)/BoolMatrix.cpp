#include "BoolMatrix.h"

int BoolMatrix::fromBinary(int* source, int size)
{
	int number = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		number += source[i] << size - i - 1;
	}
	return number;
}

int* BoolMatrix::deleteSameElement(int* array, int& size)
{
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (array[i] == array[j])
			{
				for (int k = j; k < size - 1; k++)
					array[k] = array[k + 1];
				size--;
				j = i;
			}
	return array;
}

void BoolMatrix::quickSort(int* array, int size)
{
	int i = 0;
	int j = size - 1;
	int mid = array[size / 2];

	do
	{
		while (array[i] < mid)
		{
			i++;
		}

		while (array[j] > mid)
		{
			j--;
		}

		if (i <= j)
		{
			swap(array[i], array[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		quickSort(array, j + 1);
	}
	if (i < size)
	{
		quickSort(&array[i], size - i);
	}
}

int* BoolMatrix::toBinary(int* array, int size, int number)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = 0;
	}
	int i = 0;
	while (number)
	{
		array[i] = number % 2;
		number = number / 2;
		i++;
	}
	for (int i = 0, j = size - 1; i < size / 2; i++, j--)
	{
		swap(array[i], array[j]);
	}
	return array;
}

BoolMatrix::BoolMatrix(int** matrix, int rows, int columns)
{
	setMatrix(matrix, rows, columns);
}

BoolMatrix::BoolMatrix(const BoolMatrix& Matrix)
{
	*this = Matrix;
}

int BoolMatrix::countOfOne() const
{
	int count = 0, rows = 0, columns = 0;
	int** buffer = getMatrix(rows, columns);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			count += buffer[i][j] ? 1 : 0;
		}
	}
	return count;
}

BoolMatrix BoolMatrix::A_canonical()
{
	int rows = 0, columns = 0;
	int** buffer = getMatrix(rows, columns);
	int* number = new int[rows];
	for (int i = 0; i < rows; ++i)
	{
		number[i] = fromBinary(buffer[i], columns);
	}
	number = deleteSameElement(number, rows);
	quickSort(number, rows);
	for (int i = 0; i < rows; ++i)
	{
		buffer[i] = toBinary(buffer[i], columns, number[i]);
	}
	BoolMatrix A;
	A.setMatrix(buffer, rows, columns);
	delete[] number;
	return A;
}

void BoolMatrix::setMatrix(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			matrix[i][j] = (bool)matrix[i][j];
		}
	}
	Matrix::setMatrix(matrix, rows, columns);
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& Matrix)
{
	BoolMatrix copy = *this;
	return copy &= Matrix;
}

BoolMatrix BoolMatrix::operator&=(const BoolMatrix& Matrix)
{
	int lhsRows = 0, lhsColumns = 0, rhsRows = 0, rhsColumns = 0;
	int** buffer1 = getMatrix(lhsRows, lhsColumns);
	int** buffer2 = Matrix.getMatrix(rhsRows, rhsColumns);
	if (lhsRows != rhsRows || lhsColumns != rhsColumns)
	{
		throw std::invalid_argument("Error");
	}

	for (int i = 0; i < lhsRows; ++i)
	{
		for (int j = 0; j < lhsColumns; ++j)
		{
			buffer1[i][j] = buffer1[i][j] && buffer2[i][j];
		}
	}
	setMatrix(buffer1, lhsRows, lhsColumns);
	for (int i = 0; i < rhsRows; ++i)
	{
		delete[] buffer2[i];
	}
	delete[] buffer2;
	return *this;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& Matrix)
{
	BoolMatrix copy = *this;
	return copy |= Matrix;
}

BoolMatrix BoolMatrix::operator|=(const BoolMatrix& Matrix)
{
	int lhsRows = 0, lhsColumns = 0, rhsRows = 0, rhsColumns = 0;
	int** buffer1 = getMatrix(lhsRows, lhsColumns);
	int** buffer2 = Matrix.getMatrix(rhsRows, rhsColumns);
	if (lhsRows != rhsRows || lhsColumns != rhsColumns)
	{
		throw std::invalid_argument("Error");
	}

	for (int i = 0; i < lhsRows; ++i)
	{
		for (int j = 0; j < lhsColumns; ++j)
		{
			buffer1[i][j] = buffer1[i][j] || buffer2[i][j];
		}
	}
	setMatrix(buffer1, lhsRows, lhsColumns);
	for (int i = 0; i < rhsRows; ++i)
	{
		delete[] buffer2[i];
	}
	delete[] buffer2;
	return *this;
}

BoolMatrix BoolMatrix::operator^(const BoolMatrix& Matrix)
{
	BoolMatrix copy = *this;
	return copy ^= Matrix;
}

BoolMatrix BoolMatrix::operator^=(const BoolMatrix& Matrix)
{
	int lhsRows = 0, lhsColumns = 0, rhsRows = 0, rhsColumns = 0;
	int** buffer1 = getMatrix(lhsRows, lhsColumns);
	int** buffer2 = Matrix.getMatrix(rhsRows, rhsColumns);
	if (lhsRows != rhsRows || lhsColumns != rhsColumns)
	{
		throw std::invalid_argument("Error");
	}

	for (int i = 0; i < lhsRows; ++i)
	{
		for (int j = 0; j < lhsColumns; ++j)
		{
			buffer1[i][j] = buffer1[i][j] ^ buffer2[i][j];
		}
	}
	setMatrix(buffer1, lhsRows, lhsColumns);
	for (int i = 0; i < rhsRows; ++i)
	{
		delete[] buffer2[i];
	}
	delete[] buffer2;
	return *this;
}

BoolMatrix BoolMatrix::operator*(const BoolMatrix& Matrix)
{
	BoolMatrix copy = *this;
	return copy *= Matrix;
}

BoolMatrix BoolMatrix::operator*=(const BoolMatrix& Matrix)
{
	int lhsRows = 0, lhsColumns = 0, rhsRows = 0, rhsColumns = 0;
	int** buffer1 = getMatrix(lhsRows, lhsColumns);
	int** buffer2 = Matrix.getMatrix(rhsRows, rhsColumns);
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
				product[i][j] ^= buffer1[i][k] && buffer2[k][j];
			}
		}
	}

	setMatrix(product, lhsRows, rhsColumns);
	for (int i = 0; i < lhsRows; ++i)
	{
		delete[] buffer1[i];
	}
	for (int i = 0; i < rhsRows; ++i)
	{
		delete[] buffer2[i];
	}
	delete[] buffer1;
	delete[] buffer2;
	return *this;
}

BoolMatrix BoolMatrix::operator+(const BoolMatrix& Matrix)
{
	BoolMatrix copy = *this;
	return copy += Matrix;
}

BoolMatrix BoolMatrix::operator+=(const BoolMatrix& Matrix)
{
	*this = *this ^ Matrix;
	return *this;
}

BoolMatrix& BoolMatrix::operator=(const BoolMatrix& Matrix)
{
	if (this == &Matrix)
	{
		return *this;
	}
	int rows = 0, columns = 0;
	int** buffer = Matrix.getMatrix(rows, columns);
	setMatrix(buffer, rows, columns);

	return *this;
}

istream& operator>>(istream& stream, BoolMatrix& Matrix)
{
	int rows = 0, columns = 0;
	Matrix.getRowsAndColumns(rows, columns);
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		buffer[i] = new int[columns];
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			stream >> buffer[i][j];
			buffer[i][j] = buffer[i][j] ? 1 : 0;
		}
	}
	Matrix.setMatrix(buffer, rows, columns);
	return stream;
}
