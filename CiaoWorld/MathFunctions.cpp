//this file houses a collection of math functions

#include "stdafx.h"
#include <iostream>
#include "Constants.h"		//include gravity
#include "InputOutput.h"	//include to call IO function from dFallenHeight, freeFallSimulator and simpleCalculator, includes structs for fractions
#include "MathFunctions.h"  //include enums
#include <cmath>			//for fabs
#include <cstdlib>			//for rand() and srand()
#include <ctime>			//for time()

//TODO: decide whether I want to move freeFallSimulator() and simpleCalculator to their own .cpp file
//      so that mathfunctions.cpp is more seperate from input/output





//non specific functions: can be used in a general way
bool				IsEqual(double value1, double value2)
{
	//this function checks if two doubles are equal and returns 0/1 false/true

	if (value1 == value2)
		return true;

	return false;

}
unsigned int		PowInteger(unsigned int iBase, unsigned int iExp)
{
	//returns POW based on base and exp arguments
	//TODO: Properly handle negative exponents and negative bases
	//TODO: test for exponents larger than 25 (up until 32)
	

	unsigned int iResult{iBase};
	
	//exponent = 0 means number evaluates to 1
	if (iExp == 0)
		return 1;



	//start pow algorith
	//currently max is a 4 byte signed integer, 2^31-1 is max
	while (iExp != 1 && iResult < 4294967295)
	{
		--iExp;
		iResult *= iBase;
			
	}

	return iResult;
}
bool				IsEven(int iUserInput)
{
	//returns true if passed integer is even

	if (iUserInput % 2 == 0)
		return true;
		
	else
		return false;

}
bool				IsApproximatelyEqualAbsRel(double value1, double value2, double epsilonAbs, double epsilonRel)

{
	//returns if 2 doubles are approximaely equal

	//absolute epsilon method, usually sufficient
	if (fabs(value1 - value2) <= epsilonAbs)
		return true;

	//fallback to relative epsilon method
	return fabs(value1 - value2) <= ((value1 > value2) ? value1 : value2) * epsilonRel;

}
int					SumTo(int value)
{
	int result{ 0 };

	for (; value > 0; --value)
		result += value;

	return result;
}
int					BasicRandomNumberGenerator()
{
	static unsigned int s_seed = 5233;

	s_seed = s_seed * 9898251 + 2152108;
	return s_seed % 32768;
}
int					GetRandomNumber(int min, int max)
{
	//get random number between  min and max
	//makes use of srand() being defined as follows:
	//srand(static_cast<unsigned int>(time(0)));


	static const double s_fraction = (1.0 / static_cast<double>(RAND_MAX));

	//std::cout << "\n Fraction is: " << fraction << "\n";
	int random1 = rand();
	//std::cout << "Random numberis: " << random1 << "\n";

	double scaledRandom = (random1 * s_fraction);
	//std::cout << "Random scaled numberis: " << scaledRandom << "\n";

	double rangedRandom = (scaledRandom * max);
	//std::cout << "Random scaled and ranged numberis: " << rangedRandom << "\n";

	double randomfullyRanged = (rangedRandom + 1);
	//std::cout << "Your fully ranged random is: " << randomfullyRanged << "\n";


	return static_cast<int>(randomfullyRanged);
}
void				SetSeedBasedOnTime()
{//set seed for prng to system time via time C functon
	srand(static_cast<unsigned int>(time(0)));
}
void				PrintRandomNumbers(int amount, int rangeMin, int rangeMax)
{
	for (int count = 1; count <= amount; count++)
	{
		std::cout << GetRandomNumber(rangeMin, rangeMax) << " ";

		if (count % 5 == 0)
		{
			std::cout << "\n";
		}
	}

}

//specific slave functions: only used by master functions
double	ProcessResult(double value1, char operation, double value2)
{
	//this function processes a result based on 3 arguments: 2 values
	//Id of operation handled via enums defined in header of mathfunctions
	//to take place 1 = + , 2 = -, 3 = * , 4 = /

	//all 4 cases for basic math operations are handled in the following:

	switch (operation)
	{
	case '+':
		return value1 + value2;

	case '-':
		return value1 - value2;

	case '*':
		return value1 * value2;

	case '/':
		return value1 / value2;

	default:
		return value1 + value2;

	}
}
double	FallenBallHeight(double dUserBallHeight, short sSeconds, double dCurrentHeight)

{
	//returns height of ball, using user specified height, current
	//check if the ball is already on the ground on function start
	//if not, apply free fall calculation
	
	if (dCurrentHeight > 0)

	{
		//calculate distance an object/ball falls in sSeconds in free fall
		double dFallenHeight{ constants::s_gravity * sSeconds * sSeconds * 0.5 };

		//apply distance fallen (Distance of ball to ground at sSeconds) 
		double dCurrentHeight = dUserBallHeight - dFallenHeight;

		return dCurrentHeight;
	}

	//return 0.0 if not above ground
	else
		return 0.0;

}

double	DoubleFromFractionStruct(SFraction fraction1)
{
	//returns numerator/denominator as double
	double fractionA = fraction1.numerator / fraction1.denominator;
	std::cout << "Your fraction " << fraction1.numerator << " / " << "evaluates to " << fractionA << " \n";
	return fractionA;
}
double	MultiplyTwoFractionStructs(SFraction fraction1, SFraction fraction2)
{
	//multiplies 2 fraction structs - calls other function
	double result = DoubleFromFractionStruct(fraction1) * DoubleFromFractionStruct(fraction2);
	return result;
}


//specific master functions: 
void	FreeFallSimulator()
{
	//outputs after how many seconds that object (a ball)  has hit the ground
	//simulates the free fall of an object at a user specified height
	using std::cout;
	
	//Input-Output Start
	cout << "This will calculate the amount of seconds a ball needs to fall from the value in meters you specify. \n";

	// get user input(= towerheight, ball height)
	double dUserBallHeight = GetDoubleFromUser();

	//need both current height of object and original height 
	//to know when to stop simulating
	double dCurrentHeight = dUserBallHeight;


	//foolproof: no output if user inputs 0
	if (dUserBallHeight == 0)
		cout << "The Ball is already on the ground. No Calculation will be output. \n";

	//Input-Output end

	//run simulation and output funtions until the object hits the ground.
	short sSecond{ 1 };

	while (dCurrentHeight > 0)
	{

		dCurrentHeight = FallenBallHeight(dUserBallHeight, sSecond, dCurrentHeight);
		PrintBallHeight(dCurrentHeight, sSecond);
		sSecond++;
		
	}


}
void	SimpleCalculator()
{
	//simple calculation functions; uses 2 doubles and 1 operand (+/-/:/*)

	//Get First Value
	double dfirstValue = GetDoubleFromUser();


	//Get Operation
	char operationIdExternal = GetMathematicalOperationFromUser();


	//Get Second Value
	double dsecondValue = GetDoubleFromUser();

	//Check if Values are equal
	bool bIsEqual = IsEqual(dfirstValue, dsecondValue);
	if (bIsEqual)
		std::cout << "Both operands that were entered are the same." << std::endl;



	//calculate result
	double result = ProcessResult(dfirstValue, operationIdExternal, dsecondValue);


	//outputResult 
	PrintDouble(result);


}
