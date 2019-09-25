#include <iostream>
using namespace std;
int main()
{
	cout << "Enter the point.\n ";
	double x, y;
	cout << "x= ";
	cin >> x;
	cout << "y= ";
	cin >> y;

	system("cls");

	if (x > 0 && x * x + y * y <= 1)
	{
		cout << "Point in the area.\n";
	}
	else if (x >= -1 && x <= 0 && y >= -1 && y <= 1)
	{
		cout << "Point in the area.\n";
	}
	else
	{
		cout << "Point not in the area.\n";
	}

	system("pause");
	return 0;
}