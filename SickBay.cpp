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

#include "SickBay.hpp"

/*****************************************************************************
 * SickBay::SickBay()
 * This constructor initializes variables based on the specifications of this
 * space. It also initializes items and adds them to the space's item list.
 ****************************************************************************/

SickBay::SickBay()
{
	Item controlPanel("Control Panel", "controlPanel.txt", false, false);
	Item bandages("Bandages", "bandages.txt", true, true);
	Item surgicalEquipment("Surgical Equipment", "surgicalEquipment.txt",
		       	true, true);
	
	name = "Sick Bay";
	forward = aft = starboard = port = NULL;
	forwardOpen = starboardOpen = portOpen = false;
	aftOpen = true;
	description = "sickBay.txt";
	items.push_back(controlPanel);
	items.push_back(bandages);
	items.push_back(surgicalEquipment);
}

/*****************************************************************************
 * void SickBay::useItem(Item item, Player player)
 * This function handles actions for any items that may be used in this space.
 ****************************************************************************/

void SickBay::useItem(Item item, Player &player)
{
	if(item.getName() == "Cleaning Spray" && !portOpen)
	{
		portOpen = true;
		std::cout << std::endl;
		std::cout << "You spray down the disgusting control panel and "
			  << "start wiping. To your surprise and relief the "
			  << "door to the transporter room slides open.";
		std::cout << std::endl;
	}
	else if(item.getName() == "Blaster")
	{
		std::cout << std::endl;
		std::cout << "Thinking you'd surely be able to blast through "
			  << "the door you carefully take aim and fire. "
			  << "The laser ricochets around the room and blasts "
			  << "straight through your skull. You really should "
			  << "have paid more attention during orientation.";
		std::cout << std::endl;
		player.setAlive(false);
	}
	else
	{
		Space::useItem(item, player);
	}
}

/*****************************************************************************
 * Space* SickBay::moveRooms()
 * This function lists adjacent rooms and asks the player where they would like
 * to move.
 ****************************************************************************/

Space* SickBay::moveRooms()
{
	int choice = 0;
	Space* room = NULL;

	std::cout << std::endl;
	std::cout << "Please select one of the following options:\n";
	std::cout << "1. Transporter Room\n";
	std::cout << "2. Mess Hall\n";
	std::cout << "3. Cancel\n";
	choice = getInteger(1,3);

	switch(choice)
	{
		case 1: if(portOpen)
			{
				room = port;
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





