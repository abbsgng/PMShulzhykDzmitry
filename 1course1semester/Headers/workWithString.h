#pragma once
#include <iostream>
using namespace std;
int getlength(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (source[length])
	{
		length++;
	}
	return length;
}
int getlengthWord(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (source[length] && source[length] != ' ')
	{
		length++;
	}
	return length;
}
char* createString(const char* source)
{
	//validation
	int length = getlength(source) + 1;
	char* target = new char[length];
	int i = 0;
	while (source[i])
	{
		target[i] = source[i];
		i++;
	}
	target[i] = '\0';
	return target;
}
bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}
bool isLower(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}
char toUpper(char symbol)
{
	if (isAlphabet(symbol) && isLower(symbol))
	{
		return symbol - 32;
	}
	return symbol;
}
bool compare(const char* lhs, int const lhsLength, const char* rhs, int const rhsLength, bool ordinal)
{
	//validation
	bool t = true;
	for (int i = 0; i <= lhsLength || i <= rhsLength; i++)
	{
		char l = ordinal ? lhs[i] : toUpper(lhs[i]);
		char r = ordinal ? rhs[i] : toUpper(rhs[i]);
		if (l == r)
		{
			t = true;
			continue;
		}
		if (l > r)
		{
			return true;
		}
		if (l < r)
		{
			return false;
		}

	}
	return true;

}
void validation(char* string, int lengthString, char* subString, int lengthSubString)
{
	if (string == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
	if (subString == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
	if (lengthSubString > lengthString)
	{
		throw std::invalid_argument("Substring cannot be bigger!");
	}
}
int indexSubstringInString(char* string, int lengthString, char* subString, int lengthSubString)
{
	//validation(string, lengthString, subString, lengthSubString);

	int index = -1;
	int counter = 0;
	for (int i = 0; i < lengthString; i++)
	{
		if (toUpper(subString[0]) == toUpper(string[i]))
		{
			index = i;
			int k = i + 1;
			counter++;
			for (int j = 1; j < lengthSubString; j++, k++)
			{
				if (toUpper(string[k]) == toUpper(subString[j]))
				{
					counter++;
					continue;
				}
				else
				{
					index = -1;
					counter = 0;
					break;
				}

			}
			if (counter == lengthSubString)
			{
				return k - lengthSubString;
			}
		}
		else
		{
			continue;
		}
	}
	return index;
}
void copyString(char* const target, const char* source)
{
	if (target == nullptr)
	{
		throw std::invalid_argument("Target is null!");
	}

	if (source == nullptr)
	{
		throw std::invalid_argument("Source is null!");
	}

	int targetLength = getlength(target);

	int sourceLength = getlength(source);

	if (targetLength < sourceLength)
	{
		throw std::invalid_argument("Length destination string!");
	}

	int i = 0;
	for (int i = 1; i < 256; i++)
	{
		target[i] = '\0';
	}
	while (source[i])
	{
		target[i] = source[i];
		i++;
	}
	target[i] = '\0';

}


