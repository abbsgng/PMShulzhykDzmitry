#include <iostream>
#include <fstream>

using namespace std;

#pragma region MyFunction
void workWithFile(char*);
int sizeMatrix(char*);
int** bornMatrix(int);
int** generateMatrix(int);
int** matrixFromFile(char*, int);
int findMax(int**, int, int, int);
int** makeNewMatrix(int**, int);
void outMatrix(int**, int, ostream&);
void matrixToFile(int**, int, char*);
void deleteMemory(int**, int);
#pragma endregion

int main()
{
	char path[64] = "C:\\Users\\Термокаскад\\Desktop\\matrix.txt";
	workWithFile(path);
}

void workWithFile(char* path)
{
	int size = sizeMatrix(path);

	int** matrix = matrixFromFile(path, size);

	int** newMatrix = makeNewMatrix(matrix, size);

	matrixToFile(newMatrix, size, path);

	deleteMemory(newMatrix, size);
}

int sizeMatrix(char* path)
{
	int size = 0, temp;

	ifstream from(path);

	if (!from.is_open())
	{
		throw std::invalid_argument("Error");
	}

	while (!from.eof())
	{
		from >> temp;
		size++;
	}

	from.close();

	return sqrt(size);
}

int** bornMatrix(int size)
{
	int** matrix = new int* [size];

	for (int i = 0; i < size; ++i)
	{
		matrix[i] = new int[size];
	}

	return matrix;
}

int** generateMatrix(int size)
{
	int** matrix = bornMatrix(size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = rand() % 20;
		}
	}

	return matrix;
}

int** matrixFromFile(char* path, int size)
{
	int** matrix = bornMatrix(size);

	ifstream from(path);

	if (!from.is_open())
	{
		throw std::invalid_argument("Error");
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			from >> matrix[i][j];
		}
	}

	from.close();

	return matrix;
}

void outMatrix(int** matrix, int size, ostream& out)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			out.width(9);
			out << matrix[i][j];
		}
		out << endl;
	}
}

int findMax(int** matrix, int size, int i, int j)
{
	int max = matrix[i][j], jmax = j;

	for (int i1 = i; i1 >= 0; --i1)
	{
		for (int j1 = j; j1 >= 0 && j1 <= jmax; j1++)
		{
			if (max < matrix[i1][j1])
			{
				max = matrix[i1][j1];
			}
		}
		if (j > 0)
		{
			j--;
		}
		if (jmax < size)
		{
			jmax++;
		}
	}

	return max;
}

int** makeNewMatrix(int** matrix, int size)
{
	int** newMatrix = bornMatrix(size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			newMatrix[i][j] = findMax(matrix, size, i, j);
		}
	}

	deleteMemory(matrix, size);

	return newMatrix;
}

void matrixToFile(int** matrix, int size, char* path)
{
	ofstream out;
	out.open(path, ios_base::app);

	out << endl << "new matrix" << endl;
	outMatrix(matrix, size, out);

	out.close();
}

void deleteMemory(int** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}
