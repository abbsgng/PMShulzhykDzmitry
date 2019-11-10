#include <iostream>
#include "enterArray.h"
using namespace std;

void console();
int* allocateMemory(int);
int* inputArray(int*, int);
void primeNumberArray(int[], int[], int);
void menu();
void runTest();
void testing(int, int, int, int, int, int, int, int, int, int, int);



int main()
{
	menu();
	return 0;
}
void console()
{
	int n;
	cout << "Enter the size of array.\n";
	cin >> n;
	int* array = allocateMemory(n);
	array = inputArray(array, n);
	int* primeArray = allocateMemory(n);
	for (int i = 0; i < n; i++)
	{
		primeArray[i] = 0;
	}
	primeNumberArray(array, primeArray, n);
	
	for (int c = 0; c < n; c++)
	{
		if (primeArray[c] != 0)
			cout << primeArray[c] << " ";
		else
			continue;
	}
	
	system("pause");
	system("cls");

}
void primeNumberArray(int array[], int primeArray[], int n)
{


	for (int i = 0, c = 0; i < n; i++, c++)
	{
		if (array[i] == 2)
		{
			primeArray[c] = array[i];
			continue;
		}
		else
		{
			for (int i1 = 2; i1 < abs(array[i]); i1++)
			{
				if (array[i] % i1 == 0)
				{
					primeArray[c] = 0;
					break;
				}

				else
					primeArray[c] = array[i];
			}
		}
	}

}
void menu()
{
	while (true)
	{
		char x;
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		cin >> x;
		system("cls");

		switch (x)
		{
		case '1':
			console();
			break;
		case '2':
			runTest();
			break;
		case '3':
			system("cls");
			return;
		default:
			cout << "Error, try again.";
			system("pause");
			system("cls");

		}
	}
}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 1, 2, 3, 4, 5, 0, 2, 3, 0, 5);
	testing(testNumber++, 2, 2, 2, 29, 1, 2, 2, 2, 29, 0);
	testing(testNumber++, 17, 13, 1, 1, 1, 17, 13, 0, 0, 0);
	testing(testNumber++, -5, -3, 0, 1, 2, -5, -3, 0, 0, 2);
	testing(testNumber++, 127, 1, 119, 5, 0, 127, 0, 0, 5, 0);
	system("pause");
	system("cls");
}
void testing(int testNumber, int arr1, int arr2, int arr3, int arr4, int arr5, int primeArr1, int primeArr2, int primeArr3, int primeArr4, int primeArr5)
{
	int const n = 5;
	int array[n] = { 0 };
	int primeArray[n] = { 0 };
	array[0] = arr1;
	array[1] = arr2;
	array[2] = arr3;
	array[3] = arr4;
	array[4] = arr5;
	primeNumberArray(array, primeArray, n);
	if (primeArray[0] == primeArr1 && primeArray[1] == primeArr2 && primeArray[2] == primeArr3 && primeArray[3] == primeArr4 && primeArray[4] == primeArr5)
		cout << "Test # " << testNumber << " is correct.\n";
	else
		cout << "Test # " << testNumber << " isn't correct\n";
}
int* allocateMemory(int n)
{
	if (n <= 0)
	{
		cout << "Dimension cannot be zero or negative.\n";
		return nullptr;
	}
	return new int(n);
}
int* inputArray(int* array, int n)
{
	if (array == nullptr)
	{
		cout << "Error.\n";
		return 0;
	}
	if (n <= 0)
	{
		cout << "Dimension cannot be zero or negative.\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
	return array;
}