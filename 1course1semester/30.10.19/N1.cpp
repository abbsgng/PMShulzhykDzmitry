#include <iostream>

using namespace std;

void console();
void enterArray(int[], int);
void swap(int[], int);
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
	int const n = 10;
	int array[n] = { 0 };
	enterArray(array, n);
	swap(array, n);
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	system("pause");
	system("cls");

}
void enterArray(int array1[], int n)
{
	cout << "Hello! Enter the set of integers.\n";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << (i + 1) << "]=";
		cin >> array1[i];
	}
}
void swap(int array[], int n)
{
	for (int i = 0, t = 0, k = n - 1; k > i; i++, k--)
	{
		t = array[i];
		array[i] = array[k];
		array[k] = t;
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
			cout << "Error,try again.\n";
			system("pause");
			system("cls");
		}
	}
}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1);
	testing(testNumber++, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1);
	testing(testNumber++, 11, 2, 7, 7, 9, 9, 7, 7, 2, 11);
	testing(testNumber++, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0);
	testing(testNumber++, 2, 2, 5, 3, 3, 3, 3, 5, 2, 2);
	system("pause");
	system("cls");
}
void testing(int testNumber, int arr11, int arr12, int arr13, int arr14, int arr15, int arr21, int arr22, int arr23, int arr24, int arr25)
{
	int const n = 5;
	int array1[n] = { 0 };
	int array2[n] = { 0 };
	array1[0] = arr11;
	array1[1] = arr12;
	array1[2] = arr13;
	array1[3] = arr14;
	array1[4] = arr15;
	array2[0] = arr21;
	array2[1] = arr22;
	array2[2] = arr23;
	array2[3] = arr24;
	array2[4] = arr25;
	swap(array1, n);
	bool t = true;
	for (int i = 0; i < n; i++)
	{
		if (array1[i] == array2[i])
		{
			t = true;
			continue;
		}
		else
		{
			t = false;
			break;
		}
	}
	if (t)
		cout << "Test # " << testNumber << " is correct.\n";
	else
		cout << "Test # " << testNumber << " isn't correct.\n";

}