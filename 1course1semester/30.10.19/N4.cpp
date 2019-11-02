#include <iostream>

using namespace std;

void console();
void enterArray(int[], int);
int  logic(int[], int);
void display(int);
void menu();
void runTest();
void testing(int, int, int, int, int, int, int);

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
	int t = logic(array, n);
	display(t);
	system("pause");
	system("cls");
}
void enterArray(int array[], int n)
{
	cout << "Hello! Enter the set of integers.\n";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << (i + 1) << "]=";
		cin >> array[i];
	}
}
int  logic(int array[], int n)
{
	int a = 0, b = 0, c = 0;
	int t = 0;
	for (int i = 0, k = 1; k < n && i < n; i++, k++)
	{
		if (array[i] > array[k])
			a++;
		if (array[i] < array[k])
			b++;
		if (array[i] == array[k])
			c++;
	}
	if (a > 0 && b > 0)
		t = 1; // никакая
	if (a > 0 && b == 0 && c == 0)
		t = 2; // строго убывающая
	if (a > 0 && b == 0 && c > 0)
		t = 3; // убывающая
	if (a == 0 && b > 0 && c == 0)
		t = 4; // строго возрастающая
	if (a == 0 && b > 0 && c > 0)
		t = 5; // возрастающая
	if (a == 0 && b == 0 && c > 0)
		t = 6; // монотонная

	return t;



}
void display(int t)
{
	switch (t)
	{
	case 1:
		cout << "Sequence undefined.\n";
		break;
	case 2:
		cout << "Stricly decreasing sequence.\n";
		break;
	case 3:
		cout << "Decreasing undefined.\n";
		break;
	case 4:
		cout << "Stricly increasing undefined.\n";
		break;
	case 5:
		cout << "Increasing undefined.\n";
		break;
	case 6:
		cout << "Monotonous undefined.\n";
	}
}
void menu()
{
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
}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 6, 7, 8, 9, 10, 4);
	testing(testNumber++, 1, 1, 2, 2, 2, 5);
	testing(testNumber++, 6, 7, 8, 9, 8, 1);
	testing(testNumber++, 5, 4, 3, 2, 1, 2);
	testing(testNumber++, 66, 66, 66, 0, -1, 3);
	testing(testNumber++, 0, 0, 0, 0, 0, 6);
	system("pause");
	system("cls");
}
void testing(int testNumber, int array1, int array2, int array3, int array4, int array5, int t)
{
	int const n = 5;
	int array[n] = { 0 };
	array[0] = array1;
	array[1] = array2;
	array[2] = array3;
	array[3] = array4;
	array[4] = array5;
	int actual = logic(array, n);
	if (actual == t)
		cout << "Test # " << testNumber << " is correct.\n";
	else
		cout << "Test # " << testNumber << " isn't correct.\n";
}