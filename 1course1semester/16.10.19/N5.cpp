#include <iostream>

using namespace std;

short enterDigit();
int enterNumber();
int numberOfDigits(int);
int logicChange(int, short, int);
void display(int);
void console();
void menu();
void runTest();
void testing(int, int, int, short, int);



int main()
{

	menu();
	return 0;
}
short enterDigit()
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

int enterNumber()
{
	int n;

	cout << "Enter number: ";
	cin >> n;

	return n;
}
int logicChange(int n, short d, int i)
{
	int sum = 0;
	for (int a = 0; i > 0; i--)
	{
		a = n / (int)pow(10, i - 1);
		n = n % (int)pow(10, i - 1);
		if (a == d)
		{
			continue;
		}
		else
		{
			sum = 10 * (sum + a);
		}

	}
	sum = sum / 10;
	return sum;



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
void display(int sum)
{
	cout << sum << endl;

}
void console()
{
	short d = enterDigit();
	int n = enterNumber();
	int i = numberOfDigits(n);
	int sum = logicChange(n, d, i);
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
	testing(testNumber++, 123452, 6, 2, 1345);
	testing(testNumber++, 12, 2, 1, 2);
	testing(testNumber++, 10006, 5, 0, 16);
	testing(testNumber++, 12222, 5, 2, 1);
	testing(testNumber++, 123401, 6, 1, 2341);
}
void testing(int testNumber, int n, int i, short d, int sum)
{
	int act = logicChange(n, d, i);
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
