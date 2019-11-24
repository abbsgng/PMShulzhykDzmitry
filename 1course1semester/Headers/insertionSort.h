#pragma once
#include <iostream>
using namespace std;
int* insertionSort(int* array, int n)
{
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
			swap(array[j], array[j - 1]);
	return array;
}
