#pragma once
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void shuffleArray1(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = rand() % size;
		swap(array[i], array[j]);
	}
}
void shuffleArray2(int* array, int size)
{
	for (int i = 0; i < size; i++, size--)
	{

		swap(array[i], array[size / 2]);
	}
}
void shuffleArray3(int* array, int size)
{
	for (int i = 0; i < size; i++, size--)
	{

		swap(array[i], array[(size - 1) - i]);
	}
}