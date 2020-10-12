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

#include "TransporterRoom.hpp"

/*****************************************************************************
 * TransporterRoom::TransporterRoom()
 * This constructor initializes variables based on the specifications of this
 * space. It also initializes items and adds them to the space's item list.
 ****************************************************************************/

TransporterRoom::TransporterRoom()
{
	Item cobweb("Cobweb", "cobweb.txt", false, false);
	Item magazine("Magazine", "magazine.txt", false, true);
	Item controlPanel("Control Panel", "trControlPanel.txt", false, false);
	
	name = "Transporter Room";
	forward = aft = starboard = port = NULL;
	forwardOpen = aftOpen = portOpen = false;
	starboardOpen = true;
	description = "transporterRoom.txt";
	items.push_back(cobweb);
	items.push_back(magazine);
	items.push_back(controlPanel);
}

/*****************************************************************************
 * void TransporterRoom::useItem(Item item, Player player)
 * This function handles actions for any items that may be used in this space.
 ****************************************************************************/

void TransporterRoom::useItem(Item item, Player &player)
{
	if(item.getName() == "Magazine")
	{
		std::cout << std::endl;
		std::cout << "You pick up the magazine and plop down on the "
			  << "couch to read an article about the dangers of "
			  << "global literacy" << std::endl;
		std::cout << "Well that was a waste of time. 2 minutes have "
			  << "have been taken off the clock.";
		std::cout << std::endl;
		Game::maxTime -= 120;
	}
	else if(item.getName() == "Step Ladder")
	{
		std::cout << std::endl;
		std::cout << "You set up the ladder underneath the web and "
			  << "step up to kill the spider. While loosening your "
			  << "shoe you stumble backwards, slam your head on "
			  << "the control panel and roll onto the platform. "
			  << "The last thing you see before you black out is a "
			  << "flash of light.";
		std::cout << std::endl;
		Game::currentRoom = forward;
	}
	else
	{
		Space::useItem(item, player);
	}
}

/*****************************************************************************
 * Space* TransporterRoom::moveRooms()
 * This function lists adjacent rooms and asks the player where they would like
 * to move.
 ****************************************************************************/

Space* TransporterRoom::moveRooms()
{
	int choice = 0;
	Space* room = NULL;

	std::cout << std::endl;
	std::cout << "Please select one of the following options:\n";
	std::cout << "1. Sick Bay\n";
	std::cout << "2. Engine Room\n";
	std::cout << "3. Cancel\n";
	choice = getInteger(1,3);

	switch(choice)
	{
		case 1: if(starboardOpen)
			{
				room = starboard;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "The door is locked.";
				std::cout << std::endl;
			}
			break;
		case 2: if(aftOpen)
			{
				room = aft;
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
