#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
public:
	Matrix() :matrix(nullptr), size(0) {}
	Matrix(int);
	Matrix(int**, int);
	Matrix(const Matrix&);

	void setMatrix(int**, int);
	int** getMatrix(int&) const;
	int getSize() const;

	int det();

	bool operator==(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*=(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator-=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator+=(const Matrix&);
	Matrix& operator=(const Matrix&);

	friend ostream& operator<<(ostream&, const Matrix&);
	friend istream& operator>>(istream&, Matrix&);

	~Matrix();
private:
	static int* product(int*, int*, int);
	static int* sum(int*, int*, int);
	static int* difference(int*, int*, int);
	static int determinant(int**, int);
	static void validation(int);
	static int** transform(int*, int);
	
	int* matrix;
	int size;
};

