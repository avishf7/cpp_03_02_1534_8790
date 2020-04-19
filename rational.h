/*
File: rational.h
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#ifndef RATIONAL_H
#define RATIONAL_H

#include"mytypes.h"
#include<iostream>
#include<cmath>

struct Rational
{
	int numerator;
	uint denominator = 0;
};
//The function accepts 2 numbers and returns the rational number
//If the user entered only one number, the rational value would be initialized in the denominator to 1
Rational rationalCtor(int numerator, uint denominator = 1);

// the function returns the largest divider of the two numbers
int gcd(int, int);

// the function returns the reduced fraction
void reductFraction(Rational&);

// Converter function from Rational to double 
double convert(const Rational& rNUm);

//The function does operator overloading Of operation plus
Rational operator + (const Rational&, const Rational&);

//The function does operator overloading Of prefix operation minus 
Rational operator-(const Rational&);

//The function does operator overloading Of operation minus
Rational operator - (const Rational&, const Rational&);

//The function does operator overloading Of operation multiplication
Rational operator * (const Rational&, const Rational&);

//The function does operator overloading Of operation <
bool operator < (const Rational&, const Rational&);

//The function does operator overloading Of operation >
bool operator > (const Rational&, const Rational&);

//The function does operator overloading Of operation <=
bool operator <=(const Rational&, const Rational&);

//The function does operator overloading Of operation >=
bool operator >=(const Rational&, const Rational&);

//The function does operator overloading Of operation ==
bool operator ==(const Rational&, const Rational&);

//The function does operator overloading Of operation !=
bool operator !=(const Rational&, const Rational&);

//The function does operator overloading Of operation >>
std::istream& operator >>(std::istream&,  Rational&);

//The function does operator overloading Of operation >>
std::ostream& operator <<(std::ostream&, const Rational&);


#endif
