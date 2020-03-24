#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include <iostream>

using namespace std;

char* createString(char symbol, int length)
{
	char* source = new char[length + 1];
	int i = 0;
	for (; i < length; ++i)
	{
		source[i] = symbol;
	}
	source[i] = '\0';
	return source;
}

Table::Table(int rows, int columns, int* columnsSize)
{
	setTable(columns, rows, columnsSize);
}
Table::Table()
{
	rows = 2;
	columns = 2;
	columnsSizes = new int[columns];
	for (int i = 0; i < columns; ++i)
	{
		columnsSizes[i] = 2;
	}
}
Table::~Table()
{
	delete[] columnsSizes;
}
void Table::setTable(int columns, int rows, int* sizes)
{
	if (columns < 0)
	{
		throw std::invalid_argument("");
	}
	if (sizes == nullptr)
	{
		throw std::invalid_argument("");
	}
	if (calculate(columns, sizes) > maxWidth)
	{
		throw std::invalid_argument("Error");
	}
	this->columns = columns;
	this->columnsSizes = new int[columns];
	for (int i = 0; i < columns; ++i)
	{
		this->columnsSizes[i] = sizes[i];
	}
	if (rows < 0)
	{
		throw std::invalid_argument("hj");
	}
	this->rows = 2 * rows;
	delete[] sizes;
}
inline int Table::getColumns() const
{
	return columns;
}
inline int Table::getRows() const
{
	return rows;
}

int Table::calculate(int columns, int* columnsSize)
{
	int result = 0;
	for (int i = 0; i < columns; ++i)
	{
		result += columnsSize[i];
	}
	return result;
}
void Table::create(char** table)
{
	int size = 0;
	int n = getRows() + 1;
	int m = getColumns();
	for (int i = 0; i < n; ++i)
	{
		size = calculate(m, columnsSizes) + m + 1;
		table[i] = new char[size];
		for (int j = 0; j < size; ++j)
		{
			table[i][j] = '\0';
		}
	}
	createOpenLine(table[0], m, columnsSizes);
	int i = 1;
	for (; i < n - 1; ++i)
	{
		if (i % 2 == 0)
		{
			createSeparatorLine(table[i], m, columnsSizes);
		}
		else
		{
			createEmptyLine(table[i], m, columnsSizes);
		}
	}
	createCloseLine(table[n - 1], m, columnsSizes);
}
void Table::createOpenLine(char* line, int m, int* columnsSizes) // превратить в статик, передавать массив вместо строки
{
	strcat(line, "\xc9");
	for (int i = 0; i < m - 1; ++i)
	{
		strcat(line, createString('\xcd', columnsSizes[i]));
		strcat(line, "\xcb");
	}
	strcat(line, createString('\xcd', columnsSizes[m - 1]));
	strcat(line, "\xbb");
}
void Table::createEmptyLine(char* line, int m, int* columnsSizes)
{
	strcat(line, "\xba");
	for (int i = 0; i < m; ++i)
	{
		strcat(line, createString(' ', columnsSizes[i]));
		strcat(line, "\xba");
	}
}
void Table::createSeparatorLine(char* line, int m, int* columnsSizes)
{
	strcat(line, "\xcc");
	for (int i = 0; i < m - 1; ++i)
	{
		strcat(line, createString('\xcd', columnsSizes[i]));
		strcat(line, "\xce");
	}
	strcat(line, createString('\xcd', columnsSizes[m - 1]));
	strcat(line, "\xb9");
}
void Table::createCloseLine(char* line, int m, int* columnsSizes)
{
	strcat(line, "\xc8");
	for (int i = 0; i < m - 1; ++i)
	{
		strcat(line, createString('\xcd', columnsSizes[i]));
		strcat(line, "\xca");
	}
	strcat(line, createString('\xcd', columnsSizes[m - 1]));
	strcat(line, "\xbc");
}
void Table::display()
{
	int n = getRows() + 1;
	char** table = new char* [n];
	create(table);
	for (int i = 0; i < n; ++i)
	{
		cout << table[i] << endl;
	}
	/*for (int i = 0; i < n; ++i)
	{
		delete[] table[i];
	}
	delete[] table;*/
}