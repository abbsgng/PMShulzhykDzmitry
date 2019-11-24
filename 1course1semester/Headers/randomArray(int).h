#pragma once
#include <iostream>
using namespace std;
void dataValidation(int* array, int size)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}
}
void initializationArray(int* const array, int size)
{
	dataValidation(array, size);

	for (int* p = array; p < array + size; p++)
	{
		*p = rand() % 1000;
	}
}