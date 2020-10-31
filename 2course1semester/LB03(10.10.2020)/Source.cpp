#include <iostream>
#include "Stack.h"

using namespace std;

void enterStack(Stack&);
void task(Stack&);
double* stackToArray(Stack&, int&);
void task();

int main()
{
	//Stack stack;
	//enterStack(stack);
	task();
}

void enterStack(Stack& stack)
{
	char ok = 'f';
	double item;
	while (ok == 'f')
	{
		cout << "Enter the item:";
		cin >> item;
		stack.push(item);
		cout << "Press f to continue" << endl;
		cin >> ok;
		system("cls");
	}
}

double* stackToArray(Stack& stack, int& size)
{
	size = stack.size();
	double* array = new double[size] {0};

	for (int i = size - 1; i >= 0; --i)
	{
		array[i] = stack.pop();
	}
	return array;
}

void task()
{
	int size = 0, buffer = 0;
	Stack stack1, stack2;
	double array[17] = { 1,1,1,2,2,2,7,6,5,4,4,4,1,2,3,3,3 };
	for (int i = 0; i < 16; ++i)
	{
		int j = i;
		if (array[j + 1] <= array[j])
		{
			stack1.push(array[j]);
			buffer = stack1.pop();
			cout << buffer << "   ";
			stack2.push(buffer);
			cout << stack2.pop() << "   ";
			stack1.clear();
			stack2.clear();
			i = j;
			cout << endl;
			continue;
		}
		while (array[j + 1] > array[j])
		{
			stack1.push(array[j]);
			j++;
		}
		if (!stack1.isEmpty())
		{
			stack1.push(array[j]);
		}
		while (!stack1.isEmpty())
		{
			buffer = stack1.pop();
			cout << buffer << "   ";
			stack2.push(buffer);
		}
		cout << endl;
		while (!stack2.isEmpty())
		{
			cout << stack2.pop() << "   ";
		}
		stack1.clear();
		stack2.clear();
		i = j;
		cout << "\n" << endl;
	}

	//delete[] array;
}

