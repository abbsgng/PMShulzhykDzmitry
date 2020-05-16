#define _CRT_SECURE_NO_WARNINGS
#include "FilmStrip.h"
#include <iostream>
#include <cstring>

using namespace std;

FilmStrip::FilmStrip(char* name, char* producerName, char* producerSurname, char* country, int year, int cost, int income)
{
	this->setFilmStrip(name, producerName, producerSurname, country, year, income, cost);
}

void FilmStrip::setName(char* name)
{
	strcpy(this->name, name);
}

void FilmStrip::setProducerName(char* producerName)
{
	strcpy(this->producerName, producerName);
}

void FilmStrip::setProducerSurname(char* producerSurname)
{
	strcpy(this->producerSurname, producerSurname);
}

void FilmStrip::setCountry(char* country)
{
	strcpy(this->country, country);
}

void FilmStrip::setYear(int year)
{
	this->year = year;
}

void FilmStrip::setCost(int cost)
{
	this->cost = cost;
}

void FilmStrip::setIncome(int income)
{
	this->income = income;
}

char* FilmStrip::getName()
{
	return this->name;
}

char* FilmStrip::getProducerName()
{
	return this->producerName;
}

char* FilmStrip::getProducerSurname()
{
	return this->producerSurname;
}

char* FilmStrip::getCountry()
{
	return this->country;
}

int FilmStrip::getYear()
{
	return this->year;
}

int FilmStrip::getCost()
{
	return this->cost;
}

int FilmStrip::getIncome()
{
	return this->income;
}

void FilmStrip::setFilmStrip(char* name, char* producerName, char* producerSurname, char* country, int year, int cost, int income)
{
	this->setName(name);
	this->setProducerName(producerName);
	this->setProducerSurname(producerSurname);
	this->setCountry(country);
	this->setYear(year);
	this->setCost(cost);
	this->setIncome(income);
}

void FilmStrip::displayFilmStrip()
{
	cout << "Name film strip: " << name << endl;
	cout << "Producer name: " << producerName << endl;
	cout << "Producer surname: " << producerSurname << endl;
	cout << "Country: " << country << endl;
	cout << "Year: " << year << endl;
	cout << "Cost: " << cost << endl;
	cout << "Income: " << income << endl;
}

void FilmStrip::enterFilmStrip()
{
	const int N = 256;
	char name[N] = "", producerName[N] = "", producerSurname[N] = "", country[N] = "";
	int year = 0, cost = 0, income = 0;

	cout << "Enter film strip name:";
	cin.ignore();
	cin.getline(name, N, '\n');

	cout << "Enter producer name:";
	cin.getline(producerName, N, '\n');

	cout << "Enter producer surname:";
	cin.getline(producerSurname, N, '\n');

	cout << "Enter country:";
	cin.getline(country, N, '\n');

	cout << "Enter year:" << endl;
	cin >> year;

	cout << "Enter cost:" << endl;
	cin >> cost;

	cout << "Enter income" << endl;
	cin >> income;

	this->setFilmStrip(name, producerName, producerSurname, country, year, cost, income);
}