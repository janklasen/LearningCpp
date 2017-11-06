#pragma once

//start  header guard
#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H


//function prototypes used as per forward declaration for math functions


//enums
enum class Mathoperation
{
	//included EMPTY because my integer logic assumes 1 for ADD
	//Mathoperation used by simpleCalculator() and its "slave" functions
	EMPTY,
	ADD,
	SUBSTRACT,
	MULTIPLY,
	DIVIDE
};




//GENERAL FUNCTIONS

//returns if 2 doubles are equal
bool	isEqual(double value1, double value2);

//returns pow of base and exp as integer
unsigned int	iPow(unsigned int base, unsigned int exp);

//returns true if passed integer is even
bool	isEven(int iUserInput);





//SPECIFIC SLAVE FUNCTIONS

//returns height of an object/ball in free flight
double	fallenBallHeight(double dUserBallHeight, short sSeconds, double dCurrentHeight);

//returns result of 2 double operators and 1 short operation (+/-/:/*)
double	processResult(double value1, char operation, double value2);

//returns if 2 doubles are approximately equal
bool isApproximatelyEqualAbsRel(double value1, double value2, double epsilonAbs, double epsilonRel);





//SPECIFIC MASTER FUNCTIONS

//outputs to console how many seconds a ball needs to drop from a user specified height
void	freeFallSimulator();

//simple calculation functions; uses 2 doubles and 1 operand (+/-/:/*)
void	simpleCalculator();




//end header guard
#endif 