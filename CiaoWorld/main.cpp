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
void PrintEvenNumbersTo20()
{
	for (short count = 0; count <= 20; count+=2)
	{
			std::cout << count;
	
		
	}
}
int SumTo(int value)
{
	int result{ 0 };

	for (; value > 0; --value)
		result += value;

	return result;
}
int BasicRandomNumberGenerator()
{
	static unsigned int s_seed = 5233;

	s_seed = s_seed * 9898251 + 2152108;
	return s_seed % 32768;
}
int GetRandomNumber(int min, int max)
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
	
	double rangedRandom = (scaledRandom * max );
	//std::cout << "Random scaled and ranged numberis: " << rangedRandom << "\n";
	
	double randomfullyRanged = (rangedRandom +1);
	//std::cout << "Your fully ranged random is: " << randomfullyRanged << "\n";


	return static_cast<int>(randomfullyRanged);
}
void SetSeedBasedOnTime()
{//set seed for prng to system time via time C functon
	srand(static_cast<unsigned int>(time(0)));
}
void PrintRandomNumbers(int amount)
{
	for ( int count = 1; count <= amount; count++)
	{
		std::cout << GetRandomNumber(1,10) << " ";

		if (count % 5 == 0)
		{ 
			std::cout << "\n";
		}
	}

}
bool WantToRepeatHilogame()
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
bool WonHiloGameLoopSimple()
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
void HiloGameShell()
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




//forward declarations
int  TestFunction();

int main()
{	
	





	return 0;
}


