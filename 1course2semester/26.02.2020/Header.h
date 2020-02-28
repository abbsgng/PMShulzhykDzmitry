#pragma once

class RationalFraction
{
private:
	int numerator;
	int denominator;
	public:
	RationalFraction();
	RationalFraction(int num, int denom);
	void Enter();
	void Display();
	int getNumerator() const;
	int getDenominator() const;
	int NOD();
};