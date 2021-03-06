/*
File: main.cpp
Description:
Course: 150018 C++ Workshop, Exercise 2, Question 2
Author: Dan Zilberstein
Students: eli iluz 311201354
		& avishay farkash 205918790
*/
#include "main.h"
using namespace std;

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {


	int iNumbers[4];
	double dNumbers[4];
	Rational rNumbers[4];
	Complex cNumbers[4];

	int iNum, iOper1, iOper2, iResult, chosen, type;
	double dNum;
	Rational rNum;
	Complex cNum;



	srand((unsigned)time(nullptr));

	for (int i = 0; i < 4; i++)
		iNumbers[i] = (rand() % 20) - 10;

	for (int i = 0; i < 4; i++)
		dNumbers[i] = (double)(rand() % 201 - 100) / (rand() % 91 + 10);

	for (int i = 0; i < 4; i++)
	{
		rNumbers[i].numerator = (rand() % 21) - 10;
		rNumbers[i].denominator = (rand() % 30) + 1;

		reductFraction(rNumbers[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		cNumbers[i].real = (double)(rand() % 201 - 100) / (rand() % 91 + 10);
		cNumbers[i].imaginary = (double)(rand() % 201 - 100) / (rand() % 91 + 10);
	}


	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;

		// The user will see:
		//
		//            0 -- exit the program
		//            1 --input type of number to spcific element
		//            2 --show all the elements of one type
		// etc.
		//
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION; chosen = (MenuOption)((int)chosen + 1))
		{
			cout << setw(menuIndent) << " " << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;

		cout << "Please choose a menu option: ";
		cin >> chosen;

		// the individual cases, match to the
		// operations they will perform.
		switch (chosen)
		{
		case EXIT_MENU:
			cout << endl << endl << setw(40) << " " << "thanks for using our calculator!" << endl << endl;
			break;
		case INPUT_A_TYPE_OF_NUMBER:
			cout << endl << "options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// etc.
			//
			for (type = FIRST_TYPE; type <= LAST_CHOICE; type++)
			{
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose an option: ";
			cin >> type;

			switch (type)
			{
			case INT:
				cout << "choose index to insert between 0 to 3 : " << endl;
				cin >> type;
				cout << "enter a integer number: " << endl;
				cin >> iNum;
				if (type < 0 || type>3)
					cout << endl << "ERROR: index not found" << endl;
				else
					iNumbers[type] = iNum;
				break;
			case DOUBLE:
				cout << "choose index to insert between 0 to 3 : " << endl;
				cin >> type;
				cout << "enter a decimal number: " << endl;
				cin >> dNum;
				if (type < 0 || type>3)
					cout << endl << "ERROR: index not found" << endl;
				else
					dNumbers[type] = dNum;
				break;
			case RATIONAL:
				cout << "choose index to insert between 0 to 3 : " << endl;
				cin >> type;
				cout << "enter two integer numbers for a rational number" << endl << "first one - numerator , second one - denominator: ";
				cin >> rNum;
				if (type < 0 || type>3)
					cout << endl << "ERROR: index not found" << endl;
				else if (rNum.denominator)
					rNumbers[type] = rNum;
				break;
			case COMPLEX:
				cout << "choose index to insert between 0 to 3 : " << endl;
				cin >> type;

				cout << "enter two decimal numbers for a comlex number" << endl << "first one - real , second one - imaginary: ";
				cin >> cNum;
				if (type < 0 || type>3)
					cout << endl << "ERROR: index not found" << endl;
				else
					cNumbers[type] = cNum;
				break;
			case INT_IN_RATIONAL:
				cout << "choose index to insert between 0 to 3 : " << endl;
				cin >> type;
				cout << "enter a integer number for a rational number: " << endl;
				cin >> iNum;
				if (type < 0 || type>3)
					cout << "ERROR: index not found" << endl;
				else
					rNumbers[type] = rationalCtor(iNum);
				break;
			case INT_IN_COMPLEX:
				cout << "choose index to insert between 0 to 3 : " << endl;
				cin >> type;
				cout << "enter a integer number for a comlex number: " << endl;
				cin >> dNum;
				if (type < 0 || type>3)
					cout << endl << "ERROR: index not found" << endl;
				else
					cNumbers[type] = complexCtor(dNum);
				break;
			case RATIONAL_IN_COMPLEX:
				cout << "choose index to insert between 0 to 3 : " << endl;
				cin >> type;
				cout << "enter two integer numbers for a rational number to input in complex number " << endl << "first one - numerator , second one - denominator: ";
				cin >> rNum;
				if (type < 0 || type>3)
					cout << endl << "ERROR: index not found" << endl;
				else if (rNum.denominator)
					cNumbers[type] = complexCtor(rNum);
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}


			break;

		case PRINT_ALL_NUMBERS_OF_ONE_TYPE:
			cout << endl << "types options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// 
			//
			for (type = FIRST_TYPE; type <= LAST_TYPE; type++)
			{
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose a type: ";
			cin >> type;

			switch (type)
			{
			case INT:
				for (int i = 0; i < 4; i++)
					cout << endl << "index [" << i << "] -- " << iNumbers[i] << endl;
				break;
			case DOUBLE:
				for (int i = 0; i < 4; i++)
					cout << endl << "index [" << i << "] -- " << dNumbers[i] << endl;
				break;
			case RATIONAL:
				for (int i = 0; i < 4; i++)
					cout << endl << "index [" << i << "] -- " << rNumbers[i] << endl;
				break;
			case COMPLEX:
				for (int i = 0; i < 4; i++)
					cout << endl << "index [" << i << "] -- " << cNumbers[i] << endl;
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}
			break;

		case ADD_ALL_NUMBERS_OF_ONE_TYPE:
			cout << endl << "types options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// 
			//
			for (type = FIRST_TYPE; type <= LAST_TYPE; type++)
			{
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose a type: ";
			cin >> type;

			switch (type)
			{
			case INT:
				iNum = iNumbers[0];
				for (int i = 1; i < 4; i++)
					iNum = add(iNum , iNumbers[i]);
				cout << endl << "the sum of all integer  numbers is: " << iNum << endl;
				break;
			case DOUBLE:
				dNum = dNumbers[0];
				for (int i = 1; i < 4; i++)
					dNum = add(dNum , dNumbers[i]);
				cout << endl << "the sum of all decimal numbers is: " << dNum << endl;
				break;
			case RATIONAL:
				rNum = rNumbers[0];
				for (int i = 1; i < 4; i++)
					rNum = add(rNum , rNumbers[i]);
				cout << endl << "the sum of all rational numbers is: " << rNum << endl;
				break;
			case COMPLEX:
				cNum = cNumbers[0];
				for (int i = 1; i < 4; i++)
					cNum = add(cNum , cNumbers[i]);
				cout << endl << "the sum of all complex numbers is: " << cNum << endl;
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}
			break;

		case MULTIPLIES_ALL_NUMBERS_OF_ONE_TYPE:
			cout << endl << "types options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// 
			//
			for (type = FIRST_TYPE; type <= LAST_TYPE;
				type++) {
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose a type: ";
			cin >> type;

			switch (type)
			{
			case INT:
				iNum = iNumbers[0];
				for (int i = 1; i < 4; i++)
					iNum = mult(iNum, iNumbers[i]);
				cout << endl << "the multiplies of all integer  numbers is: " << iNum << endl;
				break;
			case DOUBLE:
				dNum = dNumbers[0];
				for (int i = 1; i < 4; i++)
					dNum = mult(dNum, dNumbers[i]);
				cout << endl << "the multiplies of all decimal numbers is: " << dNum << endl;
				break;
			case RATIONAL:
				rNum = rNumbers[0];
				for (int i = 1; i < 4; i++)
					rNum = mult(rNum, rNumbers[i]);
				cout << endl << "the multiplies of all rational numbers is: " << rNum << endl;
				break;
			case COMPLEX:
				cNum = cNumbers[0];
				for (int i = 1; i < 4; i++)
					cNum = mult(cNum, cNumbers[i]);
				cout << endl << "the multiplies of all complex numbers is: " << cNum << endl;
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}
			break;

		case SUM_TWO_ELEMENTS:
			cout << endl << "types options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// 
			//
			for (type = FIRST_TYPE; type <= LAST_TYPE;
				type++) {
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose a type: ";
			cin >> type;

			switch (type)
			{
			case INT:
				cout << "choose the two indexes do you want to add:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					iNumbers[iResult] = add(iNumbers[iOper1], iNumbers[iOper2]);
				break;
			case DOUBLE:
				cout << "choose the two indexes do you want to add:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					dNumbers[iResult] = add(dNumbers[iOper1], dNumbers[iOper2]);
				break;
			case RATIONAL:
				cout << "choose the two indexes do you want to add:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					rNumbers[iResult] = add(rNumbers[iOper1], rNumbers[iOper2]);
				break;
			case COMPLEX:
				cout << "choose the two indexes do you want to add:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					cNumbers[iResult] = add(cNumbers[iOper1], cNumbers[iOper2]);
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}
			break;

		case MULTYPLY_TWO_ELEMENTS:
			cout << endl << "types options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// 
			//
			for (type = FIRST_TYPE; type <= LAST_TYPE;
				type++) {
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose a type: ";
			cin >> type;


			switch (type)
			{
			case INT:
				cout << "choose the two indexes do you want to multiply:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					iNumbers[iResult] = mult(iNumbers[iOper1], iNumbers[iOper2]);
				break;
			case DOUBLE:
				cout << "choose the two indexes do you want to multiply:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					dNumbers[iResult] = mult(dNumbers[iOper1], dNumbers[iOper2]);
				break;
			case RATIONAL:
				cout << "choose the two indexes do you want to multiply:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					rNumbers[iResult] = mult(rNumbers[iOper1], rNumbers[iOper2]);
				break;
			case COMPLEX:
				cout << "choose the two indexes do you want to multiply:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					cNumbers[iResult] = mult(cNumbers[iOper1], cNumbers[iOper2]);
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}
			break;

		case SUB_TWO_ELEMENTS:
			cout << endl << "types options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// 
			//
			for (type = FIRST_TYPE; type <= LAST_TYPE;
				type++) {
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose a type: ";
			cin >> type;

			switch (type)
			{
			case INT:
				cout << "choose the two indexes do you want to sub:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					iNumbers[iResult] = sub(iNumbers[iOper1], iNumbers[iOper2]);
				break;
			case DOUBLE:
				cout << "choose the two indexes do you want to sub:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					dNumbers[iResult] = sub(dNumbers[iOper1], dNumbers[iOper2]);
				break;
			case RATIONAL:
				cout << "choose the two indexes do you want to sub:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					rNumbers[iResult] = sub(rNumbers[iOper1], rNumbers[iOper2]);
				break;
			case COMPLEX:
				cout << "choose the two indexes do you want to sub:" << endl;
				cin >> iOper1 >> iOper2;
				cout << "choose the index for the result : " << endl;
				cin >> iResult;
				if (((iOper1 < 0) || (iOper1 > 3)) && ((iOper2 < 0) || (iOper2 > 3)) && ((iResult < 0) || (iResult > 3)))
					cout << endl << "ERROR: index not found" << endl;
				else
					cNumbers[iResult] = sub(cNumbers[iOper1], cNumbers[iOper2]);
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}
			break;


		case SORT_ELEMENTS_OF_ONE_TYPE:
			cout << endl << "types options:" << endl << endl;

			// The user will see:
			//
			//             0 -- int
			//         	   1 -- double
			//		       2 --rational
			//		       3 --complex
			// 
			//
			for (type = FIRST_TYPE; type <= LAST_TYPE;
				type++) {
				cout << setw(menuIndent) << " " << type + 1 << " -- ";
				cout << typesStrings[type] << endl;
			}
			cout << endl;

			cout << "Please choose a type: ";
			cin >> type;

			switch (type)
			{
			case INT:
				qsort(iNumbers, 4, sizeof * iNumbers, (comparator)compare<int>);
				break;
			case DOUBLE:
				qsort(dNumbers, 4, sizeof * dNumbers, (comparator)compare<double>);
				break;
			case RATIONAL:
				qsort(rNumbers, 4, sizeof * rNumbers, (comparator)compare<Rational>);
				break;
			case COMPLEX:
				qsort(cNumbers, 4, sizeof * cNumbers, (comparator)compare<Complex>);
				break;
			default:
				cout << endl << "ERROR:illegal choice" << endl;
				break;
			}
			break;

		default:
			cout << endl << "ERROR:illegal choice" << endl;
			break;
		}
	} while (chosen != EXIT_MENU);

	return 0;
}
