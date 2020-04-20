#define _CRT_SECURE_NO_WARNINGS

#include "BigInteger.h"
#include <iostream>

using namespace std;

BigInteger::BigInteger()
{
	setDigitLength(2);
	char temp[2] = "0";
	setDigits(temp);
}

BigInteger::BigInteger(char* digits)
{
	setDigitLength(strlen(digits));
	setDigits(digits);
}

BigInteger::BigInteger(const BigInteger& other)
{
	setDigitLength(strlen(other.digits));
	this->digits = new char[digitLength + 1];
	strcpy(this->digits, other.digits);
}

BigInteger::~BigInteger()
{
	delete[] digits;
}

BigInteger& BigInteger::operator+(BigInteger& other)
{
	char* temp = add(digits, other.digits);
	setDigitLength(strlen(temp) + 1);
	setDigits(temp);
	return *this;
}

BigInteger& BigInteger::operator-(BigInteger& other)
{
	char* temp = subtraction(digits, other.digits);
	setDigitLength(strlen(temp) + 1);
	setDigits(temp);
	return *this;
}

BigInteger& BigInteger::operator=(BigInteger& other)
{
	digitLength = other.digitLength;
	this->digits = new char[digitLength + 1];
	strcpy(digits, other.digits);
	return *this;
}

void BigInteger::setDigitLength(int length)
{
	if (length < 0)
	{
		throw std::invalid_argument("Invalid argument");
	}
	digitLength = length;
}

void BigInteger::setDigits(char* digits)
{
	if (digits == nullptr)
	{
		throw std::invalid_argument(" !!! ");
	}
	if (!isDataValid(digits))
	{
		throw std::invalid_argument("Invalid argument");
	}
	this->digits = new char[digitLength + 1];
	strcpy(this->digits, digits);
}

char* BigInteger::subtraction(char* lhs, char* rhs)
{
	int lhsLength = strlen(lhs), rhsLength = strlen(rhs);
	if (rhsLength > lhsLength)
	{
		throw std::invalid_argument("Error.");
	}
	if (strcmp(lhs, rhs) < 0 && rhsLength == lhsLength)
	{
		throw std::invalid_argument("Error.");
	}
	char* result = new char[lhsLength + 1]{ 0 };
	strcpy(result, "0");
	if (strcmp(lhs, rhs) == 0)
	{
		return result;
	}
	int unit = 0;
	int a = 0, b = 0, c = 0;
	for (int i = lhsLength - 1, j = rhsLength - 1; i >= 0; i--, j--)
	{
		a = b = 0;
		a = toDigit(lhs[i]) - unit, b = toDigit(rhs[j]);
		unit = 0;
		if (j < 0)
		{
			b = 0;
		}
		if (a < b)
		{
			a += 10;
			unit = 1;
		}
		c = a - b;
		result[i] = c + '0';
	}
	while (result[0] == '0')
	{
		for (int i = 0; i < lhsLength; ++i)
		{
			result[i] = result[i + 1];
		}
	}
	return result;
}

char* BigInteger::add(char* lhs, char* rhs)
{
	int lhsLength = strlen(lhs), rhsLength = strlen(rhs);
	if (lhsLength < rhsLength)
	{
		swap(lhs, rhs);
		lhsLength = strlen(lhs);
		rhsLength = strlen(rhs);
	}
	char* result = new char[lhsLength + 2]{ 0 };
	strcpy(result, "0");
	int unit = 0;
	int a = 0, b = 0, c = 0;
	for (int i = lhsLength - 1, j = rhsLength - 1; i >= 0; i--, j--)
	{
		a = b = 0;
		a = toDigit(lhs[i]) + unit, b = toDigit(rhs[j]);
		if (j < 0)
		{
			b = 0;
		}
		c = a + b;
		unit = c / 10;
		c %= 10;
		result[i] = c + '0';
	}
	if (unit > 0)
	{
		for (int i = lhsLength + 2; i >= 0; --i)
		{
			result[i + 1] = result[i];
		}
		result[0] = unit + '0';
	}

	return result;
}

void BigInteger::swap(char*& a, char*& b)
{
	char* temp = a;
	a = b;
	b = temp;
}

int BigInteger::toDigit(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	{
		return symbol - '0';
	}
	return symbol;
}

bool BigInteger::isDataValid(char* digits)
{
	for (int i = 0; i < strlen(digits); ++i)
	{
		if (digits[i] < '0' || digits[i] > '9')
		{
			return false;
		}
	}
	return true;
}

void BigInteger::display()
{
	std::cout << this->digits;
}