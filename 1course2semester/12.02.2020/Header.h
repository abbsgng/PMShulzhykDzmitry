#pragma once
#include <iostream>

using namespace std;

struct Point
{
	double x;
	double y;
	Point()
	{
		x = rand() % 100;
		y = rand() % 100;
	}
	Point(double a, double b)
	{
		x = a;
		y = b;
	}
	void display()
	{
		cout << "(" << x << ", " << y << ")";
	}
	double lengthVector()
	{
		return sqrt(x * x + y * y);
	}
};