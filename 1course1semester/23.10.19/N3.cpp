#include <iostream>

using namespace std;

int enterNumber();
char enterSymbol();
void console();
int logic(int, char);
void display(int, int, char);
void menu();
void runTest();
void testing(int, int, char, int);

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
char enterSymbol()
{
	char sym;
	cout << "Enter the symbol.\n";
	cin >> sym;
	return sym;
}
void console()
{
	char ok = 'f';
	while (ok == 'f')
	{
		int n = enterNumber();
		char sym = enterSymbol();
		int a = logic(n, sym);
		display(n, a, sym);
		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");

	}
}
int logic(int n, char sym)
{
	int a = 0;
	switch (sym)
	{
	case 'A':
		while (n != 0)
		{
			if (n % 16 == 10 || n == 10)
				a++;
			n = n / 16;
		}
		break;
	case 'B':
		while (n != 0)
		{
			if (n % 16 == 11 || n == 11)
				a++;
			n = n / 16;
		}
		break;
	case 'C':
		while (n != 0)
		{
			if (n % 16 == 12 || n == 12)
				a++;
			n = n / 16;
		}
		break;
	case 'D':
		while (n != 0)
		{
			if (n % 16 == 13 || n == 13)
				a++;
			n = n / 16;
		}
		break;
	case 'E':
		while (n != 0)
		{
			if (n % 16 == 14 || n == 14)
				a++;
			n = n / 16;
		}
		break;
	case 'F':
		while (n != 0)
		{
			if (n % 16 == 15 || n == 15)
				a++;
			n = n / 16;
		}
		break;
	default:
		a = 0;
	}
	return a;
}
void display(int n, int a, char sym)
{

	cout << "In  representation of the number " << n << ":" << endl;
	cout << a << " symbol " << sym << endl;


}
void menu()
{
	while (true)
	{
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		char i;
		cin >> i;
		system("cls");
		switch (i)
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
			cout << "Operation does not make sense.Try again.\n";
		}

	}
}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 14567, 'E', 1);
	testing(testNumber++, 888, 'A', 0);
	testing(testNumber++, 10, 'A', 1);
	testing(testNumber++, 199999, 'D', 1);
	testing(testNumber++, 199999, 'F', 1);
	testing(testNumber++, 64, 'C', 0);
	testing(testNumber++, 11189453, 'C', 2);
	testing(testNumber++, 11189453, 'A', 2);
	testing(testNumber++, 11189453, 'B', 1);
	testing(testNumber++, 11189453, 'D', 1);

}
void testing(int testNumber, int n, char sym, int a)
{
	int act = logic(n, sym);
	if (act == a)
	{
		cout << "Test # " << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Test #" << testNumber << " isn't correct.\n";
	}
}