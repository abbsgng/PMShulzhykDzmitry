#pragma once
#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

struct SetMatrix
{
public:
	SetMatrix()
	{
		int* array = new int[1]{ 0 };
		Matrix matrix1(array, 1, 1), matrix2(array, 1, 1), matrix3(array, 1, 1);
		SetMatrix(matrix1, matrix2, matrix3);
		delete[] array;
	}
	SetMatrix(Matrix matrix1, Matrix matrix2, Matrix matrix3)
	{
		this->matrix1 = matrix1;
		this->matrix2 = matrix2;
		this->matrix3 = matrix3;
	}

	friend ostream& operator<< (ostream& stream, SetMatrix& set)
	{
		stream << set.matrix1;
		stream << endl;
		stream << set.matrix2;
		stream << endl;
		stream << set.matrix3;
		return stream;
	}
	friend istream& operator>> (istream& stream, SetMatrix& set)
	{
		stream >> set.matrix1;
		stream >> set.matrix2;
		stream >> set.matrix3;
		return stream;
	}

private:
	Matrix matrix1;
	Matrix matrix2;
	Matrix matrix3;
};