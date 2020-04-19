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

//The function accepts 2 rational numbers and adds to each other
void addRational(void*, const void*, const void*);

//The function accepts 2 rational numbers and returns one minus the other
void subRational(void*, const void*, const void*);

//The function accepts 2 rational numbers and returns one double the other
void multRational(void*, const void*, const void*);

//The function receives 2 rational numbers and compares them
//If they are equal the function returns 0
//If the first number is greater than the second number the function returns 1
//If the first number is less than the second number the function returns - 1
int compareRational(const void*, const void*);

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
