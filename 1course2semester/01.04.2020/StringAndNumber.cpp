#define _CRT_SECURE_NO_WARNINGS
#include "StringAndNumber.h"
#include <iostream>


StringAndNumber::StringAndNumber()
{
	for (int i = 0; i < N; ++i)
	{
		this->letters[i] = ' ';
	}
	this->number = 0;
}
StringAndNumber::StringAndNumber(char* letters, int number)
{
	setLetters(letters);
	setNumber(number);
} 
void StringAndNumber::setLetters(char* letters)
{
	strcpy(this->letters, letters);
}
void StringAndNumber::setNumber(int number)
{
	this->number = number;
}

int StringAndNumber::getNumber() const
{
	return this->number;
}

char* StringAndNumber::getLetters()
{
	return this->letters;
}
