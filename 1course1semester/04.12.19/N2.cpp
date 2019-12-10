#include <iostream>
#include "workWithString.h"

using namespace std;

char** createWords(char[], int&);
void displayWords(char**, int);
void bubleSortString(char**, int&,char);
void swap(int*, int*);
int symbolInArray(char*, int, char);

int main()
{
	char source[] = "Lorem, Ipsum is simply dummy text "
		"of the printing and ,type setting !! industry."
		"Lorem @@@ Ipsum $$ $$$ has 78 been ** the industry's standard";
	int k = 0;

	char** words = createWords(source, k);
	char symbol;
	cout << "Enter the Symbol.\n";
	cin >> symbol;
	cout << endl;

	bubleSortString(words, k,symbol);
	displayWords(words, k);

	return 0;
}

void displayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << words[i] << endl;
	}
}

char** createWords(char source[], int& k)
{
	const int N = 256;
	char* bufferWords[N];//чистка массива "нулями" массив из N элементов состоящий из указателей на что-то 
	int i = 0,
		j = 0;
	bool isWordCreating = false;
	k = 0; // количество строк
	char buffer[N] = "";

	while (source[i])
	{
		if (isAlphabet(source[i]))
		{
			buffer[j] = source[i];
			j++;//счётчик символа в слове
			isWordCreating = true;
		}
		else
			if (isWordCreating)
			{
				bufferWords[k] = createString(buffer);
				copyString(buffer, " ");
				j = 0;
				k++;//счётчик слова
				isWordCreating = false;
			}

		//сортировка по алфавиту, размеру, колличеству заданных символов в слове(всё по нестрогому по возрастанию)
		i++;//счётчик символа в предложении
	}
	if (isWordCreating)
	{
		bufferWords[k] = createString(buffer);
		k++;
	}

	char** words = new char* [k];//указатель на хип из k эл-в содерж. указатель

	for (int i = 0; i < k; i++)
	{
		words[i] = bufferWords[i];
	}

	return words;
}

void bubleSortString(char** words, int& k, char symbol)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = k - 1; j > i; j--)
		{
			int counter1 = symbolInArray(words[j], getlengthWord(words[j]), symbol);
			int counter2 = symbolInArray(words[j - 1], getlengthWord(words[j - 1]), symbol);
			if (counter1 < counter2)
			{
				swap(words[j], words[j - 1]);
			}
		}
	}
}

void swap(int* a, int* b)
{
	int* t = a;
	a = t;
	b = t;
}

int symbolInArray(char* array, int lengthArray, char symbol)
{
	int counter = 0;
	for (int i = 0; i <= lengthArray; i++)
	{
		if (array[i] == symbol)
		{
			counter++;
		}
		else
		{
			continue;
		}
	}
	return counter;
}