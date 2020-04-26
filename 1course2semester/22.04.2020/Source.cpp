#include <iostream>
#include <fstream>

using namespace std;

void writeInBin(ofstream&, int);
void displayBin(ifstream&);
void sortInBin(const char*);

int main()
{
	const char path[] = "test.bin";

	ofstream out(path, ios::binary);
	writeInBin(out, 10);
	out.close();

	sortInBin(path);

	ifstream in(path, ios::binary);
	displayBin(in);
	in.close();

	return 0;
}

void writeInBin(ofstream& out, int size)
{
	int typeSize = sizeof(int);

	for (int i = 0; i < size; ++i)
	{
		int buffer = rand()%1000;
		out.write((char*)&buffer, typeSize);
	}
}

void displayBin(ifstream& in)
{
	int buffer;
	int typeSize = sizeof(int);

	while (in.read((char*)&buffer, typeSize))
	{
		cout << buffer << '\t';
	}
}

void sortInBin(const char* path)
{
	bool isSorted = false;
	int typeSize = sizeof(int);
	int left = 0, right = 0, position = 0;
	
	while (!isSorted)
	{
		fstream stream(path, ios::binary | ios::out | ios::in);
		isSorted = true;
		stream.read((char*)&left, typeSize);
		while (stream.read((char*)&right, typeSize))
		{
			if (left > right)
			{
				stream.seekp(-2 * typeSize, ios::cur);
				stream.write((char*)&right, typeSize);
				stream.write((char*)&left, typeSize);
				isSorted = false;
			}
			stream.seekp(-1 * typeSize, ios::cur);
			stream.read((char*)&left, typeSize);
		}
		stream.close();
	}
}