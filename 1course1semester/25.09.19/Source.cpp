#include <iostream>

using namespace std;

int main()
{
	int n;
	while (true)
	{
		cout << "Enter n.\n";
		cin >> n;
		if (n>0)
		{
			break;
		}
		cout << "n must be > 0\n";
		system("pause");
		system("cls");
	} 

	/*double sum=0;
	int i=1;
	while (i<=n)
	{
		sum = sum + 1. / i;
		i = i + 1;
	}*/
	double sum = 0;
	int i = 1,k=-1;
	while (i <= n)
	{
		sum = sum + (double)k / (2*i+1);
		k = -k;
		i = i + 1;
	}
	cout << "Sum(" << n << ")=" << sum << endl;
	return 0;
}
