#pragma once
#include <iostream>

using namespace std;

void bubleSort(int*, int);
void swap(int&, int&);


void bubleSort(int* sourceArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (sourceArray[j] < sourceArray[j - 1])
			{
				swap(sourceArray[j], sourceArray[j - 1]);
			}
		}
	}
}
void swap(int& a, int& b)
{
	int t = a;
	a = t;
	b = t;
}
