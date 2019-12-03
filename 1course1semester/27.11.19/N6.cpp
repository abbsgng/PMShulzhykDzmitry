#include <iostream>
#include "workWithString.h"
#include "arrayComprasion(char).h"

using namespace std;

void menu();
void console();
char* deleteSubString(char*, int, char*, int);
void validation(char*, char*);
void runTest();
void testing(int testNumber, char string[], int ls, char deleteString[], int lds, char finishString[], int lfs);

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

	char* deleteString = new char[n];
	cout << "Well, enter the substring you want to delete.\n";
	cin.getline(deleteString, n, '\n');

	int ls = getlength(string);
	int lds = getlength(deleteString);

	char* finishString = deleteSubString(string, ls, deleteString, lds);
	cout << finishString;
}
char* deleteSubString(char* string, int ls, char* deleteString, int lds)
{
	//validation(string, deleteString);
	int index1 = indexSubstringInString(string, ls, deleteString, lds);
	int index2 = index1 + lds;
	if (ls < lds)
	{
		return string;
	}
	int lfs = ls - lds;
	char* finishString = new char[lfs];

	if (index1 == -1)
	{
		return string;
	}
	if (index2 == -1)
	{
		throw std::invalid_argument("This string doesn't have deleted string");
	}

	for (int i = 0; i < index1; i++)
	{
		finishString[i] = string[i];
	}
	for (int i = index1, k = index2; i < lfs; i++, k++)
	{
		finishString[i] = string[k];
	}
	finishString[lfs] = '\0';

	return deleteSubString(finishString, lfs, deleteString, lds);
}
void validation(char* string, char* deleteString)
{
	/*if (string == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}*/
	if (deleteString == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
}
void runTest()
{
	int testNumber = 1;

	char string[] = "hello world";
	char deleteString[] = "hello ";
	char finishString[] = "world";
	int ls = getlength(string);
	int lds = getlength(deleteString);
	int lfs = getlength(finishString);
	testing(testNumber++, string, ls, deleteString, lds, finishString, lfs);

	char string1[] = "hello hello world world";
	char deleteString1[] = "hello";
	char finishString1[] = "  world world";
	int ls1 = getlength(string1);
	int lds1 = getlength(deleteString1);
	int lfs1 = getlength(finishString1);
	testing(testNumber++, string1, ls1, deleteString1, lds1, finishString1, lfs1);

	char string2[] = "hello world";
	char deleteString2[] = "v";
	char finishString2[] = "hello world";
	int ls2 = getlength(string2);
	int lds2 = getlength(deleteString2);
	int lfs2 = getlength(finishString2);
	testing(testNumber++, string2, ls2, deleteString2, lds2, finishString2, lfs2);

	char string3[] = "1234567";
	char deleteString3[] = "1234";
	char finishString3[] = "567";
	int ls3 = getlength(string3);
	int lds3 = getlength(deleteString3);
	int lfs3 = getlength(finishString3);
	testing(testNumber++, string3, ls3, deleteString3, lds3, finishString3, lfs3);
}
void testing(int testNumber, char string[], int ls, char deleteString[], int lds, char finishString[], int lfs)
{
	char* actual = deleteSubString(string, ls, deleteString, lds);
	int la = getlength(actual);
	if (areEqual(actual, la, finishString, lfs))
	{
		cout << "Test #" << testNumber << " is correct.\n";
	}
	else
	{
		cout << "Test #" << testNumber << " isn't correct.\n";
	}
}