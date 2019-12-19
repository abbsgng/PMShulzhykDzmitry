#include <iostream>

using namespace std;

int getLength(const char*);
bool isDigit(const char);
void reverseNumber(int&);
//etc
int parseStringToSumWithUnsigned(const char*);
int parseStringToSumWithSigned(const char*);
void parseStringToSumWithUnsignedTest();
void parseStringToSumWithSignedTest();
int numberOfDigits(int);


int main()
{
	parseStringToSumWithUnsignedTest();
	parseStringToSumWithSignedTest();
	system("pause");
	return 0;
}

int parseStringToSumWithUnsigned(const char* source)
{
	int counter = 0;
	int buffer = 0;
	for (int i = 0; i < getLength(source); i++)
	{
		if (isDigit(source[i]))
		{
			for (int j = i, k = 0; isDigit(source[j]); j++, k++, i++)
			{
				buffer = (buffer + (source[j] - '0')) * 10;
			}
			buffer = buffer / 10;
			counter = counter + buffer;
			buffer = 0;
		}
		else
		{
			continue;
		}
	}
	return counter;
}

int parseStringToSumWithSigned(const char* source)
{
	int counter = 0;
	int buffer = 0;
	for (int i = 0; i < getLength(source); i++)
	{
		if (isDigit(source[i]))
		{
			if(source[i-1]=='-')
			{ 
				for (int j = i, k = 0; isDigit(source[j]); j++, k++, i++)
				{
					buffer = (buffer + (source[j] - '0')) * 10;
				}
				buffer = buffer / (-10);
				counter = counter + buffer;
				buffer = 0;
			}
			else
			{
				for (int j = i, k = 0; isDigit(source[j]); j++, k++, i++)
				{
					buffer = (buffer + (source[j] - '0')) * 10;
				}
				buffer = buffer / 10;
				counter = counter + buffer;
				buffer = 0;
			}
		}
		else
		{
			continue;
		}
	}
	return counter;
}

bool isDigit(const char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void reverseNumber(int& number)
{
	int i = numberOfDigits(number);
	int sum = 0;
	for (int c = 1, a = 0; c <= i; c++)
	{
		a = number % 10;
		sum = 10 * (sum + a);
		number = number / 10;
	}
	sum = sum / 10;
	number = sum;
}

int getLength(const char* source)
{
	int length = 0;

	while (source[length])
	{
		length++;
	}

	return length;
}

void parseStringToSumWithUnsignedTest()
{
	bool result = parseStringToSumWithUnsigned("1235+-8+*** 90") == 1333;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithUnsigned("1235+-8+* 4** -22--- 9") == 1278;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithUnsigned("-----1-----145 ty 144") == 290;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithUnsigned("78ytfh-111 ghhg 3466 1 0 0") == 3656;
	cout << "Test for unsigned parsing " << (result ? "Passed." : "Failed.") << endl;

	cout << endl;

	//etc
}

void parseStringToSumWithSignedTest()
{
	bool result = parseStringToSumWithSigned("1235+-8+*** 90") == 1317;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithSigned("1235+-8+* 4** -22--- 9") == 1218;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithSigned("-4567gjhgjh hjhjj -1-1jhgyjg   15--") == -4554;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	result = parseStringToSumWithSigned("ghjjk -2378hj hhj^^ %%12 -156") == -2522;
	cout << "Test for signed parsing " << (result ? "Passed." : "Failed.") << endl;

	//etc
}

int numberOfDigits(int n)
{
	int i = 0;
	while (n != 0)
	{
		n = n / 10;
		i = i + 1;
	}
	return i;
}