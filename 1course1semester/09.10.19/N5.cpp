#include <iostream>

using namespace std;

short enterDigit();
int enterNumber();
int numberOfDigits(int);
void logicChange(int, short, int);



int main()
{
	short d = enterDigit();
	int n = enterNumber();
	int i = numberOfDigits(n);
	logicChange(n, d, i);

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
void logicChange(int n, short d, int i)
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