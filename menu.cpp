/****************************************************************************
 * Name: Charlie Pontrelli
 * Date 9-30-2019
 * Description: This menu function displays a menu, obtains and validates a
 *              user's input and returns the user's choice. The function
 *              accepts a filename and the menu choices are read in from 
 *              that file.
 ***************************************************************************/

#include "menu.hpp"

/****************************************************************************
 * Description: This function accepts a string and attempts to open a file
 * by that name. It treats the first line in that file as the menu title, the
 * second line as the directive, and the remaining lines as the menu options.
 * The function returns the user's choice after validating the input.
 ****************************************************************************/

int menu(std::string fileName)
{
	std::ifstream menuOptions;
	std::string heading, directive, option; //stores data from file
	int numOptions = 0; //counts the number of menu options read in

	//open file and check for success
	menuOptions.open(fileName.c_str());

	if(menuOptions)
	{
		//get heading and directive
		std::getline(menuOptions, heading);
		std::getline(menuOptions, directive);

		//Print menu heading
		std::cout << std::endl << heading << "\n\n";
		//print menu directive
		std::cout << directive << '\n';

		//print menu options
		while(std::getline(menuOptions, option))
		{
			numOptions++;
			std::cout << numOptions << ". " << option << std::endl;
		}

		menuOptions.close();
	}
	else
	{
		std::cout << "Error finding menu choices\n";
		return 0;
	}

	//Validate user choice with getInteger function and return result
	return getInteger(1, numOptions);
}
