#include <iostream>
#include "arrayComprasion(char).h"

using namespace std;

void console();
int comprasionString(char*, char*);
void display(int);
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
	int t = comprasionString(string1, string2);
	display(t);
}
int comprasionString(char* string1, char* string2)
{
	int size1 = 0;
	for (int i = 0; string1[i] != 0; i++)
	{
		size1++;
	}
	int size2 = 0;
	for (int i = 0; string2[i] != 0; i++)
	{
		size2++;
	}

	if (size1 == size2)
	{
		return 1;
	}
	if (size1 > size2)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
void display(int t)
{
	switch (t)
	{
	case 1:
		cout << "String are equal.\n";
		break;
	case 2:
		cout << "First string are bigger than second string.\n";
		break;
	case 3:
		cout << "First string are smaller than second string.\n";
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
