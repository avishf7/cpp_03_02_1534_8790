/*
File: complex.h
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>
#include"rational.h"

struct Complex
{
	double real;
	double imaginary;
};
//The function accepts 2 numbers and returns the complex number
//If the user entered only one number, the imaginary value would be initialized in the 0
Complex complexCtor(double real, double imaginary = 0);

//The function accepts rational numer and returns complex number 
//The real part is equal to the rational number and the imaginary part is equal to 0
Complex& complexCtor(Rational&);

//The function accepts  a complex number and returns its length
double abs(const Complex&);

//The function accepts 2 complex numbers and adds to each other
void addComplex(void*, const void*, const void*);

//The function accepts 2 complex numbers and returns one minus the other
void subComplex(void*, const void*, const void*);

//The function accepts 2  complex numbers and returns one double the other
void multComplex(void*, const void*, const void*);

//The function receives 2 complex numbers and compares them
//If they are equal the function returns 0
//If the first number is greater than the second number the function returns 1
//If the first number is less than the second number the function returns - 1
int compareComplex(const void* l, const void* r);

//The function does operator overloading Of operation plus
Complex operator + (const Complex&, const Complex&);

//The function does operator overloading Of operation minus
Complex operator - (const Complex&, const Complex&);

//The function does operator overloading Of operation multiplication
Complex operator * (const Complex&, const Complex&);

//The function does operator overloading Of operation <
bool operator < (const Complex&, const Complex&);

//The function does operator overloading Of operation >
bool operator > (const Complex&, const Complex&);

//The function does operator overloading Of operation <=
bool operator <=(const Complex&, const Complex&);

//The function does operator overloading Of operation >=
bool operator >=(const Complex&, const Complex&);

//The function does operator overloading Of operation == Between the length of the composite numbers
bool operator ==(const Complex&, const Complex&);

//The function does operator overloading Of operation != Between the length of the composite numbers
bool operator !=(const Complex&, const Complex&);

//The function does operator overloading Of operation >>
std::istream& operator >>(std::istream&, Complex&);

//The function does operator overloading Of operation <<
std::ostream& operator <<(std::ostream&, const Complex&);
#endif
