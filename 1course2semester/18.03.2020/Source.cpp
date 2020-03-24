#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "table.h"

using namespace std;


int main()
{
	int* size = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		size[i] = i+5;
	}
	Table table(10, 6, size);
	table.display();
	delete[] size;

	/*cout << "\xc9\xcd\xcb\xcd\xbb" << endl;
	cout << "\xba \xba \xba" << endl;
	cout << "\xcc\xcd\xce\xcd\xb9" << endl;
	cout << "\xba \xba \xba" << endl;
	cout << "\xc8\xcd\xca\xcd\xbc" << endl;*/
	return 0;
}
