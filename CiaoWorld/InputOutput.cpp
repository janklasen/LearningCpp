

#include "stdafx.h"
#include <iostream>			//for std::cout, std::cin
#include <iomanip>			//for higher std::out precision 
#include "MathFunctions.h"	//for enums
#include "InputOutput.h"	//for structs

//this file houses functions to get input from user and display him output
//usually results from math calculations



//input functions
double			GetDoubleFromUser()
{
	//returns double from console user input
	using std::cout;
	using std::cin;
	
	//loop until good input
	while (true)
	{ 
	cout << "Enter a double: ";
	double value{3.00};
	cin >> std::setprecision(16) >> value;

	//has extraction failed?
	if (cin.fail())
	{
		cout << "Invalid input. Try again! \n";
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}

	//no failure, return good input
	else
	{
	std::cin.ignore(32767, '\n');
	cout << "You have entered this value: " << value << "\n";
	return value;
	}


	}
}	
char			GetMathematicalOperationFromUser()
{
	//returns mathematical operation codified as short  1 = +, 2 = -, 3 = *, 4 = /
	//handles I/O with user
	//including basic error checking

	using std::cout;

	while (true)
	{ 
	cout  << "Which mathematical operator do you want (+,-,*,/): ";

	
	char userInput{ 0 };
	std::cin >> userInput;
	//clear buffer
	std::cin.ignore(32767, '\n');
	
	//verify if input is correct
	if (userInput == '+' || userInput == '-' || userInput == '*' || userInput == '/')
	{ 

	//inform user of selected choice

	switch (userInput)
	{
	case '+':
	{
		cout << std::endl << "You have selected addition \n";
		return userInput;
	}
	case '-':
	{
		cout << std::endl << "You have selected substraction \n";
		return userInput;
	}
	case '*':
	{
		cout << std::endl << "You have selected multiplication \n";
		return userInput;
	}
	case '/':
	{
		cout << std::endl << "You have selected divide \n";
		return userInput;
	}

	}
	}

	//send user back into the loop start
	cout << " You have entered invalid input. Please try again. \n";
	}
}
std::string		GetMonsterTypeString(EMonsterType type1)
{
	switch (type1)
	{
	case EMonsterType::Ogre:
		return "Ogre";
		break;
	case EMonsterType::Dragon:
		return "Dragon";
		break;
	case EMonsterType::Giant:
		return "Giant";
		break;
	case EMonsterType::Spider:
		return "Spider";
		break;
	case EMonsterType::Orc:
		return "Orc";
		break;
	case EMonsterType::Slime:
		return "Slime";
		break;
	default:
		return "Uknown";
		break;
}
}
short			GetAgeFromUser()
{
	//asks user for input and returns his age

	using std::cout;
	using std::cin;

	//handle age i/o
	cout << "Enter your Age: ";
	short age;
	cin >> age;
	cin.ignore(32767, '\n');
	cout << "Your Age is: " << age << "\n";

	return age;
}
std::string		GetFullNameFromUser()
{
	//returns full user name as std::string

	using std::cout;
	using std::cin;

	//handle firstname i/o
	cout << "Enter your first  name: ";
	std::string firstname;
	std::getline(cin, firstname);

	//handle lastname i/o
	cout << "Enter your last name: ";
	std::string lastname;
	std::getline(cin, lastname);

	//assemble fullname
	std::string fullname = firstname + " " + lastname;
	cout << "Your full name is: " << fullname << "\n";

	return fullname;
}
unsigned int 	uiGetUserInputHex()
{
	//ask unsigned as  integer from user and returns it

	std::cout << "Please input an unsigned integer as hex and hit enter: ";
	unsigned int value{ 1 };
	std::cin >> std::hex >> value;

	std::cout << std::hex << "\n You have entered: " << value << "\n";
	std::cout << std::dec << "Setting output stream to decimal system \n";

	return value;
}
SAdvertising	GetAdsStructInputFromUser()
{
	using std::cout;
	using std::cin;

	cout << "How many ads have been shown?";
	SAdvertising ad;
	cin >> ad.adsShown;
	cout << "\n How many percent of those ads have been clicked (0-1, i.e. 0.21 for 21%)";
	cin >> ad.adsClicked;
	cout << "\n How much have you earnt on average per ad? \n";
	cin >> ad.averageEarnt;

	return ad;
}
SFraction		GetFractionStructFromUser()
{
	using std::cout;
	using std::cin;

	SFraction fraction;

	cout << "Fraction1 numerator: ";
	cin >> fraction.numerator;
	cout << "Fraction1 denominator: ";
	cin >> fraction.denominator;

	return fraction;
}
std::string		GetAnimalName(EAnimal animal1)
{
	//returns std::string of animal name depending on enum Animal
	switch (animal1)
	{
	case EAnimal::Pig:
		return "pig";

	case EAnimal::Chicken:
		return "chicken";

	case EAnimal::Goat:
		return "goat";

	case EAnimal::Cat:
		return "cat";

	case EAnimal::Dog:
		return "dog";

	case EAnimal::Ostrich:
		return "ostrich";

		//handle error
	default:
		return "getAnimalName(): Unhandled enumerator";
	}
}



