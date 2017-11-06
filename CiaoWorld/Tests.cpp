#include "stdafx.h"			//needed for VS

//this file houses test function(s)

#include "MathFunctions.h"	//for  math functions
#include <iostream>			//for std::cout


int testFunction()
{
	//includes unit tests for several basic math functions
	std::cout << "Starting Testing!" << "\n";

	if (isEqual(0.0, 0.0) == false) 	return 1;
	if (isEqual(1.78, 1.78) == false) 	return 2;
	if (isEqual(-0.1, -0.1) == false) return 3;
		
	if (iPow(2, 2) != 4) return 4;
	if (iPow(2, 0) != 1) return 5;
	if (iPow(5, 1) != 5) return 6;
	
	if (isEven(1) == true ) return 7;
	if (isEven(2) == false) return 8;
	if (isEven(8) == false) return 9;

	if (isApproximatelyEqualAbsRel(0.1, 0.1, 0.01, 0.001) == false) return 10;
	if (isApproximatelyEqualAbsRel(0.1, 0.01, 0.001, 0.001) == true) return 11;

	std::cout << "Ending testing. No errors found.\n";
	return 0;
}