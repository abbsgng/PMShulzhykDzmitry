#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

const int N = 16;

class WordAndNumber
{
public:
	WordAndNumber();
	WordAndNumber(char*, int);
	inline char* getWord();
	inline int getCount();
	void  setWord(char*);
	void setCount(int);

	friend ostream& operator<<(ostream&, WordAndNumber&);
private:
	char word[N];
	int count;
};

