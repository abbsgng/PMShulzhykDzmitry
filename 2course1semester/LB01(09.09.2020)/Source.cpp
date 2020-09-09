#define _CRT_SECURE_NO_WARNINGS_

#include <iostream>
#include "Product.h"

using namespace std;

void menu();
Product* createArray(int&);
void display1(Product*, int);
void display2(Product*, int);
void display3(Product*, int);

int main()
{
	menu();
}

void menu()
{
	int size = 0;
	Product* products = createArray(size);
	while (true)
	{
		system("cls");
		cout << "Press 1 to display list of products for the specified name.\n";
		cout << "Press 2 to display list of products for the specified name, the price of which does not exceed the specified one.\n";
		cout << "Press 3 to display list of products that have a longer shelf life than the specified one.\n";
		cout << "Press 4 to exit.\n";
		short number;
		cin >> number;
		system("cls");
		switch (number)
		{
		case 1:
			display1(products, size);
			system("pause");
			break;
		case 2:
			display2(products, size);
			system("pause");
			break;
		case 3:
			display3(products, size);
			system("pause");
			break;
		case 4:
			return;
		default:
			cout << "ERROR.Try again.\n";
		}
	}
	delete[] products;
}

Product* createArray(int& size)
{
	cout << "How many names do you want to enter :";
	cin >> size;
	Product* array = new Product[size];
	for (int i = 0; i < size; ++i)
	{
		array[i].enter();
	}
	return array;
}

void display1(Product* products, int size)
{
	cin.ignore();
	cout << "Enter the specified name.\n";
	char* name = new char[32];
	cin.getline(name, 32, '\n');
	for (int i = 0; i < size; ++i)
	{
		char* buffer = products[i].getName();
		if (!strcmp(buffer, name))
		{
			cout << products[i];
		}
		delete[] buffer;
	}
	delete[] name;
}

void display2(Product* products, int size)
{
	cout << "Enter the the price.\n";
	int price;
	cin >> price;
	for (int i = 0; i < size; ++i)
	{
		if (products[i].getCost() <= price)
		{
			cout << products[i] << endl;
		}
	}
}

void display3(Product* products, int size)
{
	cout << "Enter the shelfLife.\n";
	int shelf;
	cin >> shelf;
	for (int i = 0; i < size; ++i)
	{
		if (products[i].getShelfLife() > shelf)
		{
			cout << products[i];
		}
	}
}
