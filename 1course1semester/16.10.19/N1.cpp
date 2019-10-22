#include <iostream>

using namespace std;

int enterNumber();
bool primeNumber(int);
void console();
void display(int n, bool t);
void menu();
void runTest();
void testing(int, int, bool);


int main()
{
	menu();
	return 0;
}
int enterNumber()
{
	int n;
	cout << "Enter the number.\n";
	cin >> n;
	return n;
}
void console()
{
	int n = enterNumber();
	bool t = primeNumber(n);
	display(n, t);
}
bool primeNumber(int n)
{
	bool t = true;
	n = abs(n);
	if (n == 0 || n == 1)
		t = false;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				t = false;
				break;
			}
			else
			{
				continue;
			}
		}
	}
	return t;
}
void display(int n, bool t)
{
	if (t)
		cout << "Number is prime.\n";
	else
		cout << "Number isn't prime.\n";
}
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
			console();
			break;
		case '2':
			runTest();
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
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 11, 1);
	testing(testNumber++, 12, 0);
	testing(testNumber++, 47, 1);
	testing(testNumber++, 132245, 0);
	testing(testNumber++, 0, 0);
}
void testing(int testNumber, int n, bool k)
{
	bool act = primeNumber(n);
	if (act == k)
	{
		cout << "Case # " << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Case # " << testNumber << " isn't correct.\n";
		cout << "Actual is " << act << " ,but expected " << k << endl;
	}
}
