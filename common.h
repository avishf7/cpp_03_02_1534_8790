/*
File: common.h
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#ifndef COMMON
#define COMMON

#include "rational.h"
#include "complex.h"

//function Template that accepts 2 numbers 
//and returns the result of their amount:
template <typename T>
const T add(const T& n1, const T& n2)
{
	return n1 + n2;
}
extern template const int add(const int& n1, const int& n2);
extern template const double add(const double& n1, const double& n2);
extern template const Rational add(const Rational& n1, const Rational& n2);
extern template const Complex add(const Complex& n1, const Complex& n2);

//function Template that accepts 2 numbers 
//and returns the result of subtracting each other:
template <typename T> 
const T sub(const T& n1, const T& n2)
{
	return n1 - n2;
}

//function Template that accepts 2 numbers 
//and returns the result of multiplying them:
template <typename T>
const T mult(const T& n1, const T& n2)
{
	return n1 * n2;
}
extern template const int mult(const int& n1, const int& n2);
extern template const double mult(const double& n1, const double& n2);
extern template const Rational mult(const Rational& n1, const Rational& n2);
extern template const Complex mult(const Complex& n1, const Complex& n2);


//function Template that receives 2 rational numbers and compares them
//If they are equal the function returns 0
//If the first number is greater than the second number the function returns 1
//If the first number is less than the second number the function returns - 1
template <typename T>
int compare(const T* n1, const T* n2)
{
	if (*n1 == *n2)
		return 0;

	if (*n1 > *n2)
		return 1;

	return -1;
}
#endif

