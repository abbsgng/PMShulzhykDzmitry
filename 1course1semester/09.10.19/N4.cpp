#include <iostream>

using namespace std;

short enterDigit1();
short enterDigit2();
int enterNumber();
int numberOfDigits(int);
void logicChange(int, short, short, int);



int main()
{
	short d = enterDigit1();
	short k = enterDigit2();
	int n = enterNumber();
	int i = numberOfDigits(n);
	logicChange(n, d, k, i);

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
void logicChange(int n, short d, short k, int i)
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
	cout << sum;




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