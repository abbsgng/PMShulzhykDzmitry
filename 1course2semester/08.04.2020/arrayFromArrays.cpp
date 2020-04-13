#include <iostream>
#include <fstream>


using namespace std;

void merge(char*, char*, char*);

int main()
{
	char fileFirst[50] = "C:\\Users\\Термокаскад\\Desktop\\array1.txt";
	char fileSecond[50] = "C:\\Users\\Термокаскад\\Desktop\\array2.txt";
	char fileThird[50] = "C:\\Users\\Термокаскад\\Desktop\\array3.txt";

	merge(fileFirst, fileSecond, fileThird);

	return 0;
}

void merge(char* fileFirst, char* fileSecond, char* fileThird)
{
	ifstream in1(fileFirst);
	ifstream in2(fileSecond);
	ofstream out(fileThird);

	if (!in1.is_open())
	{
		throw std::invalid_argument("Error.");
	}
	if (!in2.is_open())
	{
		throw std::invalid_argument("Error.");
	}
	if (!out.is_open())
	{
		throw std::invalid_argument("Error.");
	}

	int buffer1 = 0;
	int buffer2 = 0;
	in1 >> buffer1;
	in2 >> buffer2;
	while (in1 && in2)
	{
		if (buffer1 > buffer2)
		{
			out << buffer2 << ' ';
			in2 >> buffer2;
		}
		else
		{
			out << buffer1 << ' ';
			in1 >> buffer1;
		}
	}
	if (in1)
	{
		while (in1)
		{	
			out << buffer1 << ' ';
			in1 >> buffer1;
		}
	}
	else
	{
		while (in2)
		{
			out << buffer2 << ' ';
			in2 >> buffer2;
		}
	}
	in1.close();
	in2.close();
	out.close();
}