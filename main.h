#ifndef MAIN
#define MAIN

/*
File: main.h
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/

#include <iomanip>
#include "common.h"
#include "rational.h"
#include <iostream>
#include "complex.h"
#include <ctime>

// These are all of the main menu options.
// the user will see them on the screen,
// and will input them for
// choosing a menu option.
enum MenuOption {
	EXIT_MENU,
	INPUT_A_TYPE_OF_NUMBER,
	PRINT_ALL_NUMBERS_OF_ONE_TYPE,
	ADD_ALL_NUMBERS_OF_ONE_TYPE,
	MULTIPLIES_ALL_NUMBERS_OF_ONE_TYPE,
	SUM_TWO_ELEMENTS,
	MULTYPLY_TWO_ELEMENTS,
	SUB_TWO_ELEMENTS,
	SORT_ELEMENTS_OF_ONE_TYPE,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = SORT_ELEMENTS_OF_ONE_TYPE
};

// These are all of the number types.
enum Types {
	INT = 1,
	DOUBLE,
	RATIONAL,
	COMPLEX,
	INT_IN_RATIONAL,
	INT_IN_COMPLEX,
	RATIONAL_IN_COMPLEX,
	// a neat trick for for-loop initial and final values
	FIRST_TYPE = INT - 1,
	LAST_TYPE = COMPLEX - 1,
	LAST_CHOICE = RATIONAL_IN_COMPLEX - 1
};

// These strings will be seen by the user, on the main menu.
const char* const menuOptionStrings[] = {
	"exit the program",
	"input type of number to spcific element",
	"show all the elements of one type",
	"calculate the sum of all numbers of the same type",
	"calculate the multiples of all numbers of the same type",
	"calculate the sum of two elements of the same type and placing the result in another",
	"calculate the multiples of two elements of the same type and placing the result in another",
	"calculate the difference of two elements of the same type and placing the result in another",
	"sort elements of one type",
};

// These strings will be seen by the user, to choose number type.
const char* const typesStrings[] = {
	"int",
	"double",
	"rational",
	"complex",
	"int in rational",
	"int in complex",
	"rational in complex"
};
#endif