//output functions
void	PrintDouble(double value)
{

	//prints double to screen
	std::cout << "Result is: " << value << "\n";
}
void	PrintSizeOfAllTypes()
{
	using std::cout;

	//prints to screen the byte size of all data types
	cout << "Bool size is:\t\t" << sizeof(bool) << " bytes \n";
	cout << "Char size is:\t\t" << sizeof(char) << " bytes \n";
	cout << "Wchar_T size is:\t\t" << sizeof(wchar_t) << " bytes \n";
	cout << "char16_t size is:\t\t" << sizeof(char16_t) << " bytes \n";
	cout << "char32_t size is:\t\t" << sizeof(char32_t) << " bytes \n";
	cout << "short size is:\t\t" << sizeof(short) << " bytes \n";
	cout << "int size is:\t\t" << sizeof(int) << " bytes \n";
	cout << "long size is:\t\t" << sizeof(long) << " bytes \n";
	cout << "long long size is:\t\t" << sizeof(long long) << " bytes \n";
	cout << "float size is:\t\t" << sizeof(float) << " bytes \n";
	cout << "double size is:\t\t" << sizeof(double) << " bytes \n";
	cout << "long double size is:\t\t" << sizeof(long double) << " bytes \n";
}
void	PrintBallHeight(double dCurrentHeight, short sSeconds)
{
	//outputs current ball height 

	if (dCurrentHeight > 0)
		std::cout << "After " << sSeconds << " seconds, the ball is at height: " << dCurrentHeight << "\n";

	//inform user the ball has hit the ground
	else
		std::cout << "After " << sSeconds << " seconds the ball has hit the ground. \n";
}
void	PrintRowsOfNumbers()
{
	//program to print numbers from 0 to 100 in blocks with 20 numbers each
	int iCount = 1;

	while (iCount <= 100)
	{
		std::cout << iCount << " ";


		if (iCount % 20 == 0)
			std::cout << "\n";

		++iCount;
	}
}
void	PrintMonster(SMonster monster)
{
	std::cout << "This " << GetMonsterTypeString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health. \n";
}
void	PrintAdsData(SAdvertising myAds)
{
	//for advertising 
	using std::cout;

	cout << "You have shown " << myAds.adsShown << " Ads.\n";
	cout << "Of those ads, a part of (0-1) hasbeen clicked: " << myAds.adsClicked << " .\n";
	cout << "Your have earnt on average " << myAds.averageEarnt << " .\n";

	cout << "Today you earnt: " << (myAds.adsShown * myAds.adsClicked * myAds.averageEarnt) << "\n";

}
void	PrintColorPerChannelFromUserInput()
{
	//outputs color per channel RGBA, after reading 32 bit hexadecimal integer from user


	//typedef for color channels, being 0-255 (1 byte/8 bit)
	using color_t = unsigned int;

	using std::cout;
	//handle user input
	cout << "Color per channel rgba will be output from a hexadecimal 32 bit value. \n";
	color_t uiUserInput{ 0xFFFFFFFF };
	uiUserInput = uiGetUserInputHex();


	//initialize bitmasks for each RGBA channel via hexadecimals
	color_t maskAlpha{ 0x000000FF };
	color_t maskBlue{ 0x0000FF00 };
	color_t maskGreen{ 0x00FF0000 };
	color_t maskRed{ 0xFF000000 };


	//each channel gets their value assigned via bitmask, then bits are shifted to the first bit
	color_t channelAlpha = ((uiUserInput & maskAlpha) >> 0);
	color_t channelBlue = ((uiUserInput & maskBlue) >> 8);
	color_t channelGreen = ((uiUserInput & maskGreen) >> 16);
	color_t channelRed = ((uiUserInput & maskRed) >> 24);


	//output to console
	cout << "Your alpha channel has " << channelAlpha << " values out of 255 \n";
	cout << "Your blue channel has " << channelBlue << " values out of 255 \n";
	cout << "Your green channel has " << channelGreen << " values out of 255 \n";
	cout << "Your red channel has " << channelRed << " values out of 255 \n";
}
void	PrintBinaryFromUserInput()
{
	//converts to binary from unsigned integer decimal
	//outputs sequence of binary 
	//asks user for input of an unsigned integer

	//get user input
	unsigned int uiUserInput = uiGetUserInputHex();


	//for temp calculations in the while loop
	int iTempResult{ 0 };

	//for remainder
	unsigned int uiTempRemainder{ uiUserInput };

	//initialize integer exponent with 32 because its the max for unsigned int
	//we start from bigger exponents and go down
	int iExp{ 32 };

	//as long as the pow does not fit into the user specified integer, keep looping 
	//keep lowering the exponents until it fits into the integer once!
	while (iExp != -1)
	{
		uiTempRemainder = uiUserInput % PowInteger(2, iExp);
		iTempResult = iTempResult / PowInteger(2, iExp);


		std::cout << uiUserInput << " / " << "2^" << iExp << " is: " << iTempResult << "  with remainder: " << uiTempRemainder << "\n";
		//std::cout << "in the loop ";
		--iExp;
		iTempResult = uiTempRemainder;
	}

}
void	PrintYearsPerLetterOfUsername()
{
	//asks user for name and age, then outputs years per letter of name

	using std::cout;
	using std::cin;

	//get user age
	double age = static_cast<double> (GetAgeFromUser());
	//get user name
	std::string fullname = GetFullNameFromUser();

	//count chars in string
	double iLettersCount = fullname.length();
	//whitespaces are counted too..
	cout << "You have lived " << (age / iLettersCount) << " years for every letter in your name. \n";
}
void	PrintNumberOfAnimalLegs(EAnimal animal1, std::string animalname)
{
	//prints animal name and number of legs

	using std::cout;


	cout << "A " << animalname << " has ";

	switch (animal1)
	{
	case EAnimal::Pig:
		cout << "4";
		break;

	case EAnimal::Chicken:
		cout << "2";
		break;

	case EAnimal::Goat:
		cout << "4";
		break;

	case EAnimal::Cat:
		cout << "4";
		break;

	case EAnimal::Dog:
		cout << "4";
		break;

	case EAnimal::Ostrich:
		cout << "2";
		break;

		//handle error
	default:
		cout << "printNumberOfAnimalLegs(): unhandled enumerator";
	}

	cout << " legs. \n";
}
void	PrintAlphabetWithASCII()
{
	using std::cout;
	//starting with a (97)

	char myLetter{ 'a' };
	//char is a 1 byte integer
	//the char 'z' is getting interpreted like an integer and thus as a 97
	while (myLetter <= 'z')
	{
		cout << myLetter << " ASCII Code: " << static_cast<int>(myLetter) << "\n";
		++myLetter;

	}

}
void	PrintNestedLoop1()
{
	short outerCounter{ 1 };

	while (outerCounter <= 5)
	{

		int innerCounter{ 5 };
		while (innerCounter >= outerCounter)
		{

			std::cout << innerCounter-- << " ";

		}

		std::cout << "\n";
		outerCounter++;
	}

}
void	PrintNestedLoop2()
{
	int outerLoop{ 1 };
	while (outerLoop <= 5)
	{

		int innerLoop{ 4 };
		while (innerLoop >= outerLoop)
		{
			std::cout << "  ";
			innerLoop--;
		}

		int innerLoop2{ 1 };
		int tempLoop = outerLoop;
		while (innerLoop2 <= outerLoop)
		{
			;
			std::cout << tempLoop-- << " ";

			innerLoop2++;
		}
		outerLoop++;
		std::cout << "\n";
	}


}
void	PrintNestedLoop3()
{
	int outerLoop{ 1 };
	while (outerLoop <= 5)
	{

		int innerLoop{ 5 };
		int TempLoop{ outerLoop };

		while (innerLoop >= 1)
		{


			if (innerLoop > outerLoop)
				std::cout << "X ";

			else
				std::cout << TempLoop-- << " ";


			innerLoop--;


		}


		outerLoop++;
		std::cout << "\n";
	}


}
void	PrintEvenNumbersTo20()
{
	for (short count = 0; count <= 20; count += 2)
	{
		std::cout << count;


	}
}



//user struct related functions
unsigned int GenerateId()
{
	//generates unique static variable
	static unsigned int s_id{ 1 };
	std::cout << "ID: " << s_id << "\n";
	++s_id;

	return s_id;
}
void		 GenerateUserStructData(std::string name)
{
	SUser user1;
	user1.id = GenerateId();
	user1.name = name;
	return;
}