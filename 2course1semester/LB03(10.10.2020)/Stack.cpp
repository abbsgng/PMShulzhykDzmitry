#include "Stack.h"
#include <iostream>
#include <fstream>

using namespace std;

Stack::Stack(const Stack& stack)
{
	*this = stack;
}

bool Stack::isEmpty() const
{
	return !top;
}

void Stack::push(double item)
{
	Node* node = new Node(item);
	node->next = top;
	top = node;
}

double Stack::pop()
{
	Node* node = top;
	double buffer = top->item;
	top = top->next;
	delete node;
	return buffer;
}

int Stack::size() const
{
	int size = 0;
	Node* current = top;
	while (current)
	{
		current = current->next;
		size++;
	}
	return size;
}

void Stack::clear()
{
	while (top)
	{
		Node* node = top;
		top = top->next;
		delete node;
	}
}

double Stack::operator-()
{
	return pop();
}

Stack Stack::operator+(double item)
{
	push(item);
	return *this;
}

Stack& Stack::operator=(const Stack& stack)
{
	if (!stack.top)
	{
		top = nullptr;
		return *this;
	}
	top = new Node(stack.top->item);
	Node* buffer1, * buffer2;
	buffer1 = top;
	buffer2 = stack.top->next;
	while (buffer2)
	{
		buffer1->next = new Node(buffer2->item);
		buffer1 = buffer1->next;
		buffer2 = buffer2->next;
	}
	return *this;
}

Stack::~Stack()
{
	clear();
	delete top;
}

