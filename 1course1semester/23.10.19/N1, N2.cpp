#include <iostream>

using namespace std;

int enterNumber();
int numberOf1(int n);
int numberOf0(int n);
void workWithConsole();
void display(int, int, int);
void menu();
void runTest();
void testing(int, int, int, int, int);

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
int numberOf1(int n)
{
	int a = 0;
	while (n != 0)
	{
		if (n % 2 == 1)
			a++;
		n = n / 2;
	}
	return a;
}
int numberOf0(int k)
{
	int b = 0;
	if (k == 0)
		b++;
	while (k != 0)
	{
		if (k % 2 == 0)
			b++;
		k = k / 2;
	}
	return b;
}
void workWithConsole()
{
	char ok = 'f';
	while (ok == 'f')
	{

		int k = 0;
		int n = enterNumber();
		k = n;
		int a = numberOf1(n);
		int b = numberOf0(k);
		display(n, a, b);
		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}
}
void display(int n, int a, int b)
{
	cout << "In binary representation of the number " << n << ":" << endl;
	cout << a << " units and " << b << " zero" << endl;

}
void menu()
{
	while (true)
	{
		int k;
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to work to start test.\n";
		cout << "Press 3 to work with to exit.\n";
		cin >> k;

		system("cls");


		switch (k)
		{
		case 1:
			workWithConsole();
			break;
		case 2:
			runTest();
			break;
		case 3:
			return;
		default:
			cout << "Operation does not make sense.Try again.\n";
		}
	}


}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 0, 0, 0, 1);
	testing(testNumber++, 1, 1, 1, 0);
	testing(testNumber++, 2, 2, 1, 1);
	testing(testNumber++, 3, 3, 2, 0);
	testing(testNumber++, 24, 24, 2, 3);
	testing(testNumber++, 15, 15, 4, 0);
	testing(testNumber++, 156789, 156789, 9, 9);
	testing(testNumber++, 100, 100, 3, 4);
	testing(testNumber++, 111001, 111001, 9, 8);
	testing(testNumber++, 200000, 200000, 6, 12);
	testing(testNumber++, 2456, 2456, 5, 7);
}
void testing(int testNumber, int n, int k, int a, int b)
{
	int act1 = numberOf1(n);
	int act2 = numberOf0(k);
	if (act1 == a && act2 == b)
	{
		cout << "Case # " << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Case # " << testNumber << " isn't correct.\n";
	}

}