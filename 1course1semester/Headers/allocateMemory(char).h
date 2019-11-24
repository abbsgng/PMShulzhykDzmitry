#pragma once
#include <iostream>
using namespace std;
char* allocateMemoryChar(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}
	return new char[n];
}