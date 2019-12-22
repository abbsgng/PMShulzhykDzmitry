#include <iostream>
#include "workWithString.h"
#include "arrayComprasion(char).h"

using namespace std;

void console();
char* replacementStringByLength(char*, int, int, char*, int);
void validation(char*, int, char*);
int searchFirstIndexWord(char*, int);
void runTest();
void testing(int testNumber, char string[], int ls, int wordLength, char addString[], int las, char finishString[], int lfs);

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

	char* addString = new char[n];
	cout << "And now, enter the substring you want to add.\n";
	cin.getline(addString, n, '\n');

	int lengthWord;
	cout << "Well, enter the word length.\n";
	cin >> lengthWord;

	int ls = getlength(string);
	int las = getlength(addString);

	char* finishString = replacementStringByLength(string, ls, lengthWord, addString, las);
	cout << finishString;

}

char* replacementStringByLength(char* string, int ls, int wordLength, char* addString, int las)
{
	validation(string, wordLength, addString);
	int lfs = ls - wordLength + las + 1;
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
	for (int i = index, k = 0; i < index + las; i++, k++)
	{
		finishString[i] = addString[k];
	}
	for (int i = index + las, k = index + wordLength; i < lfs; i++, k++)
	{
		finishString[i] = string[k];
	}
	finishString[lfs] = '\0';

	return replacementStringByLength(finishString, lfs, wordLength, addString, las);
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

void validation(char* string, int wordLength, char* addString)
{
	if (string == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
	if (wordLength <= 0)
	{
		throw std::invalid_argument("String cannot be null!");
	}
	if (addString == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
}

void runTest()
{
	int testNumber = 1;

	char string[] = "hello world";
	int wordLength = 5;
	char addString[] = "1234";
	char finishString[] = "1234 1234";
	int ls = getlength(string);
	int las = getlength(addString);
	int lfs = getlength(finishString);
	testing(testNumber++, string, ls, wordLength, addString, las, finishString, lfs);

	char string1[] = "teh th ujh jhjjk uu";
	int wordLength1 = 2;
	char addString1[] = "world";
	char finishString1[] = "teh world ujh jhjjk world";
	int ls1 = getlength(string1);
	int las1 = getlength(addString1);
	int lfs1 = getlength(finishString1);
	testing(testNumber++, string1, ls1, wordLength1, addString1, las1, finishString1, lfs1);

	char string2[] = "h e l l o";
	int wordLength2 = 1;
	char addString2[] = "0";
	char finishString2[] = "0 0 0 0 0";
	int ls2 = getlength(string2);
	int las2 = getlength(addString2);
	int lfs2 = getlength(finishString2);
	testing(testNumber++, string2, ls2, wordLength2, addString2, las2, finishString2, lfs2);

	char string3[] = "123yhhh4567";
	int wordLength3 = 4;
	char addString3[] = "0";
	char finishString3[] = "12304567";
	int ls3 = getlength(string3);
	int las3 = getlength(addString3);
	int lfs3 = getlength(finishString3);
	testing(testNumber++, string3, ls3, wordLength3, addString3, las3, finishString3, lfs3);
}

void testing(int testNumber, char string[], int ls, int wordLength, char addString[], int las, char finishString[], int lfs)
{
	char* actual = replacementStringByLength(string, ls, wordLength, addString, las);
	int la = getlength(actual);
	if (areEqual(actual, la, finishString, lfs))
	{
		cout << "Test #" << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Test #" << testNumber << " isn't correct.\n";
	}
}