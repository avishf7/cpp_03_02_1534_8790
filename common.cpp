/*
File: common.cpp
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#include "common.h"

void operetion(void* d, const void* l, const void* r, void(*operationFunctionPtr)(void*, const void*, const void*))
{
	operationFunctionPtr(d, l, r);
}
