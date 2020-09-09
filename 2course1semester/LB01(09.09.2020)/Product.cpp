#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include <iostream>

using namespace std;

Product::Product()
{
	setCost(0);
	setShelfLife(0);
	setQuantity(0);
	setName("-");
	setMaker("-");
}

Product::Product(const char* name, const char* maker, int cost, int shelfLife, int quantity)
{
	setCost(cost);
	setShelfLife(shelfLife);
	setQuantity(quantity);
	setName(name);
	setMaker(maker);
}

void Product::setProduct(const char* name, const char* maker, int cost, int shelfLife, int quantity)
{
	setCost(cost);
	setShelfLife(shelfLife);
	setQuantity(quantity);
	setName(name);
	setMaker(maker);
}

int Product::getCost()
{
	return cost;
}

int Product::getShelfLife()
{
	return shelfLife;
}

int Product::getQuantity()
{
	return quantity;
}

char* Product::getName()
{
	char* buffer = new char[strlen(name) + 1];
	strcpy(buffer, name);
	return buffer;
}

char* Product::getMaker()
{
	char* buffer = new char[strlen(maker) + 1];
	strcpy(buffer, maker);
	return buffer;
}

void Product::setCost(int cost)
{
	this->cost = cost;
}

void Product::setShelfLife(int shelfLife)
{
	this->shelfLife = shelfLife;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::setName(const char* source)
{
	if (name != nullptr)
	{
		delete[] name;
	}
	name = new char[strlen(source) + 1];
	strcpy(name, source);
}

void Product::setMaker(const char* maker)
{
	if (this->maker != nullptr)
	{
		delete[] this->maker;
	}
	this->maker = new char[strlen(maker) + 1];
	strcpy(this->maker, maker);
}

void Product::enter()
{
	cin.ignore();
	const int N = 20;
	char* name = new char[N];
	char* maker = new char[N];
	int cost, shelfLife, quantity;
	cout << "Enter the product:\n";
	cout << "Name: ";
	cin.getline(name, N, '\n');
	cout << "Maker: ";
	cin.getline(maker, N,'\n');
	cout << "Cost: ";
	cin >> cost;
	cout << "Shelf Life: ";
	cin >> shelfLife;
	cout << "Quantity: ";
	cin >> quantity;
	setProduct(name, maker, cost, shelfLife, quantity);
	delete[] name;
	delete[] maker;
}

Product::~Product()
{
	delete[] name;
	delete[] maker;
}

ostream& operator<<(ostream& stream, Product& product)
{
	stream << product.name << endl;
	stream << product.maker << endl;
	stream << product.cost << endl;
	stream << product.shelfLife << endl;
	stream << product.quantity << endl;
	return stream;
}
