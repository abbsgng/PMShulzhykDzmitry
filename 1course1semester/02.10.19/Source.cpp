#include <iostream>

using namespace std;


int main()
{
	char ok = 'f';
	int i;

		while (ok=='f')
		{
			while (true)
			{
				int n;
				cout << "Enter the rating.\n";
				cin >> n;

				if (n <= 10 && n > 0)
				{
					i = n;
					break;
				}
				else
				{
					cout << "Such an assessment does not exist.\n";
					system("pause");
					system("cls");
				}
			}
			
			switch (i)
			{
			case 1:
			case 2:
				cout << "Was absent.\n";
				break;
			case 3:
			case 4:
				cout << "Not satisfactorily.\n";
				break;
			case 5:
			case 6:
				cout << "Satisfactorily.\n";
				break;
			case 7:
			case 8:
				cout << "Good.\n";
				break;
			case 9:
			case 10:
				cout << "Excellent.\n";
				break;
			}
			cout << "Press f to restart.\n";
			cin >> ok;
			system("cls");
		}

	return 0;
}