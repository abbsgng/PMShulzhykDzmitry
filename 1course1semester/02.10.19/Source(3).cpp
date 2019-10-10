#include <iostream>

using namespace std;


int enterNumber();
void nullHundreed(int);
void twentyToNinety(int);
void oneToNine(int);
void tenToNineteen(int);


int main()
{
	char ok = 'f';
	while (ok == 'f')
	{
		int k;
		int n = enterNumber();
		nullHundreed(n);
		if (n > 9 && n < 20)
			tenToNineteen(n);
		else
		{
			k = n / 10;
			twentyToNinety(k);
			k = n % 10;
			oneToNine(k);
		}
			cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}
	return 0;
}
int enterNumber()
{
	char ok = 'f';
	int n;
	while (ok == 'f')
	{
		cout << "Enter the number.\n";
		cin >> n;

		if (n >= 0 && n <= 100)
		{
			break;
		}
		cout << "ERROR.\n";


		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}
	return n;
}
void nullHundreed(int n)
{
	if (n == 0)
		cout << "Null.\n";
	else if (n == 100)
		cout << "One hundreed.\n";

}
void twentyToNinety(int k)
{
	switch (k)
	{
	case 2:
		cout << "Twenty";
		break;
	case 3:
		cout << "Thirdty";
		break;
	case 4:
		cout << "Fourty";
		break;
	case 5:
		cout << "Fifty";
		break;
	case 6:
		cout << "Sixty";
		break;
	case 7:
		cout << "Seventy";
		break;
	case 8:
		cout << "Eighty";
		break;
	case 9:
		cout << "Ninety";
		break;
	}
}
void oneToNine(int k)
{
	switch (k)
	{
	case 1:
		cout << "One\n";
		break;
	case 2:
		cout << "Two\n";
		break;
	case 3:
		cout << "Three\n";
		break;
	case 4:
		cout << "Four\n";
		break;
	case 5:
		cout << "Five\n";
		break;
	case 6:
		cout << "Six\n";
		break;
	case 7:
		cout << "Seven\n";
		break;
	case 8:
		cout << "Eight\n";
		break;
	case 9:
		cout << "Nine\n";
		break;
	}
}
void tenToNineteen(int n)
{
	switch (n)
	{
	case 10:
		cout << "Ten\n";
		break;
	case 11:
		cout << "Eleven\n";
		break;
	case 12:
		cout << "Twelf\n";
		break;
	case 13:
		cout << "Thirdteen\n";
		break;
	case 14:
		cout << "Fourteen\n";
		break;
	case 15:
		cout << "Fifteen\n";
		break;
	case 16:
		cout << "Sixteen\n";
		break;
	case 17:
		cout << "Seventeen\n";
		break;
	case 18:
		cout << "Eighteen\n";
		break;
	case 19:
		cout << "Nineteen\n";
		break;
	}
}

