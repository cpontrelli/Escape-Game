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

#include "MessHall.hpp"

/*****************************************************************************
 * MessHall::MessHall()
 * This constructor initializes variables based on the specifications of this
 * space. It also initializes items and adds them to the space's item list.
 ****************************************************************************/

MessHall::MessHall()
{
	Item mop("Mop", "mop.txt", false, true);
	Item blaster("Blaster", "blaster.txt", true, true);
	Item sodaCan("Soda Can", "sodaCan.txt", true, true);
	Item spatula("Spatula", "spatula.txt", true, true);
	
	name = "Mess Hall";
	foundKey = false;
	forward = port = aft = starboard = NULL;
	forwardOpen = starboardOpen = portOpen = false;
	aftOpen = true;
	description = "messHall.txt";
	items.push_back(mop);
	items.push_back(blaster);
	items.push_back(sodaCan);
	items.push_back(spatula);
}

/*****************************************************************************
 * void MessHall::MessHall(Item item, Player player)
 * This function handles actions for any items that may be used in this space.
 ****************************************************************************/

void MessHall::useItem(Item item, Player &player)
{
	if(item.getName() == "Mop" && !foundKey)
	{
		std::cout << std::endl;
		std::cout << "You tactfully slide your mop under a nearby table"
		          << " and hear the sound of metal slide across the "
			  << "floor. A new item has been added to the room.";
		std::cout << std::endl;
		Item engineRoomKey("Engine Room Key", "engineRoomKey.txt",
				true, true);
		items.push_back(engineRoomKey);
		foundKey = true;
	}
	else if(item.getName() == "Blaster")
	{
		std::cout << std::endl;
		std::cout << "Thinking you'd surely be able to blast through "
			  << "these doors you carefully take aim and fire. "
			  << "The laser ricochets around the room and blasts "
			  << "straight through your skull. You really should "
			  << "have paid more attention during orientation.";
		std::cout << std::endl;
		player.setAlive(false);
	}
	else if(item.getName() == "Spatula" && !forwardOpen)
	{
		std::cout << std::endl;
		std::cout << "You've had to shimmy thousands of locks in your "
			  << "day and this spatula is exactly the tool to do "
			  << "it. You unlock the door to the sick bay.";
		std::cout << std::endl;
		forwardOpen = true;
	}
	else if(item.getName() == "Engine Room Key" && !portOpen)
	{
		std::cout << std::endl;
		std::cout << "You used the key to open the door.";
		std::cout << std::endl;
		portOpen = true;
	}
	else
	{
		Space::useItem(item, player);
	}
}

/*****************************************************************************
 * Space* MessHall::moveRooms()
 * This function lists adjacent rooms and asks the player where they would like
 * to move.
 ****************************************************************************/

Space* MessHall::moveRooms()
{
	int choice = 0;
	Space* room = NULL;

	std::cout << std::endl;
	std::cout << "Please select one of the following options:\n";
	std::cout << "1. Sick Bay\n";
	std::cout << "2. Engine Room\n";
	std::cout << "3. Supply Closet\n";
	std::cout << "4. Cancel\n";
	choice = getInteger(1,4);

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
			break;
		case 2: if(portOpen)
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
		case 3: if(aftOpen)
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


