

#include "stdafx.h"
#include <iostream>			//for std::cout, std::cin
#include <iomanip>			//for higher std::out precision 
#include "MathFunctions.h"	//for enums
#include "InputOutput.h"	//for structs

//this file houses functions to get input from user and display him output
//usually results from math calculations



//input functions
double			getDoubleFromUser()
{
	using std::cout;
	using std::cin;
	//returns double from console user input
	
	cout << "Enter a number: ";

	//following text is for reference only, already fixed, see bottom comments
	//the following std::cin functions cease to work properly -Why?
	//it seems like std::cin will be skipped the moment you input a letter instead of anumber
	//on 2nd call the std::cin function wont be executed either
	//the std::cin in the other function will be skipped as well
	//conclusion: Just by inputting an "illegal" value into a function once, it gets "destroyed/disabled" permanently
	// Reason: "By giving cin bad input, cin gets in the fail state and stops prompting the command line for input causing the loop to free run."
	//Solution: I need to 1) check if the function returns a failstate, 2) clear the function of fail state 3) discard any "bad" characters 
	//4) ask for integer "valid" input

	double value{3.00};
	
	//set io stream precision/length to 16 digits and get user value
	cin >> std::setprecision(16) >> value;
	
	cout << "\n" << std::setprecision(16) << "Value is: " << value << "\n";

	//clears fail state of std::cin in case an illegal character was entered (i.e. a letter instead of a double)
	cin.clear();	
	//discard unprocessed characters. Otherwise, the bad character 
	//is still there and you still get infinite loops. 
	//You can simply can std::cin.ignore() to achieve this				
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	

	return value;														
}	
Mathoperation	getMathematicalOperationFromUser()
{
	//returns mathematical operation codified as short  1 = +, 2 = -, 3 = *, 4 = /
	//handles I/O with user
	//including basic error checking

	using std::cout;

	cout << std::endl << "Which mathematical operator do you want(1 = +, 2 = -, 3 = *, 4 = /): " << std::endl;

	
	short sUserInput{ 1 };
	std::cin >> sUserInput;
	Mathoperation operationId{static_cast<Mathoperation>(sUserInput)};

	//inform user of selected choice
	
	switch (operationId)
	{
	case Mathoperation::ADD:
	{
		cout << std::endl << "You have selected 1 - addition \n";
		return operationId;
	}
	case Mathoperation::SUBSTRACT:
	{
		cout << std::endl << "You have selected 2 - substraction \n";
		return operationId;
	}
	case Mathoperation::MULTIPLY:
	{
		cout << std::endl << "You have selected 3 - multiplication \n";
		return operationId;
	}
	case Mathoperation::DIVIDE:
	{
		cout << std::endl << "You have selected 4 - divide \n";
		return operationId;
	}
	default:
	{	//handle incorrect input
		cout << "You have entered: " << static_cast<short>(operationId);
		cout << "\n Error: Only 1,2,3 and 4 are valid input. Fallback to Addition(1) \n";
		//on incorrect user input: return 1
		return Mathoperation::ADD;
	}
	}

}
std::string		getMonsterTypeString(MonsterType type1)
{
	switch (type1)
	{
	case MonsterType::OGRE:
		return "Ogre";
		break;
	case MonsterType::DRAGON:
		return "Dragon";
		break;
	case MonsterType::GIANT:
		return "Giant";
		break;
	case MonsterType::SPIDER:
		return "Spider";
		break;
	case MonsterType::ORC:
		return "Orc";
		break;
	case MonsterType::SLIME:
		return "Slime";
		break;
	default:
		return "Uknown";
		break;
}
}
short			getUserAge()
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
std::string		getUserName()
{
	//returns full user name as std::string

	using std::cout;
	using std::cin;

	//handle firstname i/o
	cout << "Enter your first  name: ";
	std::string firstname;
	std::getline(cin, firstname);
	cout << "Your first name is: " << firstname << "\n";

	//handle lastname i/o
	cout << "Enter your last name: ";
	std::string lastname;
	std::getline(cin, lastname);
	cout << "Your lastname is: " << lastname << "\n";

	//assemble fullname
	std::string fullname = firstname + " " + lastname;
	cout << "Your full name is: " << fullname << "\n";

	return fullname;
}
int 			uiGetUserInputHex()
{
	//ask unsigned as  integer from user and returns it

	std::cout << "Please input an unsigned integer as hex and hit enter: ";
	unsigned int value{ 1 };
	std::cin >> std::hex >> value;

	std::cout << std::hex << "\n You have entered: " << value << "\n";
	std::cout << std::dec << "Setting output stream to decimal system \n";

	return value;
}
Advertising		getAdsStructInputFromUser()
{
	using std::cout;
	using std::cin;

	cout << "How many ads have been shown?";
	Advertising ad;
	cin >> ad.adsShown;
	cout << "\n How many percent of those ads have been clicked (0-1, i.e. 0.21 for 21%)";
	cin >> ad.adsClicked;
	cout << "\n How much have you earnt on average per ad? \n";
	cin >> ad.averageEarnt;

	return ad;
}
Fraction		getFractionStructFromUser()
{
	using std::cout;
	using std::cin;

	Fraction fraction;

	cout << "Fraction1 numerator: ";
	cin >> fraction.numerator;
	cout << "Fraction1 denominator: ";
	cin >> fraction.denominator;

	return fraction;
}
std::string		getAnimalName(Animal animal1)
{
	//returns std::string of animal name depending on enum Animal
	switch (animal1)
	{
	case Animal::PIG:
		return "pig";

	case Animal::CHICKEN:
		return "chicken";

	case Animal::GOAT:
		return "goat";

	case Animal::CAT:
		return "cat";

	case Animal::DOG:
		return "dog";

	case Animal::OSTRICH:
		return "ostrich";

		//handle error
	default:
		return "getAnimalName(): Unhandled enumerator";
	}
}



