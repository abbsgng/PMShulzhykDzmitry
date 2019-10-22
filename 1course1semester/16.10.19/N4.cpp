#include <iostream>

using namespace std;

short enterDigit1();
short enterDigit2();
int enterNumber();
int numberOfDigits(int);
int logicChange(int, short, short, int);
void display(int);
void console();
void menu();
void runTest();
void testing(int, int, short, short, int, int);


int main()
{
	menu();
	return 0;
}
short enterDigit1()
{
	short d;

	while (true)
	{
		cout << "Enter removable digit (0..9):";
		cin >> d;
		if (d >= 0 && d <= 9)
		{
			break;
		}
		cout << "Not didgits! Try again." << endl;
		system("pause");
		system("cls");
	}

	return d;
}
short enterDigit2()
{
	short k;

	while (true)
	{
		cout << "Enter added digit (0..9):";
		cin >> k;
		if (k >= 0 && k <= 9)
		{
			break;
		}
		cout << "Not didgits! Try again." << endl;
		system("pause");
		system("cls");
	}

	return k;
}
int enterNumber()
{
	int n;

	cout << "Enter number: ";
	cin >> n;

	return n;
}
int logicChange(int n, short d, short k, int i)
{
	int sum = 0;
	for (int a = 0; i > 0; i--)
	{
		a = n / (int)pow(10, i - 1);
		if (a == d)
		{
			a = k;
			sum = 10 * (sum + a);
		}
		else
		{
			sum = 10 * (sum + a);
		}
		n = n % (int)pow(10, i - 1);
	}
	sum = sum / 10;
	return sum;





}
void display(int sum)
{
	cout << sum << endl;
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
void console()
{
	short d = enterDigit1();
	short k = enterDigit2();
	int n = enterNumber();
	int i = numberOfDigits(n);
	int sum = logicChange(n, d, k, i);
	display(sum);
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
	testing(testNumber++, 12345, 4, 3, 5, 12335);
	testing(testNumber++, 111112, 1, 3, 6, 333332);
	testing(testNumber++, 11, 1, 2, 2, 22);
	testing(testNumber++, 1256342, 5, 2, 7, 1226342);
	testing(testNumber++, 0, 0, 7, 1, 7);
}
void testing(int testNumber, int n, short d, short k, int i, int sum)
{
	int act = logicChange(n, d, k, i);
	if (act == sum)
	{
		cout << "Case # " << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Case # " << testNumber << " isn't correct.\n";
		cout << "Actual is " << act << " ,but expected " << sum << endl;
	}
}
