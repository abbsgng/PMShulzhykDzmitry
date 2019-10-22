#include <iostream>

using namespace std;

int enterNumber();
short digitsInNumber(int);
void counter(int, short, int&, int&, int&);
int logic(int a, int b, int c);
void menu();
void console();
void display(int, short);
void runTest();
void testing(int, int, int, int, int, int);


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
short digitsInNumber(int n)
{
	int i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return i;
}
void counter(int n, short i, int& a, int& b, int& c)
{

	int k = i;
	for (int z = 1; z < k; z++, i--)
	{
		int x = n / (int)pow(10, i - 1);
		int y = (n / (int)pow(10, i - 2)) - (int)10 * x;
		if (x > y)
		{
			a = a + 1;
			n = n % (int)pow(10, i - 1);
			continue;
		}
		if (x < y)
		{
			b = b + 1;
			n = n % (int)pow(10, i - 1);
			continue;
		}
		if (x == y)
		{
			c = c + 1;
			n = n % (int)pow(10, i - 1);
			continue;
		}


	}

}
int logic(int a, int b, int c)
{
	int t = 0;
	if (a == 0 && b == 0)
		t = 1;
	else if (b > 0 && c == 0 && a == 0)
		t = 2;
	else if (b > 0 && c > 0 && a == 0)
		t = 3;
	else if (b == 0 && c == 0 && a > 0)
		t = 4;
	else if (b == 0 && c > 0 && a > 0)
		t = 5;
	else
		t = 6;
	return t;
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
void console()
{
	int n = enterNumber();
	short i = digitsInNumber(n);
	display(n, i);


}
void display(int n, short i)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int& a1 = a;
	int& b1 = b;
	int& c1 = c;
	counter(n, i, a, b, c);
	int t = logic(a, b, c);
	switch (t)
	{
	case 1:
		cout << "Monotonous sequence.\n";
		break;
	case 2:
		cout << "Strictly increasing sequence.\n";
		break;
	case 3:
		cout << "Increasing sequence.\n";
		break;
	case 4:
		cout << "Stricly decreasing sequence.\n";
		break;
	case 5:
		cout << "Decreasing sequence.\n";
		break;
	case 6:
		cout << "Sequence type undefined.\n";
		break;
	}
}
void runTest()
{
	int testNumber = 1;
	testing(testNumber++, 12345, 0, 4, 0, 2);
	testing(testNumber++, 1, 0, 0, 1, 1);
	testing(testNumber++, 12331345, 1, 5, 1, 6);
	testing(testNumber++, 6543210, 6, 0, 0, 4);
	testing(testNumber++, 1223, 0, 2, 1, 3);
	testing(testNumber++, 6661, 1, 0, 2, 5);
	


}
void testing(int testNumber, int n, int a, int b, int c, int t)
{
	int act = logic(a, b, c);
	if (act == t)
	{
		cout << "Case # " << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Case # " << testNumber << " isn't correct.\n";
		cout << "Actual is " << act << " ,but expected " << t << endl;
	}
}
