#include <iostream>
#include "Header.h"

using namespace std;
Date::Date()
{
	year = 1921;
	month = 1;
	day = 1;
}
Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}
void Date::dayValidation()
{
	if (year < 1920 || year > 2020)
	{
		throw std::invalid_argument("Year cant't be less than 0.");
	}
	if (month > 12 || month <= 0)
	{
		throw std::invalid_argument("Month must be from 1 to 12");
	}
	switch (this->month)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (day > 31 || day <= 0)
		{
			throw std::invalid_argument("There are no such days this month");
		}
		break;
	case 4: case 6: case 9:case 11:
		if (day > 30 || day <= 0)
		{
			throw std::invalid_argument("There are no such days this month.");
		}
		break;
	case 2:
		if (isYearLeap(this->year))
		{
			if (day > 29 || day <= 0)
			{
				throw std::invalid_argument("There are no such days this month.");
			}
		}
		else
		{
			if (day > 28 || day <= 0)
			{
				throw std::invalid_argument("There are no such days this month.");
			}
		}
		break;
	}
}
int Date::getYear()
{
	return year;
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}
bool Date::isYearLeap(int year)
{
	if (year % 4 != 0)
	{
		return false;
	}
	else if (year % 100 == 0 && year % 400 != 0)
	{
		return false;
	}
	else
		return true;
}
void Date::setYear(int year)
{
	this->year = year;
	dayValidation();
}
void Date::setMonth(int Month)
{
	this->month = month;
	dayValidation();
}
void Date::setDay(int day)
{
	this->day = day;
	dayValidation();
}
Date Date::enterDate()
{
	cout << "Enter your birthday." << endl;
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	dayValidation();
	return Date(year, month, day);
}
void Date::display()
{
	dayValidation();
	cout << day << "." << month << "." << year << endl;
}

int User::counterUsers = 0;
void User::strcopy(char* name, const char* source)
{
	int i = 0;
	for (; i < strlen(source); ++i)
	{
		name[i] = source[i];
	}
	name[i] = '\0';
}
void User::setName(char* name)
{
	if (strlen(name) > N)
	{
		throw std::invalid_argument("Toooooo looooooong name.");
	}
	strcopy(this->name, name);
}
void User::setSkills(bool skill)
{
	skills = skill;
}
void User::setGender(Gender gender)
{
	this->gender = gender;
}
void User::setDate(Date date)
{
	this->birthday = date;
}
User::User(Date date)
{
	strcopy(this->name, "User");
	skills = false;
	gender = male;
	birthday = date;
}
User::User(char* name, bool skills, Gender gender, Date date)
{
	strcopy(this->name, name);
	this->skills = skills;
	this->gender = gender;
	this->birthday = date;
}
void User::display()
{
	cout << "User #" << ++counterUsers << endl;
	cout << "Name: " << name << endl;
	cout << "Birthday date: ";
	birthday.display();
	cout << "Skills: ";
	if (skills)
	{
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;

	switch (gender)
	{
	case male:
		cout << "Gender: male" << endl;
		break;
	case female:
		cout << "Gender: male" << endl;
		break;
	}
}
User User::enterUser()
{
	Date date;
	cout << "Hello, enter your name" << endl;
	cin.getline(this->name, N);
	birthday = date.enterDate();
	cout << "Are you a programmer?" << endl;
	cout << "Yes enter 1,No enter 0"<<endl;
	cin >> skills;
	short gender;
	bool flag = true;
	cout << "Man 1" << endl;
	cout << "Woman 2" << endl;
	cin >> gender;
	while (flag)
	{
		switch (gender)
		{
		case 1:
			this->gender = male;
			flag = false;
			break;
		case 2:
			this->gender = female;
			flag = false;
			break;
		default:
			flag = true;
		}
	}

	return User(this->name, skills, this->gender, birthday);
}
int main()
{
	User user1 = user1.enterUser();
	user1.display();
	User user2 = user2.enterUser();
	user2.display();
	User user3 = user3.enterUser();
	user3.display();
	return 0;
}
