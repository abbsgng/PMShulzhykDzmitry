#pragma once
#include <iostream>
using namespace std;
int* allocateMemoryInt(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}
	return new int[n];
}