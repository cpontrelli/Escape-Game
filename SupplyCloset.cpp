/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-7-2019
 * Description: This class is derived from the space class. It has s
 * 		constructor to set member variables according to it's
 * 		specifications and to initialize the items found in this space.
 * 		It has functions to handle any items that may be used in this
 * 		space that have special actions. It also has a function to
 * 		move to an adjacent space.
 ****************************************************************************/

#include "SupplyCloset.hpp"

/*****************************************************************************
 * SupplyCLoset::SupplyCloset()
 * This constructor initializes variables based on the specifications of this
 * space. It also initializes items and adds them to the space's item list.
 ****************************************************************************/

SupplyCloset::SupplyCloset()
{
	Item screwDriver("Screwdriver", "screwdriver.txt", true, true);
	Item cleaningSpray("Cleaning Spray", "cleaningSpray.txt", true, true);
	Item booze("Booze", "booze.txt", false, false);
	
	name = "Supply Closet";
	forward = aft = starboard = port = NULL;
	forwardOpen = aftOpen = starboardOpen = portOpen = false;
	description = "supplyCloset.txt";
	items.push_back(screwDriver);
	items.push_back(cleaningSpray);
	items.push_back(booze);
}

/*****************************************************************************
 * void SupplyCloset::useItem(Item item, Player player)
 * This function handles actions for any items that may be used in this space.
 ****************************************************************************/

void SupplyCloset::useItem(Item item, Player &player)
{
	if(item.getName() == "Key Ring" && !forwardOpen)
	{
		forwardOpen = true;
		std::cout << std::endl;
		std::cout << "You unlocked the door.";
		std::cout << std::endl;
	}
	else
	{
		Space::useItem(item, player);
	}
}

/*****************************************************************************
 * Space* SupplyCloset::moveRooms()
 * This function lists adjacent rooms and asks the player where they would like
 * to move.
 ****************************************************************************/

Space* SupplyCloset::moveRooms()
{
	int choice = 0;
	Space* room = NULL;

	std::cout << std::endl;
	std::cout << "Please select one of the following options:\n";
	std::cout << "1. Mess Hall\n";
	std::cout << "2. Cancel\n";
	choice = getInteger(1,2);

	switch(choice)
	{
		case 1: if(forwardOpen)
			{
				room = forward;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "The door is locked.";
				std::cout << std::endl;
			}
	}

	return room;
}





