#pragma once
#include <iostream>
using namespace std;
bool comprasionString(char* string1, char* string2)
{
	int size1 = 0;
	for (int i = 0; string1[i] != 0; i++)
	{
		size1++;
	}
	int size2 = 0;
	for (int i = 0; string2[i] != 0; i++)
	{
		size2++;
	}

	if (size1 == size2)
	{
		return true;
	}
	else
	{
		return false;
	}
}