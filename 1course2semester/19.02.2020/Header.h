#pragma once
#include <iostream>

using namespace std;

class RationalFraction
{
private:
public:
	int x;
	int y;
	int NOD()
	{
		int min = abs(x < y ? x : y);
		int NOD = min;
		if (min == 0)
		{
			return 1;
		}
		while (min > 0)
		{
			if (x % min == 0)
			{
				if (y % min == 0)
				{
					NOD = min;
					break;
				}
			}
			min--;
		}
		return NOD;
	}
	RationalFraction()
	{
		x = 1;
		y = 1;
	}
	RationalFraction(int a, int b)
	{
		if (b == 0)
		{
			throw std::invalid_argument("You can't divide by zero");
		}
		x = a;
		y = b;
		int t = NOD();
		x = a / t;
		y = b / t;
	}
	void display()
	{

		if (x * y >= 0)
		{
			if (abs(y) / NOD() == 1)
			{
				cout << abs(x) / NOD() << endl;
			}
			else
			{
				cout << abs(x) / NOD() << "/" << abs(y) / NOD() << endl;
			}
		}
		else
		{
			if (abs(y) / NOD() == 1)
			{
				cout << "-" << abs(x) / NOD() << endl;
			}
			else
			{
				cout << "-" << abs(x) / NOD() << "/" << abs(y) / NOD() << endl;
			}
		}
	}
	void enter()
	{
		cout << "Enter the Numerator -";
		cin >> x;
		cout << "Enter the Denominator -";
		cin >> y;
		while (y == 0)
		{
			system("cls");
			cout << "Enter the Numerator -";
			cin >> x;
			cout << "Enter the Denominator -";
			cin >> y;
		}
	}
};