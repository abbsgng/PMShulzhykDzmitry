#include <iostream>
#include "Header.h"
#include <ctime>

using namespace std;

void menu();
void console();
void runTest();
void testing(short);
bool arrayIsSorted(Point*, const int);
void shuffle(Point*, const int);
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
	menu();
	return 0;
}

void menu()
{
	while (true)
	{
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		char n;
		cin >> n;
		system("cls");
		switch (n)
		{
		case '1':
			console();
			system("pause");
			break;
		case '2':
			runTest();
			system("pause");
			break;
		case '3':
			return;
		default:
			cout << "Error. Try again.\n";
			system("pause");
			system("cls");
		}
		system("cls");
	}
}
void console()
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

void runTest()
{
	testing(1);
	testing(2);
	testing(3);
	testing(4);
	testing(5);
}
void testing(short number)
{
	const int n = number * 1000;
	Point* pointers = new Point[n];
	generateArrayPointers(pointers, n);
	bubleSortPointers(pointers, n);
	if (arrayIsSorted(pointers, n))
	{
		cout << "Test #" << number << "(a) is correct." << endl;
	}
	else
	{
		cout << "Test #" << number << "(a) isn't correct." << endl;
	}
	shuffle(pointers, n);
	bubleSortPointers(pointers, n);
	if (arrayIsSorted(pointers, n))
	{
		cout << "Test #" << number << "(b) is correct." << endl;
	}
	else
	{
		cout << "Test #" << number << "(b) isn't correct." << endl;
	}
	deleteMemory(pointers);
}

bool arrayIsSorted(Point* pointers, const int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (pointers[i].lengthVector() > pointers[i + 1].lengthVector())
		{
			return false;
		}
	}
	return true;
}
void shuffle(Point* pointers, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		swap(pointers[rand() % n], pointers[rand() % n]);
	}
}