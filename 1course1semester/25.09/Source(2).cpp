#include <iostream>

using namespace std;

int main()
{
	int n;
	while (true)
	{

		cout << "Enter n.\n";
		cin >> n;
		if (n > 0)
		{
			break;
		}
		cout << "n must be > 0\n";
		system("pause");
		system("cls");
	}
	double sum = 0, sum1 = 0;
	int i = 1, k = 1;
	while (i <= n)
	{
		
		sum1 = sum1 + sin(i);
		i = i + 1;
		sum = sum + (double)k / sum1;
		
		

	}
	cout << sum;
	return 0;
}
