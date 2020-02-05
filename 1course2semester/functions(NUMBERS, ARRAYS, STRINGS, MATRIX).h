#pragma once
#include <iostream>
using namespace std;

void menu();
short digitsInNumber(int);
void swap(int&, int&);
void displayArray(int*, int);
int* generateSortedArray(int, int, int);
char* allocateMemoryInt(int);
char* allocateMemoryChar(int);
bool isDataValid(int*, int size);
bool isDataValid(char*, int);
bool areEqual(int*, int, int*, int);
bool areEqual(char*, int, char*, int);
int* enterArray(int);
void dataValidation(int*, int);
void initializationArray(int* const, int);
void removeElement(int* const, int&, int);
int linearSearch(int* const, int const, int const);
void shuffleArray(int*, int);
void bubleSort(int*, int);
void insertionSort(int*, int);
void selectionSort(int*, int);
int getlength(const char*);
void validation(char*);
int comapre(const char*, int const, const char*, int const, bool);
bool isAlphabet(char);
bool isLower(char);
char toUpper(char);
int indexSubstringInString(char*, int, char*, int);
void displayMatrix(int**, int, int);
int** createMatrix(int, int);
void deleteMemory(int**, int);
int** createTransposedArray(int**, int, int);
int maxInArrayPosition(int*, int);



void menu()
{
	while (true)
	{
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		char n;
		cin >> n;
		system("cls");


		switch (n)
		{
		case '1':

			break;
		case '2':

			break;
		case '3':
			return;
		default:
			cout << "Invalid operation. Try again.\n";
			system("pause");
			system("cls");
		}
	}

}
short digitsInNumber(int number)
{
	double count = 0;
	while (number)
	{
		number = number / 10;
		count++;
	}
	return count;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int* enterArray(int size)
{
	int* array = allocateMemoryInt(size);
	if (array == nullptr)
	{
		cout << "Error.\n";
		return 0;
	}
	if (size <= 0)
	{
		cout << "Size of array must be more than 0.\n";
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "]:";
		cin >> array[i];
	}
	return array;
}

void displayArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

int* generateSortedArray(int size, int start, int step)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = start;
		start += step;
	}

	return array;
}

int* allocateMemoryInt(int size)
{
	if (size <= 0)
	{
		return nullptr;
	}
	return new int[size];
}

char* allocateMemoryChar(int size)
{
	if (size <= 0)
	{
		return nullptr;
	}
	return new char[size];
}

bool isDataValid(int* array, int size)
{
	if (array == nullptr)
	{
		return 0;
	}

	if (size <= 0)
	{
		return 0;
	}
	return true;
}

bool isDataValid(char* array, int size)
{
	if (array == nullptr)
	{
		return 0;
	}

	if (size <= 0)
	{
		return 0;
	}
	return true;
}

bool areEqual(int* lhs, int lhsSize, int* rhs, int rhsSize)
{
	if (!isDataValid(lhs, lhsSize) || !isDataValid(rhs, rhsSize))
	{
		cout << "Error.\n";
		return false;
	}
	if (lhsSize != rhsSize)
	{
		return false;
	}
	for (int* p = lhs, *q = rhs; p < lhs + lhsSize; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}
	return true;
}

bool areEqual(char* lhs, int lhsSize, char* rhs, int rhsSize)
{
	if (!isDataValid(lhs, lhsSize) || !isDataValid(rhs, rhsSize))
	{
		cout << "Error.\n";
		return false;
	}
	if (lhsSize != rhsSize)
	{
		return false;
	}
	for (char* p = lhs, *q = rhs; p < lhs + lhsSize; p++, q++)
	{
		if (*p != *q)
		{
			return false;
		}
	}
	return true;
}

void dataValidation(int* array, int size)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}
}

void initializationArray(int* const array, int size)
{
	dataValidation(array, size);

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 1000;
	}
}

void removeElement(int* const array, int& size, int position)
{
	dataValidation(array, size);

	if (position < 0 || position > size)
	{
		throw std::out_of_range("Position  of array must be more than  zero and less then!");
	}

	for (int i = position - 1; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
}

int linearSearch(int* const array, int const size, int const value)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void shuffleArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = rand() % size;
		swap(array[i], array[j]);
	}
}

void bubleSort(int* sourceArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (sourceArray[j] < sourceArray[j - 1])
			{
				swap(sourceArray[j], sourceArray[j - 1]);
			}
		}
	}
}

void insertionSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && array[j] < array[j - 1]; j--)
		{
			swap(array[j], array[j - 1]);
		}
	}
}

void selectionSort(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i; j < size - 1; j++)
		{
			if (array[min] <= array[j + 1])
			{
				min = j + 1;
				continue;
			}
			else
				continue;
		}
		swap(array[min], array[i]);
	}
}

int getlength(const char* string)
{
	if (string == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (string[length])
	{
		length++;
	}
	return length;
}

void validation(char* string)
{
	if (string == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
}

int comapre(const char* lhs, int const lhsLength, const char* rhs, int const rhsLength, bool ordinal)
{
	//validation

	for (int i = 0; i <= lhsLength || i <= rhsLength; i++)
	{
		char l = ordinal ? lhs[i] : toUpper(lhs[i]);
		char r = ordinal ? rhs[i] : toUpper(rhs[i]);

		if (l = r)
		{
			continue;
		}
		if (l > r)
		{
			return 1;
		}
		else
		{
			return -1;
		}

	}
	if (lhsLength == rhsLength)
	{
		return 0;
	}

}

bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}

bool isLower(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}

char toUpper(char symbol)
{
	if (isAlphabet(symbol) && isLower(symbol))
	{
		return symbol - 32;
	}
	return symbol;
}

int indexSubstringInString(char* string, int lengthString, char* subString, int lengthSubString)
{
	//validation(string, lengthString, subString, lengthSubString);

	int index = -1;
	int counter = 0;
	for (int i = 0; i < lengthString; i++)
	{
		if (toUpper(subString[0]) == toUpper(string[i]))
		{
			index = i;
			int k = i + 1;
			counter++;
			for (int j = 1; j < lengthSubString; j++, k++)
			{
				if (toUpper(string[k]) == toUpper(subString[j]))
				{
					counter++;
					continue;
				}
				else
				{
					index = -1;
					counter = 0;
					break;
				}

			}
			if (counter == lengthSubString)
			{
				return k - lengthSubString;
			}
		}
		else
		{
			continue;
		}
	}
	return index;
}

void displayMatrix(int** matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int** createMatrix(int row, int column)
{
	int** matrix = new int* [row];
	srand(time(0));
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[column];

		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
	return matrix;
}

void deleteMemory(int** matrix, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int** createTransposedArray(int** array, int row, int column)
{
	int** transposedArray = new int* [column];
	for (int i = 0; i < column; i++)
	{
		transposedArray[i] = new int[row];
		for (int j = 0; j < row; j++)
		{
			transposedArray[i][j] = array[j][i];
		}
	}
	return transposedArray;
}

int maxInArrayPosition(int* array, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] > array[max])
		{
			max = i;
		}
	}
	return max;
}