//output functions
void	printDouble(double value)
{

	//prints double to screen
	std::cout << "Result is: " << value << "\n";
}
void	printSizeOfAllTypes()
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
void	printBallHeight(double dCurrentHeight, short sSeconds)
{
	//outputs current ball height 

	if (dCurrentHeight > 0)
		std::cout << "After " << sSeconds << " seconds, the ball is at height: " << dCurrentHeight << "\n";

	//inform user the ball has hit the ground
	else
		std::cout << "After " << sSeconds << " seconds the ball has hit the ground. \n";
}
void	printRows()
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
void	printMonster(Monster monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health. \n";
}
void	printAdsData(Advertising myAds)
{
	//for advertising 
	using std::cout;

	cout << "You have shown " << myAds.adsShown << " Ads.\n";
	cout << "Of those ads, a part of (0-1) hasbeen clicked: " << myAds.adsClicked << " .\n";
	cout << "Your have earnt on average " << myAds.averageEarnt << " .\n";

	cout << "Today you earnt: " << (myAds.adsShown * myAds.adsClicked * myAds.averageEarnt) << "\n";

}
void	printColorPerChannelFromUserInput()
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
void	printBinaryFromUserInput()
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
		uiTempRemainder = uiUserInput % iPow(2, iExp);
		iTempResult = iTempResult / iPow(2, iExp);


		std::cout << uiUserInput << " / " << "2^" << iExp << " is: " << iTempResult << "  with remainder: " << uiTempRemainder << "\n";
		//std::cout << "in the loop ";
		--iExp;
		iTempResult = uiTempRemainder;
	}

}
void	printYearsPerLetterOfUsername()
{
	//asks user for name and age, then outputs years per letter of name

	using std::cout;
	using std::cin;

	//get user age
	double age = static_cast<double> (getUserAge());
	//get user name
	std::string fullname = getUserName();

	//count chars in string
	double iLettersCount = fullname.length();
	//whitespaces are counted too..
	cout << "You have lived " << (age / iLettersCount) << " years for every letter in your name. \n";
}
void	printNumberOfAnimalLegs(Animal animal1, std::string animalname)
{
	//prints animal name and number of legs

	using std::cout;


	cout << "A " << animalname << " has ";

	switch (animal1)
	{
	case Animal::PIG:
		cout << "4";
		break;

	case Animal::CHICKEN:
		cout << "2";
		break;

	case Animal::GOAT:
		cout << "4";
		break;

	case Animal::CAT:
		cout << "4";
		break;

	case Animal::DOG:
		cout << "4";
		break;

	case Animal::OSTRICH:
		cout << "2";
		break;

		//handle error
	default:
		cout << "printNumberOfAnimalLegs(): unhandled enumerator";
	}

	cout << " legs. \n";
}
void	printAlphabetWithASCII()
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
void	printNestedLoop1()
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
void	printNestedLoop2()
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
void	printNestedLoop3()
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



//user struct related functions
unsigned int generateId()
{
	//generates unique static variable
	static unsigned int id{ 1 };
	std::cout << "ID: " << id << "\n";
	id++;

	return id;
}
void		 generateUserStructData(std::string name)
{
	User user1;
	user1.id = generateId();
	user1.name = name;
	return;
}