#include <iostream>
#include "workWithString.h"

using namespace std;

void menu();
void console();
int indexSubstringInString(char* string, int lengthString, char* subString, int lengthSubString);
void validation(char* string, int lengthString, char* subString, int lengthSubString);
void runTest();
void testing(int, char[], int, char[], int, int);

int main()
{
	menu();
	return 0;
}

void menu()
{
	while (true)
	{
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		char button;
		cin >> button;
		system("cls");

		switch (button)
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
	int const n = 256;

	cout << "Hello, enter the string.\n";
	char* string = new char[n];
	cin.getline(string, n, '\n');

	char* subString = new char[n];
	cout << "Well, and now enter the word.\n";
	cin.getline(subString, n, '\n');

	int lengthString = getlength(string);
	int lengthSubString = getlength(subString);

	int index = indexSubstringInString(string, lengthString, subString, lengthSubString);
	cout << index << endl;
}
void runTest()
{
	int testNumber = 1;

	char string[] = "Hello, world!";
	char subString[] = "world!";
	testing(testNumber++, string, 12, subString, 5, 7);

	char string1[] = "dfhgjk";
	char subString1[] = "jki";
	testing(testNumber++, string1, 6, subString1, 3, -1);

	char string2[] = "fgjyyjy";
	char subString2[] = "fgjyyjy";
	testing(testNumber++, string2, 7, subString2, 7, 0);
}
void testing(int testNumber, char string[], int lengthString, char subString[], int lengthSubString, int index)
{
	int actual = indexSubstringInString(string, lengthString, subString, lengthSubString);
	if (actual == index)
	{
		cout << "Test #" << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Test #" << testNumber << " isn't correct.\n";
	}
}