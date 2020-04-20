#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;

class BigInteger
{
public:
	BigInteger();
	BigInteger(char*);
	BigInteger(BigInteger const&);
	~BigInteger();
	BigInteger& operator+(BigInteger&);
	BigInteger& operator-(BigInteger&);
	BigInteger& operator=(BigInteger&);
	void display();
private:
	char* digits;
	int digitLength;
	static bool isDataValid(char*);
	void setDigitLength(int);
	void setDigits(char*);
	static char* subtraction(char*, char*);
	static char* add(char*, char*);
	static void swap(char*&, char*&);
	static int toDigit(char);
};

