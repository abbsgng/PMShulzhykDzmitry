#include <iostream>

using namespace std;


int main()
{
	char ok = 'f';
	while (ok == 'f')

	{
		char m;
		cout << "Press a to calculate the first amount.\n";
		cout << "Press b to calculate the first amount.\n";
		cout << "Press c to calculate the first amount.\n";
		cout << "Press d to calculate the first amount.\n";
		cout << "Press e to calculate the first amount.\n";
		cin >> m;
		int n;
		double sum = 0, sum1 = 0;
		system("cls");
		if (m == 'a' || m == 'b' || m == 'c' || m == 'd' || m == 'e')
		{
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
		}
		bool t = 1;
		switch (m)
		{
		case 'a':

			for (int i = 1, k = -1; i <= n; i++, k = -k)
			{
				sum = sum + (double)k / (2 * i + 1);
			}
			break;

		case 'b':

			for (int i = 1, k = 1; i <= n; i++, k = -k)
			{
				sum = sum + (double)k / (i * (i + 1));
			}
			break;

		case 'c':

			for (int i = 1, k = 1, fact = 1; i <= n; i++, fact = fact * i)
			{
				sum1 = sum1 + ((double)k / i);
				sum = sum + (fact / sum1);
			}
			break;

		case 'd':

			for (int i = 1; i <= n; i++)
			{
				sum = sqrt(sum + 2);
			}
			break;

		case 'e':

			for (int i = 1, k = 1; i <= n; i++)
			{
				sum1 = sum1 + sin(i);
				sum = sum + (double)k / sum1;
			}
			break;

		default:
			t = false;
		}
		if (t)
		{
			cout << "Sum(" << n << ")=" << sum << endl;
		}
		else
		{
			cout << "ERROR.\n";
		}

		cout << "Press 'f' to restart.\n";
		cin >> ok;
		system("cls");
	}
	return 0;
}