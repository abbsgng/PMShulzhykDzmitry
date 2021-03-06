#include <iostream>

#pragma once

class Product
{
public:
	Product() :Product("-", "-", 0, 0, 0) {}
	Product(const char*, const char*, int, int, int);
	void setProduct(const char*, const char*, int, int, int);
	int getCost();
	int getShelfLife();
	int getQuantity();
	char* getName();
	char* getMaker();
	void setCost(int);
	void setShelfLife(int);
	void setQuantity(int);
	void setName(const char*);
	void setMaker(const char*);
	void enter();
	friend std::ostream& operator<<(std::ostream& stream, Product& product);
	friend std::istream& operator>>(std::istream& stream, Product& product);
	~Product();
private:
	char* name = nullptr;
	char* maker = nullptr;
	int cost;
	int shelfLife;
	int quantity;
};

