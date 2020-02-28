#include <iostream>
#include "Header.h"

using namespace std;

RationalFraction::RationalFraction()
{
	numerator = 1;
	denominator = 1;
}
RationalFraction::RationalFraction(int num, int denom)
{
	numerator = num;
	denominator = denom;
}
int RationalFraction::getNumerator() const
{
	return numerator;
}
void RationalFraction::Display()
{
	if (numerator * denominator >= 0)
	{
		if (abs(denominator) / NOD() == 1)
		{
			cout << abs(numerator) / NOD() << endl;
		}
		else
		{
			cout << abs(numerator) / NOD() << "/" << abs(denominator) / NOD() << endl;
		}
	}
	else
	{
		if (abs(denominator) / NOD() == 1)
		{
			cout << "-" << abs(numerator) / NOD() << endl;
		}
		else
		{
			cout << "-" << abs(numerator) / NOD() << "/" << abs(denominator) / NOD() << endl;
		}
	}
}
void RationalFraction::Enter()
{
	cout << "Enter the Numerator -";
	cin >> numerator;
	cout << "Enter the Denominator -";
	cin >> denominator;
	while (denominator == 0)
	{
		system("cls");
		cout << "Enter the Numerator -";
		cin >> numerator;
		cout << "Enter the Denominator -";
		cin >> denominator;
	}
}
int RationalFraction::getDenominator() const
{
	return denominator;
}
int RationalFraction::NOD()
{
	int min = abs(numerator < denominator ? numerator : denominator);
	int NOD = min;
	if (min == 0)
	{
		return 1;
	}
	while (min > 0)
	{
		if (numerator % min == 0)
		{
			if (denominator % min == 0)
			{
				NOD = min;
				break;
			}
		}
		min--;
	}
	return NOD;
}

#pragma region Prototyps
typedef RationalFraction(*Operation)(RationalFraction, RationalFraction);
void menu();
void workWithConsole();
RationalFraction sum(RationalFraction, RationalFraction);
RationalFraction product(RationalFraction, RationalFraction);
RationalFraction reverse(RationalFraction);
RationalFraction power(RationalFraction, short);
int power(int, short);
bool areEqual(RationalFraction, RationalFraction);
void runTest();
void testing(RationalFraction, RationalFraction, RationalFraction, short, Operation);
void testingReverse(RationalFraction, RationalFraction, short);
void testingPower(RationalFraction, RationalFraction, short);
#pragma endregion


int main()
{
	menu();
	return 0;
}


void menu()
{
	enum button { console = '1', test = '2', exit = '3' };
	char button = '0';
	while (button)
	{
		cout << "Press 1 to work with console." << endl;
		cout << "Press 2 to start test." << endl;
		cout << "Press 3 to exit." << endl;
		cin >> button;
		system("cls");
		switch (button)
		{
		case console:
			workWithConsole();
			system("pause");
			break;
		case test:
			runTest();
			system("pause");
			break;
		case exit:
			return;
		default:
			cout << "Error. Try again." << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	}
}
void workWithConsole()
{
	enum button { Sum = '1', Product = '2', Reverse = '3', Power = '4' };
	char button = '0';
	while (button)
	{
		cout << "Press 1 to solve sum." << endl;
		cout << "Press 2 to solve product." << endl;
		cout << "Press 3 to reverse." << endl;
		cout << "Press 4 to raise in power." << endl;
		cout << "Press 0 to exit." << endl;
		cin >> button;
		system("cls");
		if (button == '0')
		{
			return;
		}
		RationalFraction expr1, expr2;
		cout << "Enter the first rational fraction." << endl;
		expr1.Enter();
		cout << "Enter the second rational fraction." << endl;
		expr2.Enter();
		switch (button)
		{
		case Sum:
			sum(expr1, expr2).Display();
			system("pause");
			break;
		case Product:
			product(expr1, expr2).Display();
			system("pause");
			break;
		case Reverse:
			reverse(expr1).Display();
			cout << endl;
			reverse(expr2).Display();
			system("pause");
			break;
		case Power:
			short exponent;
			cout << "Enter the exponent." << endl;
			cin >> exponent;
			power(expr1, exponent).Display();
			cout << endl;
			power(expr2, exponent).Display();
			system("pause");
			break;
		default:
			cout << "Error. Try again." << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	}
}

RationalFraction sum(RationalFraction expr1, RationalFraction expr2)
{
	return RationalFraction(expr1.getNumerator() * expr2.getDenominator() + expr2.getNumerator() * expr1.getDenominator(), expr1.getDenominator() * expr2.getDenominator());
}
RationalFraction product(RationalFraction expr1, RationalFraction expr2)
{
	return RationalFraction(expr1.getNumerator() * expr2.getNumerator(), expr1.getDenominator() * expr2.getDenominator());
}
RationalFraction reverse(RationalFraction expr)
{
	if (expr.getNumerator() == 0)
	{
		throw std::invalid_argument("You can't divide by zero");
	}
	return RationalFraction(expr.getDenominator(), expr.getNumerator());
}
RationalFraction power(RationalFraction expr, short exponent)
{
	return RationalFraction(power(expr.getNumerator(), exponent), power(expr.getDenominator(), exponent));
}
int power(int number, short exponent)
{
	int num = number;
	if (exponent == 0)
	{
		return 1;
	}
	for (int i = 1; i < exponent; i++)
	{
		number *= num;
	}
	return number;
}

void runTest()
{
	testing(RationalFraction(1, 2), RationalFraction(1, 2), RationalFraction(1, 1), 1, sum);
	testing(RationalFraction(10, 17), RationalFraction(8, 5), RationalFraction(16, 17), 2, product);
	testing(RationalFraction(121, 242), RationalFraction(1, 2), RationalFraction(1, 1), 3, sum);
	testing(RationalFraction(0, 10), RationalFraction(10, 2), RationalFraction(0, 20), 4, product);
	testing(RationalFraction(12, 27), RationalFraction(13, 81), RationalFraction(49, 81), 5, sum);
	testingReverse(RationalFraction(100, 21), RationalFraction(21, 100), 6);
	testingReverse(RationalFraction(40, 20), RationalFraction(2, 4), 7);
	testingPower(RationalFraction(1, 10), RationalFraction(1, 100), 8);
	testingPower(RationalFraction(7, 49), RationalFraction(1, 49), 9);
}
void testing(RationalFraction expr1, RationalFraction expr2, RationalFraction expr, short number, Operation func)
{
	if (areEqual(func(expr1, expr2), expr))
	{
		cout << "Test # " << number << " is correct" << endl;
	}
	else
	{
		cout << "Test # " << number << " isn't correct" << endl;
	}
}
void testingReverse(RationalFraction expr1, RationalFraction expr2, short number)
{
	if (areEqual(reverse(expr1), expr2))
	{
		cout << "Test # " << number << " is correct" << endl;
	}
	else
	{
		cout << "Test # " << number << " isn't correct" << endl;
	}
}
void testingPower(RationalFraction expr1, RationalFraction expr2, short number)
{
	if (areEqual(power(expr1, 2), expr2))
	{
		cout << "Test # " << number << " is correct" << endl;
	}
	else
	{
		cout << "Test # " << number << " isn't correct" << endl;
	}
}
bool areEqual(RationalFraction expr1, RationalFraction expr2)
{
	if (expr1.getNumerator() / expr1.NOD() == expr2.getNumerator() / expr2.NOD() && expr1.getDenominator() / expr1.NOD() == expr2.getDenominator() / expr2.NOD())
	{
		return true;
	}
	return false;
}