#pragma once
#include <iostream>
#include <fstream>
class Stack
{
public:
	Stack() :top(nullptr) { }
	Stack(const Stack&);
	bool isEmpty() const;
	void push(double);
	double pop();
	int size() const;
	void clear();

	double operator-();
	Stack operator+(double);
	Stack& operator=(const Stack&);

	~Stack();
private:
	struct Node
	{
		Node() :item(0), next(nullptr) { }
		Node(double value) :item(value), next(nullptr) { }
		friend std::ostream& operator<<(std::ostream& stream, const Node& node)
		{
			stream << node.item;
			return stream;
		}
		double item;
		Node* next;
	};
	Node* top;
};

