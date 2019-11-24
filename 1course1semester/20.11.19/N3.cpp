#include <iostream>


using namespace std;

void console();
void display(int);
void menu();
int linearSearch(char*, int, const char);


int main()
{
	menu();
	return 0;
}
void console()
{
	char string[] = "Hello, world!";
	int size = sizeof(string) / sizeof(char);
	cout << "Enter the symbol.\n";
	char symbol;
	cin >> symbol;
	int number = linearSearch(string, size, symbol);
	display(number);
}
void display(int t)
{
	if (t == -1)
	{
		cout << "String doesn't have this element\n";
	}
	else
	{
		cout << "This element located in " << t + 1 << " place.\n";
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
int linearSearch(char* string, int size, const char value)
{

	for (int i = 0; i < size; i++)
	{
		if (string[i] == value)
		{
			return i;
		}
	}
	return -1;
}