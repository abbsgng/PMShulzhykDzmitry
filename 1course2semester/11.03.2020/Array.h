#pragma once
#include <iostream>

using namespace std;


class Array
{
public:
	typedef int(*Comparer)(int, int);
	typedef int* (*Rule)(int*, int);
	int& operator[](int);
	bool operator==(Array&);
	bool operator!=(Array&);
	Array operator=(Array&);
	void bubleSort();
	void bubleSort(Comparer);
	void bubleSort(bool*);
	void createSorted(int,int);
	int linearSearch(int);
	void shuffle();
	void shift(int);
	void removeElement(int);
	void setItem(int, int);
	int getItem(int);
	Array(int);
	Array(int, int);
	Array(Array&);
	~Array();
	inline int getLength() const;
	void enter();
	void display() const;
private:
	inline void setLength(int);
	int* array;
	int length;
};