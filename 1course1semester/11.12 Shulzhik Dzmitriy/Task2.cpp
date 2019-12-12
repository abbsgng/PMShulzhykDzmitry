#include <iostream>

using namespace std;

int* encoding(char const*, char const*);
char* decoding(int const*, int, char const*);
char* createRule(const char*);
void createRuleTest();
void encodingTests();
void decodingTests();
bool equals(const char*, const char*);
bool equals(const int*, int n, const int*, int m);

int getlength(const char* source);
void swap(int* a, int* b);
bool isDataValid(const int* array, int n);
bool isDataValid(const char* array, int n);
bool isAlphabet(char symbol);
int linearSearch(const char* array, int const n, char const value);
char toUpper(char symbol);
bool isLower(char symbol);

int main()
{
	createRuleTest();
	encodingTests();
	decodingTests();
	system("pause");
}

char* createRule(const char* source)
{
	int n = getlength(source);
	char* rule = new char[n + 1];
	int i = 0;
	for (int k = n - 1; k >= 0; i++, k--)
	{
		rule[i] = source[k];
	}
	rule[i] = '\0';
	return rule;
}

int* encoding(const char* source, const char* rule)
{
	int n = getlength(source);
	int* encode = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (isAlphabet(source[i]))
		{
			encode[i] = linearSearch(rule, getlength(rule), toUpper(source[i])) + 1;
		}
		else
		{
			encode[i] = source[i];
		}
	}
	return encode;
}

char* decoding(const int* source, int n, const char* rule)
{
	char* decode = new char[n];
	int t = 0, i = 0;
	for ( ; i < n; i++)
	{
		if (1 <= source[i] && source[i] <= 26)
		{
			t = source[i] - 1;
			decode[i] = rule[t];
		}
		else
		{
			decode[i] = source[i];
		}
	}
	decode[i] = '\0';
	return decode;
}

bool equals(const char* lhs, const char* rhs)
{
	int n = getlength(lhs);
	int m = getlength(rhs);
	if (!isDataValid(lhs, n) || !isDataValid(rhs, m))
	{
		cout << "Error.\n";
		return false;
	}
	if (n != m)
	{
		return false;
	}
	for (int i = 0; i < n || i < m; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
}

bool equals(const int* lhs, int n, const int* rhs, int m)
{
	if (!isDataValid(lhs, n) || !isDataValid(rhs, m))
	{
		cout << "Error.\n";
		return false;
	}
	if (n != m)
	{
		return false;
	}
	for (int i = 0; i < n || i < m; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
}

void createRuleTest()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char* actual = createRule(source);
	const char* expected = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	cout << "Test for creation rule " << (equals(actual, expected) ? "Passed." : "Failed.") << endl;
}

void encodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	int* encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode, 10, new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, 10) ? "Passed." : "Failed.") << endl;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode, 29, new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, 29) ? "Passed." : "Failed.") << endl;
}

void decodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	char* decode = decoding(new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, 10, rule);

	cout << "Test for decoding " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;

	decode = decoding(new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, 29, rule);

	cout << "Test for decoding " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;
}


int getlength(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (source[length])
	{
		length++;
	}
	return length;
}

bool isDataValid(const char* array, int n)
{
	if (array == nullptr)
	{
		return 0;
	}

	if (n <= 0)
	{
		return 0;
	}
	return true;
}

void swap(int* a, int* b)
{
	int* t = a;
	a = t;
	b = t;
}

bool isDataValid(const int* array, int n)
{
	if (array == nullptr)
	{
		return 0;
	}

	if (n <= 0)
	{
		return 0;
	}
	return true;

}

bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}

char toUpper(char symbol)
{
	if (isAlphabet(symbol) && isLower(symbol))
	{
		return symbol - 32;
	}
	return symbol;
}

bool isLower(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}

int linearSearch(const char* array, int const n, char const value)
{

	for (int i = 0; i < n; i++)
	{
		if (array[i] == value)
		{
			return i;
		}
	}

	return -1;
}



