#include <iostream>
#include "bubleSortArray.h"
#include "ArrayComprasion.h"

using namespace std;

int* allocateMemory(int n);
int* enterArray(int);
void deleteMemory(int*);
void console();
void menu();
void runTest();
void testing(int, int*, int, int*, int);

int main()
{
	menu();
	return 0;
}

int* allocateMemory(int n)
{
	if (n <= 0)
	{
		cout << "Size of array must be more than 0.\n";
		return nullptr;
	}
	int* p = new int(n);
	return p;
}
int* enterArray(int n)
{
	int* array = allocateMemory(n);
	if (array == nullptr)
	{
		cout << "Error.\n";
		return 0;
	}
	if (n <= 0)
	{
		cout << "Size of array must be more than 0.\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "]:";
		cin >> array[i];
	}
	return array;
}
void console()
{

	int n;
	cout << "Enter the size of array.\n";
	cin >> n;
	int* array = enterArray(n);
	array = bubleSort(array, n);
	cout << "Sorted array:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "]:" << array[i] << "; ";

	}
	system("pause");
	system("cls");
}
void deleteMemory(int* sourceArray)
{
	delete[] sourceArray;
}
void menu()
{
	while (true)
	{
		char f;
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		cin >> f;
		system("cls");
		switch (f)
		{
		case '1':
			console();
			break;
		case '2':
			runTest();
			break;
		case '3':
			return;
		default:
			cout << "Invalid operation.Try again.\n";
		}
	}
}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, new int[6]{ 3, 2, 5, 1, 4, 5 }, 6, new int[6]{ 5,5,4,3,2,1 }, 6);
	testing(testNumber++, new int[9]{ 1, 1, 1, 1, 1, 1, 1, 1, 0 }, 9, new int[9]{ 1, 1, 1, 1, 1, 1, 1, 1, 0 }, 9);
	testing(testNumber++, new int[4]{ -1, -2, -2, 8 }, 4, new int[4]{ 8,-1,-2,-2 }, 4);
	testing(testNumber++, new int[6]{ 1,2,3,3,2,1 }, 6, new int[6]{ 3,3,2,2,1,1 }, 6);
	testing(testNumber++, new int[2]{ 0,100 }, 2, new int[2]{ 100,0 }, 2);
	testing(testNumber++, new int[2]{ 8,2 }, 2, new int[2]{ 8,2 }, 2);
}
void testing(int testNumber, int* lhs, int n, int* rhs, int m)
{
	int* rhs1 = bubleSort(lhs, n);
	if (areEqual(rhs1, n, rhs, m))
		cout << "Test #" << testNumber << " is correct.\n";
	else
		cout << "Test #" << testNumber << " isn't correct.\n";

}