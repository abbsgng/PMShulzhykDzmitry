#include <iostream>
using namespace std;
int main()
{
	cout << "Enter the number.\n";

	double a, b, c;

	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;

	double min;

	min = a;
	if (min > b)
	{
		min = b;
	}
	if (min > c)
	{
		min = c;
	}

	cout << "The smallest number " << min << endl;
	system("pause");
	return 0;
}