#include <iostream>
#include "Array.h"

using namespace std;

#pragma region classArray
int& Array::operator[](const int index)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range("Wrong index");
	}
	return array[index];
}
bool Array::operator==(Array& array)
{
	if (getLength() != array.getLength())
	{
		return false;
	}
	for (int i = 0; i < getLength(); ++i)
	{
		if (this->array[i] == array[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool Array::operator!=(Array& array)
{
	return !(*this == array);
}
Array Array::operator=(Array& array)
{
	if (getLength() != array.getLength())
	{
		throw std::out_of_range("Array are not equal");
	}
	for (int i = 0; i < getLength(); ++i)
	{
		this->array[i] = array[i];
	}
	return *this;
}
Array ::~Array()
{
	delete[] array;
	setLength(0);
}
Array::Array(int length)
{
	setLength(length);
	int n = getLength();
	array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = 0;
	}
}
Array::Array(int length, int range)
{
	setLength(length);
	int n = getLength();
	array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = rand() % range;
	}
}
Array::Array(Array& other)
{
	this->setLength(other.getLength());
	array = new int[other.getLength()];
	for (int i = 0; i < other.getLength(); ++i)
	{
		array[i] = other[i];
	}
}
int Array::getItem(int index)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range("Wrong index");
	}
	return array[index];
}
void Array::setItem(int index, int value)
{
	if (index < 0 || index >= getLength())
	{
		throw std::out_of_range("Wrong index");
	}
	array[index] = value;
}
int Array::getLength() const
{
	return length;
}
void Array::setLength(int length)
{
	if (length < 0)
	{
		throw std::invalid_argument("Length can't be smaller than zero.");
	}
	this->length = length;
}
void Array::enter()
{
	for (int i = 0; i < getLength(); ++i)
	{
		cout << "array[" << i << "]:";
		cin >> array[i];
	}
}
void Array::display() const
{
	for (int i = 0; i < getLength(); ++i)  //
	{
		cout << array[i] << " ";
	}
}
void Array::bubleSort()
{
	for (int i = 0; i < getLength(); ++i)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			if (array[j] > array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
		}
	}
}
void Array::bubleSort(Comparer comparer)
{
	for (int i = 0; i < getLength(); ++i)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			if (comparer(array[j], array[j - 1]) > 0)
			{
				swap(array[j], array[j - 1]);
			}
		}
	}
}
void Array::bubleSort(bool* keys)
{
	for (int i = 0; i < getLength(); ++i)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			if (keys[j] < keys[j - 1])
			{
				swap(keys[j], keys[j - 1]);
				swap(array[j], array[j - 1]);
			}
		}
	}
}
void Array::createSorted(int start, int step)
{
	for (int i = 0; i < getLength(); i++)
	{
		array[i] = start;
		start += step;
	}
}
int Array::linearSearch(int number)
{
	for (int i = 0; i < getLength(); i++)
	{
		if (array[i] == number)
		{
			return i;
		}
	}
	return -1;
}
void Array::shuffle()
{
	for (int i = 0; i < getLength(); i++)
	{
		int j = rand() % getLength();
		swap(array[i], array[j]);
	}
}
void Array::shift(int shift)
{
	if (shift >= getLength())
	{
		shift -= getLength();
	}
	int* array = new int[getLength()];
	int i = 0;
	for (int j = shift; j < getLength(); i++, j++)
	{
		array[i] = this->array[j];
	}
	for (int j = 0; i < getLength(); i++, j++)
	{
		array[i] = this->array[j];
	}
	for (int i = 0; i < getLength(); ++i)
	{
		this->array[i] = array[i];
	}
}
void Array::removeElement(int position)
{
	if (position < 0 || position > getLength())
	{
		throw std::out_of_range("Position  of array must be more than  zero and less then!");
	}

	for (int i = position - 1; i < getLength() - 1; i++)
	{
		array[i] = array[i + 1];
	}
	setLength(getLength() - 1);
}
#pragma endregion

