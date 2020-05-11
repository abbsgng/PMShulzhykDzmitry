#include "LinkedList.h" 

LinkedList::LinkedList(int* values, int n) : head(nullptr)
{
	if (!values)
	{
		throw std::invalid_argument("Array doesn't exist.");
	}
	for (int i = n - 1; i >= 0; --i)
	{
		addFirst(values[i]);
	}
}

LinkedList::LinkedList(const LinkedList& list) : head(nullptr)
{
	int size = list.size();
	int* array = list.copyToArray(size);
	for (int i = size - 1; i >= 0; --i)
	{
		addFirst(array[i]);
	}
	delete[] array;
}

LinkedList::~LinkedList()
{
	clear();
}

bool LinkedList::isEmpty() const
{
	return !head;
}

bool LinkedList::haveElement(int value) const
{
	Node* current = head;
	while (current)
	{
		if (current->item == value)
		{
			return true;
		}
		else
		{
			current = current->next;
		}
	}
	return false;
}

int LinkedList::size() const
{
	int size = 0;
	Node* current = head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return size;
}

void LinkedList::addFirst(int value)
{
	Node* node = new Node(value);
	if (isEmpty())
	{
		head = node;
		return;
	}
	node->next = head;
	head = node;
}

void LinkedList::addBeforeItem(int tag, int value)
{
	if (isEmpty())
	{
		return;
	}
	Node* current = head,
		* previous = current;
	while (current)
	{
		if (current->item == tag)
		{
			if (current == head)
			{
				addFirst(value);
			}
			else
			{
				Node* node = new Node(value);
				previous->next = node;
				node->next = current;
			}
			return;
		}
		previous = current;
		current = current->next;
	}
}

void LinkedList::addAfterItem(int tag, int value)
{
	if (isEmpty())
	{
		return;
	}
	Node* current = head;
	while (current)
	{
		if (current->item == tag)
		{
			Node* node = new Node(value);
			node->next = current->next;
			current->next = node;
			return;
		}
		current = current->next;
	}
}

void LinkedList::addLast(int value)
{
	Node* current = head,
		* previous = current;
	while (current)
	{
		previous = current;
		current = current->next;
	}
	Node* node = new Node(value);
	previous->next = node;
}

void LinkedList::removeElement(int value)
{
	if (isEmpty() && !haveElement(value))
	{
		return;
	}
	Node* current = head, * previous = head, * buffer = nullptr;
	while (head->item == value)
	{
		previous = head;
		head = head->next;
		if (!head)
		{
			return;
		}
		delete previous;
	}
	previous = head,
		current = previous->next;
	while (current)
	{
		if (current->item == value)
		{
			buffer = current;
			current = current->next;
			delete buffer;
			previous->next = current;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}

void LinkedList::clear()
{
	Node* current = head;
	while (current)
	{
		head = current->next;
		delete current;
		current = head;
	}
}

int* LinkedList::copyToArray(int size) const
{
	int* array = new int[size] {0};
	Node* current = head;
	for (int i = 0; i < size; ++i)
	{
		if (!current)
		{
			return array;
		}
		array[i] = current->item;
		current = current->next;
	}
	return array;
}

std::ostream& operator<<(ostream& stream, const LinkedList& list)
{
	LinkedList::Node* current = list.head;
	while (current)
	{
		stream << *current;
		current = current->next;
	}

	stream << endl;
	return stream;
}
