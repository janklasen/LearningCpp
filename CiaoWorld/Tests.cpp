#include "stdafx.h"			//needed for VS

//this file houses test function(s)
//TODO (19/11/17): error codes based on arrays per function to improve usability and scalability
#include "MathFunctions.h"	//for  math functions
#include <iostream>			//for std::cout
#include "Tests.h"			//for error structs


short TestSimpleMath()
{
	//includes unit tests for several basic math functions

	if (!IsEqual(0.0, 0.0)) 	return 1;
	if (!IsEqual(1.78, 1.78)) 	return 2;
	if (!IsEqual(-0.1, -0.1))	return 3;
		
	if (PowInteger(2, 2) != 4) return 4;
	if (PowInteger(2, 0) != 1) return 5;
	if (PowInteger(5, 1) != 5) return 6;
	
	if (IsEven(1) ) return 7;
	if (!IsEven(2)) return 8;
	if (!IsEven(8)) return 9;

	if (!IsApproximatelyEqualAbsRel(0.1, 0.1, 0.01, 0.001)) return 10;
	if (IsApproximatelyEqualAbsRel(0.1, 0.01, 0.001, 0.001)) return 11;

	std::cout << "Simple math: NO ERRORS\n";
	return 0;
}
short TestArraySort()
{
	//initialize arrays and length
	int array1[] = { 1 , 100, -2 , 0 };
	int array2[] = { 1 , 100, -2 , 0 };
	int array3[] = { 1 , 100, -2 , 0 };
	int array4[] = { 1 , 100, -2 , 0 };
	int array5[] = { 1 , 100, -2 , 0};
	short arrayLength = 4;

	//call sort arrays for each array
	SimpleSortIntArrayToBiggestFirst	(array1, arrayLength);
	SimpleSortIntArrayToSmallestFirst	(array2, arrayLength);
	BubbleSortIntArrayToBiggestFirst	(array3, arrayLength);
	BubbleSortIntArrayToSmallestFirst	(array4, arrayLength);

	//check results
	if (array1[0] != 100 || array1[1] != 1 || array1[2] != 0 || array1[3] != -2)	return 1;
	if (array2[0] != -2 || array2[1] != 0 || array2[2] != 1 || array2[3] != 100)	return 2;
	if (array3[0] != 100 || array3[1] != 1 || array3[2] != 0 || array3[3] != -2)	return 3;
	if (array4[0] != -2  || array4[1] != 0 || array4[2] != 1 || array4[3] != 100)	return 4;

	//no errors
	std::cout << "Array Sorting: NO ERRORS.\n";
	return 0;
}
short TestSFraction()
{
	//test the functions related to SFraction struct

	SFraction fractionA = { 1,2 };
	SFraction fractionB = { 2,1 };

	double result1 = MultiplyTwoFractionStructs(fractionA, fractionB);

	if (result1 != 1) return 1;

	std::cout << "Fraction Structs: NO ERRORS.\n";
	return 0;


}

void QuickTest()
{
	TestSimpleMath();
	TestArraySort();
	TestSFraction();
}