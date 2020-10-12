/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-2-2019
 * Description: This is the main function for an escape room type game you
 *              find yourself in the supply closet of an abandoned ship and
 *              have to find your way off. Make use of any items that you
 *              find to unlock doors and teleport off the ship. Beware that
 *              using some items may kill you.
 ****************************************************************************/

#include "Game.hpp"
#include "menu.hpp"
#include "readFile.hpp"
#include <iostream>

int main()
{
	int choice = 0;

	do
	{
		Game game;
		
		choice = menu("menuOptions.txt");

		switch(choice)
		{
			case 1: readFile("./instructions/instructions.txt");
				break;
			case 2: game.start();
		}

	} while (choice != 0 && choice != 3);
}
