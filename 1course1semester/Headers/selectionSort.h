#pragma once
#include <iostream>
using namespace std;
int* solutionSort(int*, int);
void swap(int& a, int& b);
int* solutionSort(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i; j < n - 1; j++)
		{
			if (array[min] >= array[j + 1])
			{
				min = j + 1;
				continue;
			}
			else
				continue;
		}
		swap(array[min], array[i]);
	}
	return array;
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}