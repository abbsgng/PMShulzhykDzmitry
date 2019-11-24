#pragma once
#include <iostream>
using namespace std;

bool isDataValid(char*, int);
bool areEqual(char*, int, char*, int);
bool areEqual(char* lhs, int n, char* rhs, int m)
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
	for (char* p = lhs, *q =rhs; p < lhs + n; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}
	return true;
}
bool isDataValid(char* array, int n)
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
