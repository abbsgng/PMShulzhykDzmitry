#include <iostream>

using namespace std;

void enterArray(int[], int n);
int enterNumber();
int logic(int[], int n, int num);
void console();
void menu();
void runTest();
void testing(int, int, int, int, int, int, int, int);

int main()
{
	menu();
	return 0;
}

void enterArray(int array[], int n)
{
	cout << "Hello! Enter the set of integers.\n";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << (i + 1) << "]=";
		cin >> array[i];
	}
	system("pause");
	system("cls");
}
int enterNumber()
{
	int num;
	cout << "Enter the number.\n";
	cin >> num;
	return num;
}
int logic(int array[], int n, int num)
{
	int amount = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < num)
			amount++;
		else
			continue;

	}
	return amount;
}
void console()
{
	int const n = 10;
	int array[n] = { 0 };
	enterArray(array, n);
	int num = enterNumber();
	int amount = logic(array, n, num);
	cout << "Number of numbers less than " << num << " in your set equals " << amount << endl;
	system("pause");
	system("cls");
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
	testing(testNumber++, 1, 2, 3, 4, 5, 5, 4);
	testing(testNumber++, 2, 18, 9, 157, 2, 10, 3);
	testing(testNumber++, 1, 100, -11, 0, 4, 2, 3);
	testing(testNumber++, 4567, 4567, 17, 1, 1, -2, 0);
	testing(testNumber++, 0, 0, 0, 0, 12, 12, 4);
	system("pause");
	system("cls");
}
void testing(int testNumber, int array1, int array2, int array3, int array4, int array5, int num, int amount)
{
	int const n = 5;
	int array[5] = { 0 };
	array[0] = array1;
	array[1] = array2;
	array[2] = array3;
	array[3] = array4;
	array[4] = array5;
	int actual = logic(array, n, num);
	if (actual == amount)
		cout << "Case # " << testNumber << " is correct.\n";
	else
		cout << "Case # " << testNumber << " isn't correct.\n";
	
}
