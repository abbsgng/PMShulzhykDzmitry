#include <iostream>

using namespace std;


int main()
{
	char ok = 'f';
	int i;

	while (ok == 'f')
	{
		while (true)
		{
			int n;
			cout << "Enter the month number.\n";
			cin >> n;

			if (n <= 12 && n > 0)
			{
				i = n;
				break;
			}
			else
			{
				cout << "Such a month does not exist, enter the new.\n";
				system("pause");
				system("cls");
			}
		}

		switch (i)
		{
		case 1:
		case 2:
		case 12:
			cout << "Ooo, it's winter.\n";
			break;
		case 3:
		case 4:
		case 5:
			cout << "Ooo, it's spring.\n";
			break;
		case 6:
		case 7:
		case 8:
			cout << "Ooo, it's summer.\n";
			break;
		case 9:
		case 10:
		case 11:
			cout << "Ooo, it's autumn.\n";
			break;

		}
		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}

	return 0;
}