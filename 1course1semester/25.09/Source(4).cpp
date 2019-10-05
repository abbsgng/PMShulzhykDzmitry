#include <iostream>

using namespace std;

int main()
{
	char ok = 'f';
	while (ok == 'f')
	{
		int n;
		cout << "Enter the number.\n";
		cin >> n;
		double sum = 0;
		int i = 1;
		while (i <= n)
		{
			sum = sqrt(sum + 2);
			i++;
		}
		cout << "Sum(" << n << ")=" << sum << endl;
		cout << "Press f to restart\n";
		cin >> ok;
		system("cls");
	}

	return 0;

}