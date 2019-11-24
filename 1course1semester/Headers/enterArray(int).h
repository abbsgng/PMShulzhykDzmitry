#pragma once
#include <iostream>
using namespace std;
int* enterArray(int n)
{
	int* array = allocateMemory(n);
	if (array == nullptr)
	{
		cout << "Error.\n";
		return 0;
	}
	if (n <= 0)
	{
		cout << "Size of array must be more than 0.\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "]:";
		cin >> array[i];
	}
	return array;
}
int* allocateMemory(int n)
{
	if (n <= 0)
	{
		cout << "Size of array must be more than 0.\n";
		return nullptr;
	}
	int* p = new int(n);
	return p;
}
