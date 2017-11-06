#pragma once

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





//SPECIFIC SLAVE FUNCTIONS

//returns height of an object/ball in free flight
double	FallenBallHeight(double dUserBallHeight, short sSeconds, double dCurrentHeight);

//returns result of 2 double operators and 1 short operation (+/-/:/*)
double	ProcessResult(double value1, char operation, double value2);

//returns if 2 doubles are approximately equal
bool IsApproximatelyEqualAbsRel(double value1, double value2, double epsilonAbs, double epsilonRel);





//SPECIFIC MASTER FUNCTIONS

//outputs to console how many seconds a ball needs to drop from a user specified height
void	FreeFallSimulator();

//simple calculation functions; uses 2 doubles and 1 operand (+/-/:/*)
void	SimpleCalculator();




//end header guard
#endif 