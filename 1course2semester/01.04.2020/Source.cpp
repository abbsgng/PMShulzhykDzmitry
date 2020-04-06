#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "StringAndNumber.h"
#include <cstdlib>

using namespace std;

void transfer(char*, char*);
void read(char*);
StringAndNumber* parse(char*);

int main()
{
	char textPath[64] = "C:\\Users\\Термокаскад\\Desktop\\file.txt";
	char binaryPath[64] = "C:\\Users\\Термокаскад\\Desktop\\bynary.BIN";
	transfer(textPath, binaryPath);
	read(binaryPath);
	return 0;
}

void transfer(char* destinationPath, char* sourcePath)
{
	ofstream streamOut(sourcePath, ios::binary);
	ifstream streamIn(destinationPath);
	char* bufferString = new char[StringAndNumber::N]{ 0 };

	int bufferNumber = 0;
	int sizeBuffer = sizeof(StringAndNumber);
	StringAndNumber* bufferObject = new StringAndNumber;

	if (!streamIn.is_open())
	{
		throw std::invalid_argument("Error");
	}

	if (!streamOut.is_open())
	{
		throw std::invalid_argument("Error");
	}

	while (!streamIn.eof())
	{
		streamIn.getline(bufferString, sizeBuffer,'\n');
		bufferObject = parse(bufferString);
		streamOut.write((char*)bufferObject, sizeBuffer);
	}
	streamIn.close();
	streamOut.close();
	delete bufferObject;
	delete[] bufferString;
}

void read(char* destination)
{
	ifstream streamIn(destination, ios::binary);
	int sizeBuffer = sizeof(StringAndNumber);
	StringAndNumber bufferObject;

	if (!streamIn.is_open())
	{
		throw std::invalid_argument("Error");
	}

	while (streamIn.read((char*)&bufferObject, sizeBuffer))
	{
		cout << bufferObject.getLetters() << bufferObject.getNumber() << endl;
	}
	streamIn.close();
}

StringAndNumber* parse(char* source)
{
	int size = strlen(source);
	char* word = new char[size] { 0 };
	char* numberChar = new char[size] { 0 };
	int bufferNumber = 0;
	int i = 0, j = 0;
	char* p = strchr(source, ' ');

	strncpy(word, source, (p - source+1));
	strcpy(numberChar, p + 1);

	bufferNumber = atoi(numberChar);

	StringAndNumber* object = new StringAndNumber;
	object->setLetters(word);
	object->setNumber(bufferNumber);
	delete[] word, numberChar;
	return object;
}