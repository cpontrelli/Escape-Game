/******************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-8-2019
 * Description:
 * This function reads in a description from a file and prints to the
 * screen.
 *****************************************************************************/

#include "readFile.hpp"

/******************************************************************************
 * This function accepts a filename containing paragrahps of text. It loops
 * through the paragraphs and prints them adding a new line in between each
 * paragraph.
 *****************************************************************************/

void readFile(std::string fileName)
{
	std::ifstream file;
	std::string output;
	file.open(fileName.c_str());
	if(file)
	{
		while(std::getline(file, output))
		{
			std::cout << std::endl;
			std::cout << output;
			std::cout << std::endl;
		}

		file.close();
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Cannot open file " << fileName;
		std::cout <<std::endl;
	}
}
