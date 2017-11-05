// main.cpp : Defines the entry point for the console application.
//TODO: Revisit printBinarayFromUserInput and iPow (03/11/17) (dd/mm/yy)


#include "stdafx.h"			//needed for VS
#include <iostream>			//standard i/o library 
#include "MathFunctions.h"	//contains function prototypes for math functions
#include "InputOutput.h"	//contains function prototypes for input/output
#include <cstdint>			//contains fixed width integers
#include <typeinfo>			//for typeid()
#include <string>			//for std::string
#include <cstdlib>			//for rand() and srand()
#include <ctime>			//for time()



//global variables





//enums




//structs





//functions
void printEvenNumbersTo20()
{
	for (short count = 0; count <= 20; count+=2)
	{
			std::cout << count;
	
		
	}
}
int sumTo(int value)
{
	int result{ 0 };

	for (; value > 0; value--)
		result += value;

	return result;
}
int PRNG()
{
	static unsigned int seed = 5233;

	seed = seed * 9898251 + 2152108;
	return seed % 32768;
}
int getRandomNumber(int min, int max)
{
	//get random number between  min and max
	//makes use of srand() being defined as follows:
	//srand(static_cast<unsigned int>(time(0)));

	static const double fraction = (1.0 / static_cast<double>(RAND_MAX));

	//std::cout << "\n Fraction is: " << fraction << "\n";
	int random1 = rand();
	//std::cout << "Random numberis: " << random1 << "\n";

	double scaledRandom = (random1 * fraction);
	//std::cout << "Random scaled numberis: " << scaledRandom << "\n";
	
	double rangedRandom = (scaledRandom * max );
	//std::cout << "Random scaled and ranged numberis: " << rangedRandom << "\n";
	
	double randomfullyRanged = (rangedRandom +1);
	//std::cout << "Your fully ranged random is: " << randomfullyRanged << "\n";


	return static_cast<int>(randomfullyRanged);
}
void initializeRandom()
{//set seed for prng to system time via time C functon
	srand(static_cast<unsigned int>(time(0)));
}
void printRandonNumbers(int amount)
{
	for ( int count = 1; count <= amount; count++)
	{
		std::cout << getRandomNumber(1,10) << " ";

		if (count % 5 == 0)
			std::cout << "\n";

	}

}
int main()
{	

	
	
	simpleCalculator();



	return 0;
}


