/*
File: complex.cpp
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/

#include "complex.h"
using namespace std;

Complex complexCtor(double real, double imaginary)
{
	Complex cNum;

	cNum.real = real;
	cNum.imaginary = imaginary;

	return cNum;
}

Complex& complexCtor(Rational& rNum)
{
	Complex cNum;

	cNum = complexCtor(convert(rNum));

	return cNum;
}

double abs(const Complex& cNum)
{
	return sqrt(cNum.real * cNum.real + cNum.imaginary * cNum.imaginary);
}

void addComplex(void* d, const void* l, const void* r)
{
	*(Complex*)(d) = *(Complex*)(l)+*(Complex*)(r);
}

void subComplex(void* d, const void* l, const void* r)
{
	*(Complex*)(d) = *(Complex*)(l)-*(Complex*)(r);
}

void multComplex(void* d, const void* l, const void* r)
{
	*(Complex*)(d) = (*(Complex*)(l))*(*(Complex*)(r));
}

int compareComplex(const void* l, const void* r)
{
	if (*(Complex*)(l) == *(Complex*)(r))
		return 0;

	if (*(Complex*)(l) > * (Complex*)(r))
		return 1;

	return -1;
}

Complex operator+(const Complex& l, const Complex& r)
{
	Complex cNum;

	cNum.real = l.real + r.real;
	cNum.imaginary = l.imaginary + r.imaginary;

	return cNum;
}

Complex operator-(const Complex& l, const Complex& r)
{
	Complex cNum;

	cNum.real = l.real - r.real;
	cNum.imaginary = l.imaginary - r.imaginary;

	return cNum;
}

Complex operator*(const Complex& l, const Complex& r)
{
	Complex cNum;

	cNum.real = (l.real * r.real) - (l.imaginary * r.imaginary);
	cNum.imaginary = l.real * r.imaginary + r.real * l.imaginary;

	return cNum;
}

bool operator<(const Complex& l, const Complex& r)
{
	return (abs(l) - abs(r)) < 0;
}

bool operator>(const Complex& l, const Complex& r)
{
	return (abs(l) - abs(r)) > 0;
}

bool operator<=(const Complex& l, const Complex& r)
{
	return !(l > r);
}

bool operator>=(const Complex& l, const Complex& r)
{
	return !(l < r);
}

bool operator==(const Complex& l, const Complex& r)
{
	return !(l != r);
}

bool operator!=(const Complex& l, const Complex& r)
{
	return (abs(l) - abs(r));
}

istream& operator>>(istream& in, Complex& cNum)
{
	double real, imaginary;

	in >> real >> imaginary;
	cNum = complexCtor(real, imaginary);

	return in;
}

ostream& operator<<(ostream& out, const Complex& cNum)
{
	out << cNum.real;
	(cNum.imaginary >= 0) ? out << " + " << cNum.imaginary : out << " - " << -cNum.imaginary;
	out << " * i";

	return out;
}
