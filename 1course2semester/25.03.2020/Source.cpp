#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

const int N = 48;

void deleteSubString(char*, short);
void cleanString(char*);
bool isAlphabet(char);
char* fromFile(char*, char*);
void toFile(char*, char*, short);

int main()
{
	char* temp = new char[256];
	char path[N] = "C:\\Users\\Термокаскад\\Desktop\\turks.txt";
	temp = fromFile(path, temp);
	toFile(path, temp, 2);
	delete[] temp;
}

void deleteSubString(char* source, short size)
{
	int n = strlen(source);
	char* temp = new char[n + 1];
	char* buffer = new char[n / 3];
	cleanString(temp);
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		cleanString(buffer);

		int k = 0;
		for (; isAlphabet(source[i]); ++i, ++k)
		{
			buffer[k] = source[i];
		}
		buffer[k] = '\0';
		k = 0;
		if (strlen(buffer) != size)
		{
			while (buffer[k])
			{
				temp[j] = buffer[k];
				k++;
				j++;
			}
		}
		temp[j++] = source[i];
	}
	temp[j] = '\0';
	strcpy(source, temp);
	delete[] temp, buffer;
}
void cleanString(char* source)
{
	for (int i = 0; i < strlen(source);++i)
	{
		source[i] = '\0';
	}
}
bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}
char* fromFile(char* path, char* temp)
{
	ifstream from(path);
	if (!from.is_open())
	{
		throw std::invalid_argument("File is not open.");
	}
	while (!from.eof())
	{
		from.getline(temp, 256, '\0');
	}

	from.close();
	return temp;
}
void toFile(char* path, char* temp, short deleteSize)
{
	deleteSubString(temp, deleteSize);
	short n = strlen(temp) + 1;
	ofstream to(path);
	if (!to.is_open())
	{
		throw std::invalid_argument("File is not open.");
	}
	to << temp;
	to.close();
}