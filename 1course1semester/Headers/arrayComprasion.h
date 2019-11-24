#pragma once
#include <iostream>
using namespace std;

bool isDataValid(int*, int);
bool areEqual(int*, int, int*, int);
bool areEqual(int* lhs, int n, int* rhs, int m)
{
	if (!isDataValid(lhs, n) || !isDataValid(rhs, m))
	{
		cout << "Error.\n";
		return false;
	}
	if (n != m)
	{
		return false;
	}
	for (int* p = lhs, *q = rhs; p < lhs + n; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}
	return true;
}
bool isDataValid(int* array, int n)
{
	if (array == nullptr)
	{
		return 0;
	}

	if (n <= 0)
	{
		return 0;
	}
	return true;

}
