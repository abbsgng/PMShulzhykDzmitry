#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "WordAndNumber.h"

using namespace std;

const int length = 64;

void console();
void toBinary(const char*, const char*, const char*);
void cleanString(char*);
void cleanString(char**, int);
char** parse(char*, int&);
int countReplay(char**, char*, int);
void displayBinary(const char*);
void deleteMemory(char*);
void deleteMemory(char**, int);


int main()
{
	console();
	return 0;
}

void console()
{
	const char* path1 = "file1.txt";
	const char* path2 = "file2.txt";
	const char* pathBin = "Binary.bin";

	toBinary(path1, path2, pathBin);

	displayBinary(pathBin);
}

void toBinary(const char* path1, const char* path2, const char* pathBin)
{
	ofstream to(pathBin, ios::binary | ios::app);
	ifstream from2(path2);

	if (!to.is_open() || !from2.is_open())
	{
		throw std::invalid_argument("File isn't open");
	}

	char* buffer1 = new char[length] {};
	char* buffer2 = new char[length] {};

	while (!from2.eof())
	{
		ifstream from1(path1);

		if (!from1.is_open())
		{
			throw std::invalid_argument("File isn't open");
		}

		from2.getline(buffer2, 16, ' ');

		int count = 0;
		while (!from1.eof())
		{
			from1.getline(buffer1, 16, ' ');
			int n = 0;
			char** words = parse(buffer1, n);
			count += countReplay(words, buffer2, n);

			cleanString(words, n);
			deleteMemory(words, n);
		}

		from1.close();

		WordAndNumber buffer(buffer2, count);
		int bufSize = sizeof(WordAndNumber);
		to.write((char*)&buffer,bufSize);

		cleanString(buffer1);
		cleanString(buffer2);
	}

	delete[] buffer1, buffer2;
	to.close();
}

void cleanString(char* source)
{
	int size = strlen(source);
	for (int i = 0; i < size; ++i)
	{
		source[i] = '\0';
	}
}

void cleanString(char** source, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cleanString(source[i]);
	}
}

char** parse(char* source, int& n)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char* [strlen(source)];
	n = 0;
	char* pword = strpbrk(source, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);
		words[n] = new char[length + 1];
		strncpy(words[n], pword, length);
		words[n][length] = '\0';
		pword += length;
		pword = strpbrk(pword, symbols);
		n++;
	}

	return words;
}

int countReplay(char** text, char* word, int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(text[i], word) == 0)
		{
			count++;
		}
	}
	return count;
}

void displayBinary(const char* path)
{
	ifstream from(path, ios::binary);

	if (!from.is_open())
	{
		throw std::invalid_argument("File isn't open");
	}
	WordAndNumber buffer;
	int bufSize = sizeof(WordAndNumber);
	while (from.read((char*)&buffer, bufSize))
	{
		cout << buffer << endl;
	}

	from.close();
}

void deleteMemory(char* source)
{
	delete[] source;
}

void deleteMemory(char** source, int n)
{
	for (int i = 0; i < n; ++i)
	{
		deleteMemory(source[i]);
	}
	delete[] source;
}