/*
File: ratinal.cpp
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#include "rational.h"
using namespace std;

Rational rationalCtor(int numerator, uint denominator)
{
	Rational rNum;

	rNum.numerator = numerator;
	rNum.denominator = denominator;

	reductFraction(rNum);
	return rNum;
}

int gcd(int num, int divNum)
{
	if (!divNum)
		return num;

	return gcd(divNum, num % (divNum));
}

void reductFraction(Rational& rNum)
{
	if (rNum.numerator)
	{
		int div, big, small;

		//decide who is the biggest:
		if (abs(rNum.numerator) > rNum.denominator)
		{
			big = abs(rNum.numerator);
			small = rNum.denominator;
		}
		else
		{
			big = rNum.denominator;
			small = abs(rNum.numerator);
		}

		div = gcd(big, small);

		rNum.numerator /= div;
		rNum.denominator /= div;
	}
	else
		rNum.denominator = 1;
}

void addRational(void* d, const void* l, const void* r)
{
	*(Rational*)(d) = *(Rational*)(l)+*(Rational*)(r);
}

void subRational(void* d, const void* l, const void* r)
{
	*(Rational*)(d) = *(Rational*)(l)-*(Rational*)(r);
}

void multRational(void* d, const void* l, const void* r)
{
	*(Rational*)(d) = *(Rational*)(l) * *(Rational*)(r);
}

int compareRational(const void* l, const void* r)
{
	if (*(Rational*)(l) == *(Rational*)(r))
		return 0;
	 
	if (*(Rational*)(l) > * (Rational*)(r))
		return 1;

	return -1;
}

double convert(const Rational& rNUm)
{
	return ((double)rNUm.numerator / rNUm.denominator);
}

Rational operator+(const Rational& l, const Rational& r)
{
	Rational sum;

	sum.numerator = (r.numerator * l.denominator) + (l.numerator * r.denominator);
	sum.denominator = r.denominator * l.denominator;

	reductFraction(sum);
	return sum;
}

Rational operator-(const Rational& num)
{
	Rational tmp;
	tmp.numerator = -num.numerator;
	tmp.denominator = num.denominator;
	return tmp;
}

Rational operator-(const Rational& l, const Rational& r)
{
	Rational sub;

	sub = l + -r;

	return sub;
}

Rational operator * (const Rational& l, const Rational& r)
{
	Rational mult;

	mult.numerator = r.numerator * l.numerator;
	mult.denominator = r.denominator * l.denominator;

	return mult;
}

bool operator < (const Rational& l, const Rational& r)
{
	return ((l - r).numerator < 0);
}

bool operator==(const Rational& l, const Rational& r)
{
	return !(l != r);
}

bool operator !=(const Rational& l, const Rational& r)
{
	return ((l - r).numerator);
}

bool operator >= (const Rational& l, const Rational& r)
{
	return !(l < r);
}

bool operator > (const Rational& l, const Rational& r)
{
	return ((l - r).numerator > 0);
}

bool operator <= (const Rational& l, const Rational& r)
{
	return !(l > r);
}

istream& operator>>(istream& in,  Rational& rNum)
{
	int numerator, denominator;
	in >> numerator >> denominator;

	if (denominator)
		(denominator > 0) ? rNum = rationalCtor(numerator, denominator) : rNum = rationalCtor(-numerator, -denominator);
	else
	{
		cout << endl << "MATH ERROR" << endl;
		rNum.denominator = 0;
	}
	return in;
}

ostream& operator<<(ostream& out, const Rational& rNum)
{
	out << rNum.numerator << "/" << rNum.denominator;

	return out;
}
