#pragma once
#include <iostream>

using namespace std;

void removeElement(int* const array, int& n, int k)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (k < 0 || k > n)
	{
		throw std::out_of_range("Position  of array must be more than  zero and less then!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = k - 1; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}

	n--;
}