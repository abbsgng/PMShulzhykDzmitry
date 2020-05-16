#pragma once
#include <iostream>
#include <fstream>

const int N = 256;
using namespace  std;

class Matrix
{
public:
	Matrix() {}
	Matrix(int, int);
	Matrix(int*, int, int);
	Matrix(int**, int, int);
	Matrix(const Matrix&);
	void setMatrix(int**, int, int);
	Matrix& operator=(const Matrix&);
	Matrix& operator*(const Matrix&);
	friend ostream& operator<<(ostream&, Matrix&);
	friend istream& operator>>(istream&, Matrix&);
private:
	static int* productMatrix(int*, int*, int, int, int, int);
	static void validation(int, int);
	static int* transformMatrix(int**, int, int);

	void setMatrix(int*, int, int);
	int matrix[N];
	int rows;
	int columns;
};

