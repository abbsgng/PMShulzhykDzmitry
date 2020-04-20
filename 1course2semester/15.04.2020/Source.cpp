#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BigInteger.h"

using namespace std;



int main()
{
	char temp1[1000] = "154567345";
	char temp2[1000] = "56784356";
	BigInteger number1(temp1);
	BigInteger number2(temp2);
	BigInteger number3;
	number3 = number1-number2;
	number3.display();
	return 0;
}


