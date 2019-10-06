#include <iostream>

using namespace std;

int main()
{
	char ok = 'f';
	cout << "Hello, I will count everything you want.\n";
	while (ok == 'f')
	{
		cout << "Let's go.\n";
		bool t = true;
		double a, b, res = 0;
		char i;
		cin >> a; cin >> i;
	
		
		switch (i)
		{
		case '*':
			cin >> b;
			res = a * b;
			break;
		case '+':
			cin >> b;
			res = a + b;
			break;
		case '-':
			cin >> b;
			res = a - b;
			break;
		case '/':
			cin >> b;
			res = a / b;
			break;
		default:
			t = false;
		}
		if (t)
		{
			cout << "=" << res << endl;
		}
		else
			cout << "ERROR.\n";
		cout << "Press f to restart.\n";
		cin >> ok;
		system("cls");
	}
	return 0;
}