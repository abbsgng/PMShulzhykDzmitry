#include <iostream>

using namespace std;

int main()
{
	int n;
	while (true)
	{
		cout << "Enter n\n";
		cin >> n;
			if (n > 0)
			{
				break;
			}
		cout << "n must be > 0";
		system("pause");
		system("cls");
	}
	int i = 1, k = 1, fact = 1;
	double sum = 0, sum1 = 0;
	while (i <= n)
	{
		sum1 = sum1 + ((double)k / i);
		i = i + 1;
		sum = sum + (fact / sum1);
		fact = fact * i;
	}
	cout << sum;
	return 0;
}