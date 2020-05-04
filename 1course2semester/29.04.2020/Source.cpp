#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	const int N = 15;
	int* array = new int[N] {0};
	for (int i = 2; i < N-3; ++i)
	{
		array[i] = 1;
	}
	
	LinkedList list(array, N);
	cout << list;

	list.removeElement(0);
	cout << list;
	delete[] array;
	return 0;
}