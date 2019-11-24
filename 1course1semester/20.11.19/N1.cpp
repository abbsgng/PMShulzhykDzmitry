#include <iostream>
#include "arrayComprasion(char).h"

using namespace std;

void console();
bool comprasionString(char*, char*);
void display(bool);
void menu();


int main()
{
	menu();
	return 0;
}
void console()
{
	char string1[] = "Hello, world!";
	int n = sizeof(string1);
	char string2[] = "Hello, world!";
	int m = sizeof(string2);
	bool t = areEqual(string1, n, string2, m);
	display(t);
}
void display(bool t)
{
	if (t)
	{
		cout << "String are equal.\n";
	}
	else
	{
		cout << "String aren't equal.\n";
	}
}
void menu()
{
	while (true)
	{
		char button;
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to exit.\n";
		cin >> button;
		system("cls");
		switch (button)
		{
		case '1':
			console();
			break;
		case '2':
			return;
		default:
			cout << "Error.Try again.\n";
		}

	}
}
