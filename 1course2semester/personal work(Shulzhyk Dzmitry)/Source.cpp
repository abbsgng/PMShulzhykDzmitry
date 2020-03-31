#include <iostream>
#include <fstream>

using namespace std;


typedef bool(*filter)(int, char);


void enterArray(int*, int);
void initArray(int*, int);
void displayArray(int*, int);
void swap(int*, int*);
void deleteReplayElement(int*, int&);
int firstDigit(int);
int* createRule(int*, int);
void quickSort(int*, int*, int);
bool haveElement(int, char);
void filterArray(int*, int&, char, filter);
void inFile(char*, int*, int);
void fromFile(char*, int*, int);
void outArray(char*, int*, int);
void menu(char*);



int main()
{
	char path[64] = "C:\\Users\\Термокаскад\\Desktop\\personalWork.txt";
	menu(path);
}

void menu(char* path)
{
	int size = -1;
	cout << "Enter the size of array." << endl;
	while (size < 0)
	{
		cin >> size;
	}
	int* array = new int[size];
	enum cases { makeArray = 1, randomArray = 2, File = 3, exit = 4 };
	while (true)
	{
		cout << "Press 1 to enter array.\n";
		cout << "Press 2 to make random array.\n";
		cout << "Press 3 to get array from file.\n";
		cout << "Press 4 to exit.\n";
		int n;
		cin >> n;
		system("cls");

		switch (n)
		{
		case makeArray:
			enterArray(array, size);
			outArray(path, array, size);
			break;
		case randomArray:
			initArray(array, size);
			outArray(path, array, size);
			break;
		case File:
			fromFile(path, array, size);
			outArray(path, array, size);
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

void enterArray(int* array, int size)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Error");
	}
	if (size <= 0)
	{
		throw std::invalid_argument("Size of array must be more than 0.");
	}
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "]:";
		cin >> array[i];
	}
}

void initArray(int* array, int size)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Error");
	}
	if (size <= 0)
	{
		throw std::invalid_argument("Size of array must be more than 0.");
	}
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % (10 * size + i);
	}
}

void displayArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << array[i] << " ";
	}
}

void swap(int* lhs, int* rhs)
{
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

void deleteReplayElement(int* array, int& size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (array[i] == array[j])
			{
				for (int k = j; k < size - 1; ++k)
				{
					array[k] = array[k + 1];
				}
				i = 0;
				j = 0;
				size--;
			}
		}
	}
}

int firstDigit(int number)
{
	int digit = 0;
	while (number / 16)
	{
		number /= 16;
	}
	digit = number % 16;
	return digit;
}

int* createRule(int* array, int size)
{
	int* rule = new int[size];
	for (int i = 0; i < size; ++i)
	{
		rule[i] = firstDigit(array[i]);
	}
	return rule;
}

void quickSort(int* array, int* rule, int size)
{
	int i = 0;
	int j = size - 1;
	int mid = rule[size / 2];

	do
	{
		while (rule[i] > mid)
		{
			i++;
		}

		while (rule[j] < mid)
		{
			j--;
		}

		if (i <= j)
		{
			swap(rule[i], rule[j]);
			swap(array[i], array[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		quickSort(array, rule, j + 1);
	}
	if (i < size)
	{
		quickSort(&array[i], &rule[i], size - i);
	}
}

bool haveElement(int number, char element)
{
	while (number / 16)
	{
		if (number % 16 == element - 55)
		{
			return true;
		}
		number /= 16;
	}
	if (number % 16 == element - 55)
	{
		return true;
	}
	return false;
}

void filterArray(int* array, int& size, char element, filter filter)
{
	for (int i = 0; i < size; i++)
	{
		if (filter(array[i], element))
		{
			for (int j = i; j < size - 1; ++j)
			{
				array[j] = array[j + 1];
			}
			i = -1;
			size--;
		}
	}
}

void inFile(char* path, int* array, int size)
{
	ofstream to(path);
	if (!to.is_open())
	{
		throw std::invalid_argument("File is not open");
	}
	for (int i = 0; i < size; ++i)
	{
		to << array[i] << " ";
	}
	to.close();
}

void fromFile(char* path, int* array, int size)
{
	int temp;
	ifstream from(path);
	if (!from.is_open())
	{
		throw std::invalid_argument("File is not open");
	}
	int i = 0;
	while (!from.eof() && i < size)
	{
		from >> temp;
		array[i++] = temp;
	}
	from.close();
}

void outArray(char* path, int* array, int size)
{
	int* rule = new int[size];
	rule = createRule(array, size);
	enum cases { console = 1, toFile = 2, exit = 3 };
	while (true)
	{
		cout << "Enter the element from A to F." << endl;
		char element = ' ';
		while (element < 'A' || element > 'F')
		{
			cin >> element;
		}
		system("pause");
		system("cls");
		cout << "Press 1 to display on console.\n";
		cout << "Press 2 to make file.\n";
		cout << "Press 3 to exit.\n";
		int n;
		cin >> n;
		system("cls");

		switch (n)
		{
		case console:
			displayArray(array, size);
			deleteReplayElement(array, size);
			quickSort(array, rule, size);
			filterArray(array, size, element, haveElement);
			cout << endl;
			displayArray(array, size);
			system("pause");
			system("cls");
			break;
		case toFile:
			displayArray(array, size);
			deleteReplayElement(array, size);
			quickSort(array, rule, size);
			filterArray(array, size, element, haveElement);
			inFile(path, array, size);
			break;
		case exit:
			return;
		default:
			cout << "Invalid operation. Try again.\n";
			system("pause");
			system("cls");
		}
	}
	delete[] rule, array;
}