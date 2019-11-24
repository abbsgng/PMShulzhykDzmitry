#pragma once
#include <iostream>
using namespace std;
int* generateSortedArray(int size, int start, int step)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	int* array = new int[size];

	for (int* p = array, i = start; p < array + size; p++)
	{
		*p = start;
		start += step;
	}

	return array;
}