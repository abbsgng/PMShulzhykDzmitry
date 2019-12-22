#include <iostream>
#include "workWithString.h"
#include "arrayComprasion(char).h"

using namespace std;

void menu();
void console();
char* replacementString(char*, int, char*, int, char*, int);
void validation(char*, char*, char*);
void runTest();
void testing(int testNumber, char string[], int ls, char deleteString[], int lds, char addString[], int las, char finishString[], int lfs);

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

	char* addString = new char[n];
	cout << "And now, enter the substring you want to add.\n";
	cin.getline(addString, n, '\n');

	int ls = getlength(string);
	int lds = getlength(deleteString);
	int las = getlength(addString);

	char* finishString = replacementString(string, ls, deleteString, lds, addString, las);
	cout << finishString;
}
char* replacementString(char* string, int ls, char* deleteString, int lds, char* addString, int las)
{
	validation(string, deleteString, addString);
	int index1 = indexSubstringInString(string, ls, deleteString, lds);
	int index2 = index1 + lds;
	int lfs = las + ls - lds + 1;
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
	for (int i = index1, k = 0; i < index1 + las; i++, k++)
	{
		finishString[i] = addString[k];
	}
	for (int i = index1 + las, k = index2; i < lfs; i++, k++)
	{
		finishString[i] = string[k];
	}
	finishString[lfs] = '\0';

	return replacementString(finishString, lfs, deleteString, lds, addString, las);
}
void validation(char* string, char* deleteString, char* addString)
{
	if (string == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
	if (deleteString == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
	if (addString == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}
}
void runTest()
{
	int testNumber = 1;

	char string[] = "hello world";
	char deleteString[] = "hello";
	char addString[] = "world";
	char finishString[] = "world world";
	int ls = getlength(string);
	int lds = getlength(deleteString);
	int las = getlength(addString);
	int lfs = getlength(finishString);
	testing(testNumber++, string, ls, deleteString, lds, addString, las, finishString, lfs);

	char string1[] = "hello hello world world";
	char deleteString1[] = "hello";
	char addString1[] = "world";
	char finishString1[] = "world world world world";
	int ls1 = getlength(string1);
	int lds1 = getlength(deleteString1);
	int las1 = getlength(addString1);
	int lfs1 = getlength(finishString1);
	testing(testNumber++, string1, ls1, deleteString1, lds1, addString1, las1, finishString1, lfs1);

	char string2[] = "hello";
	char deleteString2[] = "hello";
	char addString2[] = "123456789";
	char finishString2[] = "123456789";
	int ls2 = getlength(string2);
	int lds2 = getlength(deleteString2);
	int las2 = getlength(addString2);
	int lfs2 = getlength(finishString2);
	testing(testNumber++, string2, ls2, deleteString2, lds2, addString2, las2, finishString2, lfs2);

	char string3[] = "1234567";
	char deleteString3[] = "1234";
	char addString3[] = "00000000";
	char finishString3[] = "00000000567";
	int ls3 = getlength(string3);
	int lds3 = getlength(deleteString3);
	int las3 = getlength(addString3);
	int lfs3 = getlength(finishString3);
	testing(testNumber++, string3, ls3, deleteString3, lds3, addString3, las3, finishString3, lfs3);
}
void testing(int testNumber, char string[], int ls, char deleteString[], int lds, char addString[], int las, char finishString[], int lfs)
{
	char* actual = replacementString(string, ls, deleteString, lds, addString, las);
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