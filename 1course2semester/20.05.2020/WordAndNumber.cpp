#define _CRT_SECURE_NO_WARNINGS
#include "WordAndNumber.h"


WordAndNumber::WordAndNumber()
{
	strcpy(word, "\0");
	count = 0;
}

WordAndNumber::WordAndNumber(char* word, int number)
{
	strcpy(this->word, word);
	this->count = number;
}

inline char* WordAndNumber::getWord()
{
	return word;
}

inline int WordAndNumber::getCount()
{
	return count;
}

void WordAndNumber::setWord(char* source)
{
	for (int i = 0; i < strlen(source); ++i)
	{
		word[i] = source[i];
	}
}

void WordAndNumber::setCount(int count)
{
	this->count = count;
}

ostream& operator<<(ostream& stream, WordAndNumber& WordAndNumber)
{
	stream << WordAndNumber.word << WordAndNumber.count;
	return stream;
}
