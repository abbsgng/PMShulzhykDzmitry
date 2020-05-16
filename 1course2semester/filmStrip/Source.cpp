#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "FilmStrip.h"

using namespace std;

void initFile(char*);
void displayFile(char*);
void addToEndFile(char*);
void changeFile(char*);
void removeFromFile(char*);
void initNumber(long&);
void systemFun();
void initNameFile(char*);
void sortingFile(char*);
int menu();

int main()
{
	char fileName[N] = "C:\\Users\\ִלטענטי\\Desktop\\persoalWork\\persoalWork\\film.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int Key = menu();
		if (Key == Exit)
			return 0;
		system("cls");
		switch (Key)
		{
		case Init:
			initNameFile(fileName);
			systemFun();
			break;
		case Create:
			initFile(fileName);
			systemFun();
			break;
		case Display:
			displayFile(fileName);
			systemFun();
			break;
		case Add:
			addToEndFile(fileName);
			systemFun();
			break;
		case Change:
			changeFile(fileName);
			systemFun();
			break;
		case Remove:
			removeFromFile(fileName);
			systemFun();
			break;
		case Sort:
			sortingFile(fileName);
			systemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			systemFun();
		}
	}
}

void initFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		systemFun();
		return;
	}
	int bufSize = sizeof(FilmStrip);
	//Student* man = new Student;
	FilmStrip film;
	char ok = 'y';
	while (ok == 'y')
	{
		//man->EnterStudent();
		film.enterFilmStrip();//
		//streamOut.write((char*)man,bufSize);
		streamOut.write((char*)&film, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> ok;
	}
	//delete man;
	streamOut.close();
}

void addToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		systemFun();
		return;
	}
	int bufSize = sizeof(FilmStrip);
	FilmStrip film;
	char Ok = 'y';
	while (Ok == 'y')
	{
		film.enterFilmStrip();
		streamOut.write((char*)&film, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void changeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		systemFun();
		return;
	}
	int bufSize = sizeof(FilmStrip);
	FilmStrip film;
	long Position;
	initNumber(Position);
	streamInOut.seekp((Position - 1) * bufSize, ios::beg);
	film.enterFilmStrip();
	streamInOut.write((char*)&film, bufSize);
	streamInOut.close();
}

void removeFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		systemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);//*
	long N = streamInOut.tellp();//*
	int bufSize = sizeof(FilmStrip);
	FilmStrip film;
	long Position;
	initNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&film, bufSize))
	{
		//streamInOut.seekp( (Position - 1 + i ) * bufSize, ios::beg);
		//streamInOut.write((char*)&man, bufSize);
		//streamInOut.seekp( bufSize, ios::cur);
		//i++;
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&film, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	//int DiskriptorFile = open(fileName, 2);//*
	//chsize(DiskriptorFile, N - bufSize);//*
	//close(DiskriptorFile);//*
}

void sortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			systemFun();
			return;
		}
		flag = false;
		FilmStrip filmOne, filmTwo;
		int bufSize = sizeof(FilmStrip);
		streamInOut.read((char*)&filmOne, bufSize);
		while (streamInOut.read((char*)&filmTwo, bufSize))
		{
			if (filmTwo.getYear() < filmOne.getYear())
			{
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&filmTwo, bufSize);
				streamInOut.write((char*)&filmOne, bufSize);
				flag = true;
			}
			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&filmOne, bufSize);
		}
		streamInOut.close();
	}
}

void displayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		systemFun();
		return;
	}
	int bufSize = sizeof(FilmStrip);
	FilmStrip* film = new FilmStrip;
	while (streamIn.read((char*)film, bufSize))
	{
		film->displayFilmStrip();
	}
	streamIn.close();
}

void initNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void systemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void initNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}