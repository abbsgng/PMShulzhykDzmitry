#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
public:
	Matrix() :matrix(nullptr), rows(0), columns(0) {}
	Matrix(int, int);
	Matrix(int**, int, int);
	Matrix(const Matrix&);

	void setMatrix(int**, int, int);
	int** getMatrix(int&, int&) const;
	void getRowsAndColumns(int&, int&) const;

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
	static int** product(int**, int**, int, int, int, int);
	static int** sum(int**, int**, int, int, int, int);
	static int** difference(int**, int**, int, int, int, int);
	static void validation(int, int);

	int** matrix;
	int rows;
	int columns;
};


