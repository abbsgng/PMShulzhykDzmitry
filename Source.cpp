#include <iostream>
using namespace std;
int main()
{
	cout << "Enter the side lenghts.\n";

	double a, b, c;

	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;

	if (a + b <= c || a + c <= b || b + c <= a)
	{
		cout << "Not triangle.\n";
	}

	else if (a == b && b == c)
	{
		cout << "Triangle is equilateral.\n";
	}

	else if (a == b || a == c || b == c)
	{
		cout << "triangle is isosceles.\n";
	}

	else
	{
		cout << "Triangle versatile.\n";
	}


	system("pause");
	return 0;
}