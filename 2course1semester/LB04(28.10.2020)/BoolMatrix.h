#pragma once
#include "Matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

class BoolMatrix :public Matrix
{
public:
	BoolMatrix() :Matrix() {}
	BoolMatrix(int rows, int columns) :Matrix(rows, columns) {}
	BoolMatrix(int**, int, int);
	BoolMatrix(const BoolMatrix&);

	int countOfOne() const;
	BoolMatrix A_canonical();

	void setMatrix(int**, int, int);

	BoolMatrix operator&(const BoolMatrix&);
	BoolMatrix operator&=(const BoolMatrix&);
	BoolMatrix operator|(const BoolMatrix&);
	BoolMatrix operator|=(const BoolMatrix&);
	BoolMatrix operator^(const BoolMatrix&);
	BoolMatrix operator^=(const BoolMatrix&);
	BoolMatrix operator*(const BoolMatrix&);
	BoolMatrix operator*=(const BoolMatrix&);
	BoolMatrix operator+(const BoolMatrix&);
	BoolMatrix operator+=(const BoolMatrix&);
	BoolMatrix& operator=(const BoolMatrix&);

	friend istream& operator>>(istream&, BoolMatrix&);

private:
	static int fromBinary(int*, int);
	static int* deleteSameElement(int*, int&);
	static void quickSort(int*, int);
	static int* toBinary(int*, int, int);
};

