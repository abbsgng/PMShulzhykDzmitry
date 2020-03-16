#pragma once
#include <iostream>

using namespace std;

int const N = 20;

enum Gender { male = 1, female = 0 };

struct Date
{
public:
	Date& operator=(const Date& date)
	{
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
		return *this;
	}
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void display();
	Date enterDate();
	Date();
	Date(int year, int month, int day);
private:
	void dayValidation();
	static bool isYearLeap(int year);
	int day;
	int month;
	int year;
};

class User
{
public:
	User& operator=(const User& user)
	{
		strcopy(this->name, user.name);
		this->skills = user.skills;
		this->gender = user.gender;
		this->birthday = user.birthday;
		return *this;
	}
	void display();
	void setName(char* name);
	void setSkills(bool skill);
	void setGender(Gender gender);
	void setDate(Date date);
	User(Date date);
	User(char* name, bool skills, Gender gender, Date date);
	User enterUser();
private:
	static int counterUsers;
	char name[N];
	bool skills;
	Gender gender;
	Date birthday;
	static void strcopy(char* name, const char* source);
};