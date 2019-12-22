#include <iostream>
#include "workWithString.h"
#include "arrayComprasion(char).h"

using namespace std;

void menu();
void console();
char* replacementStringByLength(char*, int, int);
void validation(char*, int);
int searchFirstIndexWord(char*, int);


int main()
{
	console();
	return 0;
}

void console()
{
	int const n = 256;

	cout << "Hello, enter the string.\n";
	char* string = new char[n];
	cin.getline(string, n, '\n');

	int lengthWord;
	cout << "Well, enter the word length.\n";
	cin >> lengthWord;
	int ls = getlength(string);

	char* finishString = replacementStringByLength(string, ls, lengthWord);
	cout << finishString;
}

char* replacementStringByLength(char* string, int ls, int wordLength)
{
	validation(string, wordLength);
	int lfs = ls - wordLength + 1;
	char* finishString = new char[lfs];
	int index = searchFirstIndexWord(string, wordLength);
	if (index == -1)
	{
		return string;
	}

	for (int i = 0; i < index; i++)
	{
		finishString[i] = string[i];
	}
	for (int i = index, k = index + wordLength; i < lfs; i++, k++)
	{
		finishString[i] = string[k];
	}
	finishString[lfs] = '\0';

	return replacementStringByLength(finishString, lfs, wordLength);

}

int searchFirstIndexWord(char* string, int wordLength)
{
	int index = -1;
	int ls = getlength(string);
	for (int i = 0; i < ls; i++)
	{
		if (!(isAlphabet(string[i + wordLength])))
		{
			for (int j = i; j < i + wordLength; j++)
			{
				if (!isAlphabet(string[j]))
				{
					index = -1;
					break;
				}
				else
				{
					index = i;
				}

			}
			if (index != -1 && !(isAlphabet(string[index - 1])))
			{
				return index;
			}
		}
	}
	return index;
}

void validation(char* string, int wordLength)
{
	if (string == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
	if (wordLength <= 0)
	{
		throw std::invalid_argument("String cannot be null!");
	}
}
