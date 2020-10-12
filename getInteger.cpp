/****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 9-29-2019
 * Description: This function validates that a user's input is an integer
 *              it returns a valid integer.
 ***************************************************************************/

#include "getInteger.hpp"

/*****************************************************************************
 * Description: This function accepts a minimum and maximum value and returns
 * an integer within that range (inclusive of the min and max values). If
 * no min or max are passed in, then it defaults to the smallest and largest
 * numbers that an int data type can hold.
 ****************************************************************************/

int getInteger(int min, int max)
{
	std::string input; //stores user input
	std::string firstChar = "-1234567890"; //allowable first characters
	std::string nextChar = "1234567890"; //allowable remaining characters
	std::istringstream istr; //stream to convert input to int
	int returnInt = 100000001; //stores integer to return

	while(true)
	{
		bool valid = true;

		std::getline(std::cin, input);

		//check to see if each character is a digit
		//'-' is allowed for first character
		for(int pos = 0; pos < input.length(); pos++)
		{
			if(pos == 0)
				if(firstChar.find(input[pos]) == 
						std::string::npos)
					valid = false;

			if(pos > 0)
				if(nextChar.find(input[pos]) == 
						std::string::npos)
					valid = false;
		}
		
		//return if integer is valid and between min and max
		if(valid)
		{
			istr.str(input);
			istr >> returnInt;

			if(returnInt >= min && returnInt <= max)
				return returnInt;
			else
				istr.clear();
		}

		//if not valid prompt for new input
		std::cout << "Invalid input. Please try again." << std::endl;
	}

}

