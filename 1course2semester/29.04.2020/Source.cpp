#include <iostream>
#include "LinkedList.h"

using namespace std;



int main()
{
	const int N = 50;
	int* array = new int[N] {0};

	for (int i = 0; i < N; ++i)
	{
		array[i] = rand() % 20;
	}

	LinkedList list(array, N);
	cout << list << endl;
	list.removeElement(7);
	cout << list;

	delete[] array;
	return 0;
}