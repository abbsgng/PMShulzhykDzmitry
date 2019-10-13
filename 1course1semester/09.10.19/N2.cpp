#include <iostream>

using namespace std; int enterNumber();
int numberOfDigits(int);
bool logicPolindrom(int, int);
void display(bool);

int main()
{
	char ok = 'f';
	while (ok=='f')
	{
		int n = enterNumber();
		int i = numberOfDigits(n);
		bool t = logicPolindrom(n, i);
		display(t);
		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}

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
