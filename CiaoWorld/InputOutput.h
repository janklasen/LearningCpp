#pragma once
//start header guard
#include "MathFunctions.h"		//for enums
#include <string>				//for std::string

#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H



//ENUMS

//for monster functions
enum class EMonsterType
{
	Ogre,
	Dragon,
	Orc,
	Giant,
	Spider,
	Slime
};

//for Animal functions
enum class EAnimal
{
	Pig,
	Chicken,
	Goat,
	Cat,
	Dog,
	Ostrich
};





//STRUCTS

//for fraction functions
struct SFraction
{
	double numerator;
	double denominator;


};   //for fraction functions //for fraction functions

//for monster functions 
struct SMonster
{
	EMonsterType type;
	std::string name;
	short health;

};	

//for advertising functions
struct SAdvertising
{
	unsigned int adsShown;
	double adsClicked;
	double averageEarnt;

};

//for user data generation function
struct SUser
{

	short id;
	std::string name;
	short age;

};




//FUNCTION DECLARATIONS




//INPUT FUNCTIONS

//returns double console user input
double	GetDoubleFromUser();	

//Return Monster Type as a string so it canbe printed
std::string GetMonsterTypeString(EMonsterType type1);

//return user age as short
short		GetAgeFromUser();

//return both first and last name from userinput
std::string	GetNameFromUser();

//returns unsigned integer user input as hexadecimal
unsigned int 		uiGetUserInputHex();

//returns ads struct data from user input
SAdvertising	GetAdsStructInputFromUser();

//returns fraction with data from user input
SFraction	GetFractionStructFromUser();

//returns animal as string
std::string		GetAnimalName(EAnimal animal1);





//SPECIFIC SLAVE FUNCTIONS

//returns mathematical operation as Mathoperation enum
char	GetMathematicalOperationFromUser();

//outputs height of a falling ball to console
void	printBallHeight(double dCurrentHeight, short sSeconds);





//OUTPUT FUNCTIONS

//outputs double to console
void	printDouble(double value);

//outputs size of common data types to console
void	printSizeOfAllTypes();

//prints rows of 20 ints
void printRows();

//prints monster type, name, health
void printMonster(SMonster monster);

//prints ads struct data and revenue of the day
void	printAdsData(SAdvertising myAds);

//asks user for 32bit hexadec int then prints individual colors
void	printColorPerChannelFromUserInput();

//takes in hexadec from user, then prints that to dec, might be broken.
void	printBinaryFromUserInput();

//asks user for input then prints years lived per year
void	printYearsPerLetterOfUsername();

//prints number of animal legs and its name
void	printNumberOfAnimalLegs(EAnimal animal1, std::string animalname);

//print alphabet a-z and for each letter the ASCII code
void	printAlphabetWithASCII();

//nested loops
void	printNestedLoop1();
void	printNestedLoop2();
void	printNestedLoop3();





//USER STRUCT RELATED FUNCTIONS



//generates a unique ID via a static local varaible
unsigned int GenerateId();

//writes data into the user struct 
void		 GenerateUserStructData(std::string name);




//end header guard
#endif