#include <iostream>
#include "workWithString.h"

using namespace std;

int enterNumber();
int enterScaleOfNotation();
char* transferToAnotherSystem(int, int);
void console();
void swap(char*, int);


int main()
{
	console();
	return 0;
}
int enterNumber()
{
	int number;
	cout << "Enter the number." << endl;
	cin >> number;
	return number;
}
int enterScaleOfNotation()
{
	short digit;
	cout << "Enter the scale of notation.\n";
	cin >> digit;
	return digit;
}
char* transferToAnotherSystem(int number, int digit)
{
	int const n = 64;
	char* anotherNumber = new char[n];
	char remainder;
	int i = 0;
	while (number)
	{
		remainder = number % digit;
		number = number / digit;
		if (remainder >= 0 && remainder <= 9)
		{
			remainder = remainder+48;
		}
		else
		{
			remainder = remainder + 55;
		}
		anotherNumber[i] = remainder;
		i++;

	}
	anotherNumber[i] = '\0';
	int gl = getlength(anotherNumber);
	swap(anotherNumber, gl);
	return anotherNumber;
}
void console()
{
	int number = enterNumber();
	int digit = enterScaleOfNotation();
	char* anotherNumber = transferToAnotherSystem(number, digit);
	cout << anotherNumber;
}
void swap(char* arr, int n)
{
	for (int i = 0, t = 0, k = n - 1; k > i; i++, k--)
	{
		t = arr[i];
		arr[i] = arr[k];
		arr[k] = t;
	}
}
