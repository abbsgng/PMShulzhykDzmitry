#define _CRT_SECURE_NO_WARNINGS
#pragma once

const int N = 256;

class FilmStrip
{
public:
	FilmStrip() {}
	FilmStrip(char*, char*, char*, char*, int, int, int);
	~FilmStrip() {}
	void setName(char*);
	void setProducerName(char*);
	void setProducerSurname(char*);
	void setCountry(char*);
	void setYear(int);
	void setCost(int);
	void setIncome(int);
	void setFilmStrip(char*, char*, char*, char*, int, int, int);
	char* getName();
	char* getProducerName();
	char* getProducerSurname();
	char* getCountry();
	int getYear();
	int getCost();
	int getIncome();
	void enterFilmStrip();
	void displayFilmStrip();
private:
	char name[N], 
		producerName[N],
		producerSurname[N], 
		country[N];
	int year,
		cost,
		income;
};

