#pragma once

#include <string>			//for std::string in the string sorting functions

//start  header guard
#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H


//function prototypes used as per forward declaration for math functions


//enums




//GENERAL FUNCTIONS

//returns if 2 doubles are equal
bool	IsEqual(double value1, double value2);

//returns pow of base and exp as integer
unsigned int	PowInteger(unsigned int base, unsigned int exp);

//returns true if passed integer is even
bool	IsEven(int iUserInput);

//sums all integers that a value contains i.e. 1+2+3 etc 
int SumTo(int value);

//basic random number generator, should not be used - strong periodity, seed is static
int BasicRandomNumberGenerator();

//needs seed to be initalised first as local time. otherwise good enough
int GetRandomNumber(int min, int max);

//needs testing, setting seed to system time outside of main() might get errors
void SetSeedBasedOnTime();

//prints 5 random numbers every line, in specified range
void PrintRandomNumbers(int amount, int rangeMin, int rangeMax);

//sorts integer array
void BubbleSortIntArrayToBiggestFirst(int *array, short arraylength);

//sorts integer array
void BubbleSortIntArrayToSmallestFirst(int *array, short arraylength);

//std::string sort
void BubbleSortStringArrayToSmallestFirst(std::string *array, short arraylength);

//should be preferred over bubble sort
void	SimpleSortIntArrayToBiggestFirst(int *array, short arraylength);

//should be preferred over bubble sort
void	SimpleSortIntArrayToSmallestFirst(int *array, short arraylength);

//should be preferred over bubble sort
void	SimpleSortStringArrayToSmallestFirst(std::string *array, short arraylength);

//TODO: if searched value is not in array, this will return 0 (bad solution) 
int	 SearchForIndexOfInteger(int *array, int searchedInt, int arrayLength);

//creates then deletes dynamically a 1d array. TODO: delete because useless.
void Create1DArrayFromUserInput();





//SPECIFIC SLAVE FUNCTIONS

//returns height of an object/ball in free flight
double	FallenBallHeight(double dUserBallHeight, short sSeconds, double dCurrentHeight);

//returns result of 2 double operators and 1 short operation (+/-/:/*)
double	ProcessResult(double value1, char operation, double value2);

//returns if 2 doubles are approximately equal
bool IsApproximatelyEqualAbsRel(double value1, double value2, double epsilonAbs, double epsilonRel);

//true if you want to reply. asks user
bool WantToRepeatHilogame();

//true if won. main game loop
bool WonHiloGameLoopSimple();

//only a,e,i,o,u handled atm (capital and regular size)
short AmountOfVowelsInString(std::string strArr, int length);





//SPECIFIC MASTER FUNCTIONS

//outputs to console how many seconds a ball needs to drop from a user specified height
void	FreeFallSimulator();

//simple calculation functions; uses 2 doubles and 1 operand (+/-/:/*)
void	SimpleCalculator();

//handles calling of game loop and repeat game function
void HiloGameShell();

//get string list from user then output sorted strings
void PrintSortedNamesFromUserInput();

//gets string from user and prints how many vowels are contained. aouie only
void PrintAmountOfVowelsFromUserInput();


//end header guard
#endif 