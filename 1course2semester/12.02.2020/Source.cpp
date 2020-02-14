#include <iostream>
#include "Header.h"
#include <ctime>

using namespace std;

void generateArrayPointers(Point*, const int);
void displayArrayPointers(Point*, const int);
double* createArrayLengths(Point*, const int);
void displayArrayLengths(double*, const int);
void bubleSortPointers(Point*, const int);
void bubleSortPointers(Point*, const int, double*);
void swap(double*, double*);
void swap(Point*, Point*);
void deleteMemory(Point*);
void deleteMemory(double*);


int main()
{
	srand(time(0));
	const int n = 10;
	Point* pointers = new Point[n];
	generateArrayPointers(pointers, n);
	displayArrayPointers(pointers, n);
	cout << endl;
	double* lengths = createArrayLengths(pointers, n);
	bubleSortPointers(pointers, n, lengths);
	displayArrayPointers(pointers, n);
	deleteMemory(pointers);
	deleteMemory(lengths);
	return 0;
}


void swap(Point* a, Point* b)
{
	Point t = *a;
	*a = *b;
	*b = t;
}
void swap(double* a, double* b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

void generateArrayPointers(Point* pointers, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		pointers[i] = Point(rand() % 20, rand() % 20);
	}
}
double* createArrayLengths(Point* pointers, const int n)
{
	double* lengths = new double[n];
	for (int i = 0; i < n; ++i)
	{
		lengths[i] = pointers[i].lengthVector();
	}
	return lengths;
}

void displayArrayPointers(Point* pointers, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		pointers[i].display();
		cout << endl;
	}
}
void displayArrayLengths(double* lengths, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << lengths[i];
		cout << endl;
	}
}

void bubleSortPointers(Point* pointers, const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (pointers[j].lengthVector() < pointers[j - 1].lengthVector())
			{
				swap(pointers[j], pointers[j - 1]);
			}
		}
	}
}
void bubleSortPointers(Point* pointers, const int n, double* lengths)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (lengths[j] < lengths[j - 1])
			{
				swap(lengths[j], lengths[j - 1]);
				swap(pointers[j], pointers[j - 1]);
			}
		}
	}
}

void deleteMemory(Point* pointers)
{
	delete[] pointers;
}
void deleteMemory(double* lengths)
{
	delete[] lengths;
}