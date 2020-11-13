#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template<typename T>class Matrix
{
public:
	Matrix() :matrix(nullptr), size(0) {}
	Matrix(int);
	Matrix(T**, int);
	Matrix(const Matrix&);

	void setMatrix(T**, int);
	T** getMatrix(int&) const;
	int getSize() const;

	T det();

	bool operator==(const Matrix&);
	Matrix operator*(const Matrix&) const;
	Matrix operator*=(const Matrix&);
	Matrix operator-(const Matrix&) const;
	Matrix operator-=(const Matrix&);
	Matrix operator+(const Matrix&) const;
	Matrix operator+=(const Matrix&);
	Matrix& operator=(const Matrix&);

	friend ostream& operator<<(ostream& stream, const Matrix& matrix)
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
	friend istream& operator>>(istream& stream, Matrix& matrix)
	{
		int size = matrix.getSize() * matrix.getSize();
		for (int i = 0; i < size; ++i)
		{
			stream >> matrix.matrix[i];
		}
		return stream;
	}

	~Matrix();
private:
	static T* product(T*, T*, int);
	static T* sum(T*, T*, int);
	static T* difference(T*, T*, int);
	static T determinant(T**, int);
	static void validation(int);
	static T** transform(T*, int);

	T* matrix;
	int size;
};

template<typename T>
Matrix<T>::Matrix(int size)
{
	this->size = size;
	this->matrix = new T[size * size];
	for (int i = 0; i < size * size; ++i)
	{
		this->matrix[i] = 0;
	}
}

template<typename T>
Matrix<T>::Matrix(T** matrix, int size)
{
	setMatrix(matrix, size);
}

template<class T>
Matrix<T>::Matrix(const Matrix& matrix)
{
	*this = matrix;
}

template<typename T>
void Matrix<T>::setMatrix(T** matrix, int size)
{
	validation(size);
	if (!this->matrix)
	{
		delete[] this->matrix;
	}
	this->size = size;
	this->matrix = new T[size * size];
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			this->matrix[i * size + j] = matrix[i][j];
		}
	}
}

template<typename T>
T** Matrix<T>::getMatrix(int& size) const
{
	size = this->size;
	T** buffer = new T * [size];
	for (int i = 0; i < size; ++i)
	{
		buffer[i] = new T[size]{ 0 };
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

template<typename T>
int Matrix<T>::getSize() const
{
	return size;
}

template<typename T>
T Matrix<T>::det()
{
	T** buffer = transform(matrix, size);
	T det = determinant(buffer, size);
	for (int i = 0; i < size; ++i)
	{
		delete[] buffer[i];
	}
	delete[] buffer;
	return det;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix& matrix)
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

template<typename T>
Matrix<T>Matrix<T>::operator*(const Matrix& matrix) const
{
	Matrix copy = *this;
	return copy *= matrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix& matrix)
{
	if (this->size != matrix.getSize())
	{
		throw std::invalid_argument("Error");
	}
	this->matrix = product(this->matrix, matrix.matrix, size);
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& matrix) const
{
	Matrix copy = *this;
	return copy -= matrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix& matrix)
{
	if (this->size != matrix.getSize())
	{
		throw std::invalid_argument("Error");
	}
	this->matrix = difference(this->matrix, matrix.matrix, size);
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& matrix) const
{
	Matrix copy = *this;
	return copy += matrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix& matrix)
{
	if (this->size != matrix.getSize())
	{
		throw std::invalid_argument("Error");
	}
	this->matrix = sum(this->matrix, matrix.matrix, size);
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& matrix)
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
	this->matrix = new T[size * size];
	for (int i = 0; i < size * size; ++i)
	{
		this->matrix[i] = matrix.matrix[i];
	}
	return *this;
}

template<typename T>
Matrix<T>::~Matrix()
{
	delete[] matrix;
}

template<typename T>
T* Matrix<T>::product(T* lhs, T* rhs, int size)
{
	T* product = new T[size * size]{ 0 };
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

template<typename T>
T* Matrix<T>::sum(T* lhs, T* rhs, int size)
{
	T* sum = new T[size * size]{ 0 };
	for (int i = 0; i < size * size; ++i)
	{
		sum[i] = lhs[i] + rhs[i];
	}

	return sum;
}

template<typename T>
T* Matrix<T>::difference(T* lhs, T* rhs, int size)
{
	T* difference = new T[size * size]{ 0 };
	for (int i = 0; i < size * size; ++i)
	{
		difference[i] = lhs[i] - rhs[i];
	}

	return difference;
}

template<typename T>
void Matrix<T>::validation(int number)
{
	if (number < 0)
	{
		throw std::invalid_argument("Error");
	}
}

template<typename T>
T** Matrix<T>::transform(T* array, int size)
{
	T** buffer = new T * [size];
	for (int i = 0; i < size; ++i)
	{
		buffer[i] = new T[size];
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

template<typename T>
T Matrix<T>::determinant(T** array, int size)
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
		T** buffer = new T * [size - 1];
		for (int i = 0; i < size - 1; ++i)
		{
			buffer[i] = new T[size - 1];
		}

		T det = 0;
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