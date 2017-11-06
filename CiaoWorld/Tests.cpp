#include "stdafx.h"			//needed for VS

//this file houses test function(s)

#include "MathFunctions.h"	//for  math functions
#include <iostream>			//for std::cout


int TestFunction()
{
	//includes unit tests for several basic math functions
	std::cout << "Starting Testing!" << "\n";

	if (!IsEqual(0.0, 0.0)) 	return 1;
	if (!IsEqual(1.78, 1.78)) 	return 2;
	if (!IsEqual(-0.1, -0.1)) return 3;
		
	if (PowInteger(2, 2) != 4) return 4;
	if (PowInteger(2, 0) != 1) return 5;
	if (PowInteger(5, 1) != 5) return 6;
	
	if (IsEven(1) ) return 7;
	if (!IsEven(2)) return 8;
	if (!IsEven(8)) return 9;

	if (!IsApproximatelyEqualAbsRel(0.1, 0.1, 0.01, 0.001)) return 10;
	if (IsApproximatelyEqualAbsRel(0.1, 0.01, 0.001, 0.001)) return 11;

	std::cout << "Ending testing. No errors found.\n";
	return 0;
}