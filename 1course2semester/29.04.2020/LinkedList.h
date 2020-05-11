#pragma once
#include <iostream>
#include <ostream>

using namespace std;

class LinkedList
{
public:
	LinkedList() : head(nullptr) {}
	LinkedList(int*, int);
	LinkedList(const LinkedList&);
	~LinkedList();
	
	bool haveElement(int) const;
	int size() const;
	void addFirst(int);
	void addBeforeItem(int, int);
	void addAfterItem(int, int);
	void addLast(int);
	void removeElement(int);
	void clear();
	int* copyToArray(int) const;

	friend std::ostream& operator << (ostream&, const LinkedList&);
private:
	inline bool isEmpty() const;

	struct Node
	{
		Node() : next(nullptr) { }
		Node(int value) : item(value), next(nullptr) { }
		friend std::ostream& operator << (ostream& stream, const Node& node)
		{
			stream << node.item << "->";
			return stream;
		}

		int item{ 0 };
		Node* next;

	};
	Node* head;
};

