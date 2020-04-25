#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class BigInteger
{
public:
	BigInteger();
	BigInteger(const char*);
	BigInteger(BigInteger const&);
	~BigInteger();
	BigInteger& operator+(const BigInteger&);
	BigInteger& operator-(const BigInteger&);
	BigInteger& operator=(const BigInteger&);
	friend ostream& operator<<(ostream&, BigInteger&);
	friend istream& operator>>(istream&, BigInteger&);
private:
	char* digits;
	int digitLength;
	static bool isDataValid(const char*);
	void setDigitLength(int);
	void setDigits(const char*);
	static char* subtraction(char*, char*);
	static char* add(char*, char*);
	static void swap(char*&, char*&);
	static int toDigit(char);
};

