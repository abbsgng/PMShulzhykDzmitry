#pragma once

using namespace std;


class StringAndNumber
{
public:
	static const int N = 10;
	StringAndNumber();
	StringAndNumber(char*, int);
	void setLetters(char*);
	void setNumber(int);
	int getNumber() const;
	char* getLetters();
private:
	char letters[N];
	int number;
};

