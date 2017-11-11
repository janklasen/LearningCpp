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
void				BubbleSortIntArrayToBiggestFirst(int array[], short arraylength)
{

	//bubble array sorting program from biggest to smallest

	//Loop Counter is used to debug/measure perfomance of the loop, not used atm, can delete.
	int LoopCounter = 0;

	for (int counter1 = 0; counter1 < (arraylength - 1); ++counter1)
	{
		//for early exit if poss
		bool isSorted = true;

		for (int innerCounter = 0; innerCounter < (arraylength - counter1); ++innerCounter)
		{
			++LoopCounter;
			if (array[innerCounter] < array[(innerCounter + 1)])
			{
				std::swap(array[innerCounter], array[innerCounter + 1]);
				isSorted = false;
			}
		}
		if (isSorted)
		{
			//one full inner iteration without a single swap/succesful check means we can  exit earlier
			break;
		}
	}
	//perfomance analysis would need to go here via LoopCounter

}
void				BubbleSortIntArrayToSmallestFirst(int array[], short arraylength)
{
	for (int counter1 = 0; counter1 < (arraylength - 1); ++counter1)
	{
		bool isSorted = true;
		for (int innerCounter = 0; innerCounter < (arraylength - 1); ++innerCounter)
		{

			if (array[innerCounter] > array[(innerCounter + 1)])
			{
				std::swap(array[innerCounter], array[innerCounter + 1]);
				isSorted = false;
			}
		}
		if (isSorted)
		{
			//exit loop early if possible due to no changes
			break;
		}
	}
}
void				BubbleSortStringArrayToSmallestFirst(std::string array[], short arraylength)
{
	for (int counter1 = 0; counter1 < (arraylength - 1); ++counter1)
	{
		bool isSorted = true;
		for (int innerCounter = 0; innerCounter < (arraylength - 1); ++innerCounter)
		{

			if (array[innerCounter] > array[(innerCounter + 1)])
			{
				std::swap(array[innerCounter], array[innerCounter + 1]);
				isSorted = false;
			}
		}
		if (isSorted)
		{
			//exit loop early if possible due to no changes
			break;
		}
	}
}
int					SearchForIndexOfInteger(int array[], int searchedInt, int arrayLength)
{
	for (int counter = 0; counter < arrayLength; ++counter)
	{
		if (array[counter] == searchedInt)
		{
			std::cout << "The index of the value you are looking for is: " << counter << " ";
			return counter;
		}
		else
		{
			//TODO: Need better error checking here. Returning 0 is a very bad solution.
			std::cout << "The array does not contain the number you were looking for. Returning 0 instead \n.";
			return 0;
		}

	}
	return 0;
}
void				Create1DArrayFromUserInput()
{
	int length;
	std::cout << "Enter the length of the desired integer array: ";
	length = GetIntInRangeFromUser(0, 2147483647);
	std::cout << "the length of your array is: " << length << "\n";

	int *array = new int[length];
	delete[] array;
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

bool	WantToRepeatHilogame()
{
	//repeats hilogame if user wants to 
	using std::cout;
	using std::cin;


	char replay;

	//handle user input
	while (true)
	{
		cout << "Would you like to play again? (y/n): ";
		cin >> replay;
		cin.ignore(32767, '\n');

		if (replay == 'y' || replay == 'n')
		{
			break;
		}
		else
		{
			cout << "Invalid Input - try again \n";
			continue;
		}
	}
	//handle whether to play again
	if (replay == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool	WonHiloGameLoopSimple()
{
	using std::cout;
	using std::cin;
	short userInput;

	//first pngr call is always the same
	GetRandomNumber(1, 100);

	int randomNumber = GetRandomNumber(1, 100);

	for (short attempts = 0; attempts <= 7; ++attempts)
	{
		cout << "Your Guess #" << attempts << ": ";
		userInput = static_cast<int>(GetDoubleFromUser());




		if (userInput == randomNumber)
		{
			cout << "You win. The number is indeed: " << randomNumber << ", just like your guess: " << userInput << "\n";
			return true;
		}

		if (userInput > randomNumber)
		{
			cout << "The number you entered is too big. \n";
		}

		if (userInput < randomNumber)
		{
			cout << "The number you entered is too small. \n";
		}
	}
	cout << "You lose. The number was: " << randomNumber << "\n";
	return false;
}
short	AmountOfVowelsInString(std::string strArr, int length)
{
	int vowels{ 0 };
	for (int counter = 0; counter < length; ++counter)
	{
		switch (strArr[counter])
		{
		case 'a':
		case 'o':
		case 'e':
		case 'i':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		{
			++vowels;
		}
		}
	}
	return vowels;
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
void	HiloGameShell()
{
	using std::cout;
	using std::cin;
	//	srand(static_cast<unsigned int>(time(0)));
	//this needs to go into main()

	while (true)
	{
		cout << "HINT: 	srand needs to run in main() \n";
		//start initial game loop
		//get back result of game (as int of num of attemptsleft, -1 counts as lost ;D)
		bool hasWon = WonHiloGameLoopSimple();

		if (hasWon)
		{
			cout << "You won the game. Congratulations. \n";
		}

		else
		{
			cout << "You lost the game. Too bad. \n";
		}
		//call interprete Game result function and print resulst

		//ask if user wants to replay, in that case
		bool willRepeat = WantToRepeatHilogame();

		if (willRepeat)
		{
			cout << "Get ready for another round! \n";
		}

		else
		{
			cout << "Thanks for playing! \n";
			break;
		}
	}
}
void	PrintSortedNamesFromUserInput()
{
	using std::cout;
	using std::cin;

	//how many names? - array length (max is 100 atm)
	cout << "How many names would you like to enter? ";
	short amountNames = GetIntInRangeFromUser(1, 100);
	cout << "\n";

	//dynamically create std::string array
	std::string *nameAr = new std::string[amountNames];

	//assign user values in the loop: 
	for (short counter = 0; counter < amountNames; ++counter)
	{
		nameAr[counter] = GetStringFromUser();

	}

	//sorting and printing functions get called

	BubbleSortStringArrayToSmallestFirst(nameAr, amountNames);
	cout << "\nYour sorted list: \n";
	PrintStringArray(nameAr, amountNames);

}
void	PrintAmountOfVowelsFromUserInput()
{
	//asks user to input a string
	//prints how many vowels said string contains
	//only a,e,i,o,u handled atm. no y etc
	std::string strArr = GetStringFromUser();
	int length = strArr.length();

	short vowelsInString = AmountOfVowelsInString(strArr, length);
	std::cout << "Your string contains " << vowelsInString << " vowels. \n";

	const int arrayLength = 7;
	char name[arrayLength] = "Mollie";
	int numVowels = 0;
}