#pragma once
#include <iostream>

using namespace std;

class Table
{
public:
	Table();
	Table(int, int, int*);
	~Table();
	void setTable(int, int, int*);
	inline int getRows() const;
	inline int getColumns() const;
	void display();
private:
	int columns;
	int rows;
	int* columnsSizes;
	const int maxWidth = 200;
	static int calculate(int, int*);
	void create(char**);
	static void createOpenLine(char*, int, int*);
	static void createEmptyLine(char*, int, int*);
	static void createSeparatorLine(char*, int, int*);
	static void createCloseLine(char*, int, int*);
};