#pragma region Function
void menu();
void workWithConsole();
void runTest();
void testing(int);
int comparer(int, int);
bool* createKeys(Array);
bool isEven(int);
#pragma endregion




int main()
{
	menu();
}


void menu()
{
	enum cases { console = 1, test = 2, exit = 3 };
	while (true)
	{
		cout << "Press 1 to work with console.\n";
		cout << "Press 2 to start test.\n";
		cout << "Press 3 to exit.\n";
		int n;
		cin >> n;
		system("cls");

		switch (n)
		{
		case console:
			workWithConsole();
			break;
		case test:
			runTest();
			break;
		case exit:
			return;
		default:
			cout << "Invalid operation. Try again.\n";
			system("pause");
			system("cls");
		}
	}

}
void workWithConsole()
{
	cout << "Enter the length of array." << endl;
	int length = -1;
	while (length < 0)
	{
		cin >> length;
	}
	Array array(length);
	bool way;
	cout << "Press 0 to make sorted array." << endl;
	cout << "Press 1 to enter array." << endl;
	cin >> way;
	system("cls");
	if (way)
	{
		array.enter();
	}
	if (!way)
	{
		int start, step;
		cout << "Enter start and step." << endl;
		cin >> start >> step;
		array.createSorted(start, step);
		array.display();
	}
	system("cls");
	int n;
	enum action { bubleSort = 1, keyBubleSort, linearSearch, removeElement, shift, shuffle };
	while (true)
	{
		cout << "Enter the action" << endl;
		cout << "Press 1 to use bubleSort." << endl;
		cout << "Press 2 to use keyBubleSort." << endl;
		cout << "Press 3 to use linear search." << endl;
		cout << "Press 4 to use removeElement." << endl;
		cout << "Press 5 to use shift." << endl;
		cout << "Press 6 to use shuffle." << endl;
		cout << "Press any button to exit." << endl;
		cin >> n;
		system("cls");
		switch (n)
		{
		case bubleSort:
			array.bubleSort(comparer);
			array.display();
			cout << endl;
			break;
		case keyBubleSort:
			array.bubleSort(createKeys(array));
			array.display();
			cout << endl;
			break;
		case linearSearch:
			int element;
			cout << "Enter the element." << endl;
			cin >> element;
			cout << array.linearSearch(element) << endl;
			break;
		case removeElement:
			int position;
			cout << "Enter the position." << endl;
			cin >> position;
			array.removeElement(position);
			array.display();
			cout << endl;
			break;
		case shift:
			int shift;
			cout << "Enter the position." << endl;
			cin >> shift;
			array.shift(shift);
			array.display();
			cout << endl;
			break;
		case shuffle:
			array.shuffle();
			array.display();
			cout << endl;
			break;
		default:
			system("cls");
			return;
		}

	}

}
void runTest()
{
	testing(1);
	testing(2);
	testing(3);
	testing(4);
	testing(5);
}
void testing(int number)
{
	Array lhsArray(number * 15);
	Array rhsArray(number * 15);
	lhsArray.createSorted(10 % number, 10 + number);
	rhsArray.createSorted(10 % number, 10 + number);
	rhsArray.shuffle();
	rhsArray.bubleSort(comparer);
	if (lhsArray == rhsArray)
	{
		cout << "Test #" << number << " is correct." << endl;
	}
	else
	{
		cout << "Test #" << number << " isn't correct." << endl;
	}

}
bool* createKeys(Array array)
{
	bool* keys = new bool[array.getLength()];
	for (int i = 0; i < array.getLength(); ++i)
	{
		keys[i] = isEven(array[i]);
	}
	return keys;
}
int comparer(int lhs, int rhs)
{
	return rhs - lhs;
}
bool isEven(int number)
{
	return number % 2 == 0 ? 1 : 0;
}