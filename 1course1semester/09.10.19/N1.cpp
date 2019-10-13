#include <iostream>

using namespace std;

int enterNumber();
bool primeNumber(int);
void console();
void display(int n, bool t);


int main()
{
	console();
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
	char ok = 'f';
	while (ok == 'f')
	{

		int n = enterNumber();
		bool t = primeNumber(n);
		display(n, t);
		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}
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