#include <iostream>

using namespace std;
int enterNumber();
int numberOfDigits(int);
bool logicPolindrom(int, int);
void display(bool);
void console();
void menu();
void runTest();
void testing(int, int, int, bool);

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
	n = abs(n);
	return n;
}
int numberOfDigits(int n)
{
	int i = 0;
	while (n != 0)
	{
		n = n / 10;
		i = i + 1;
	}
	return i;
}
bool logicPolindrom(int n, int i)
{
	bool t = true;
	int sum = 0;
	int k = 0;
	k = n;
	for (int c = 1, a = 0; c <= i; c++)
	{
		a = k % 10;
		sum = 10 * (sum + a);
		k = k / 10;
	}
	sum = sum / 10;
	if (sum == n)
		t = true;
	else
		t = false;

	return t;
}
void display(bool t)
{
	if (t)
	{
		cout << "Number is polindrom\n";
	}
	else
	{
		cout << "Number isn't polindrom\n";
	}
}
void console()
{
	char ok = 'f';
	while (ok == 'f')
	{
		int n = enterNumber();
		int i = numberOfDigits(n);
		bool t = logicPolindrom(n, i);
		display(t);
		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}
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
	testing(testNumber++, 12345, 5, 0);
	testing(testNumber++, 0, 1, 1);
	testing(testNumber++, 1256521, 7, 1);
	testing(testNumber++, 132245, 6, 0);
	testing(testNumber++, 22, 2, 1);
}
void testing(int testNumber, int n, int i, bool k)
{
	bool act = logicPolindrom(n, i);
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
