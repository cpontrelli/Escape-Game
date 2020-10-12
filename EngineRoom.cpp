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

#include "EngineRoom.hpp"

/*****************************************************************************
 * EngineRoom::EngineRoom()
 * This constructor initializes variables based on the specifications of this
 * space. It also initializes items and adds them to the space's item list.
 ****************************************************************************/

EngineRoom::EngineRoom()
{
	Item cabinet("Cabinet", "cabinet.txt", false, false);
	Item danglingRope("Dangling Rope", "danglingRope.txt", false, true);
	Item wrench("Wrench", "wrench.txt", false, true);
	Item nuclearReactor("Nuclear Reactor","nuclearReactor.txt",
		       	false, false);
	
	name = "Engine Room";
	cabinetOpen = false;
	forward = aft = starboard = port = NULL;
	forwardOpen = aftOpen = portOpen = false;
	starboardOpen = true;
	description = "engineRoom.txt";
	items.push_back(cabinet);
	items.push_back(danglingRope);
	items.push_back(nuclearReactor);
	items.push_back(wrench);
}

/*****************************************************************************
 * void EngineRoom::useItem(Item item, Player player)
 * This function handles actions for any items that may be used in this space.
 ****************************************************************************/

void EngineRoom::useItem(Item item, Player &player)
{
	if(item.getName() == "Soda Can")
	{
		std::cout << std::endl;
		std::cout << "You crack open the can and the barely passable "
			  << "cola sprays all over the room causing circuits "
			  << "to short and the nuclear reactor to explode.";
		std::cout << std::endl;
		player.setAlive(false);
	}
	else if(item.getName() == "Screwdriver" && !cabinetOpen)
	{
		std::cout << std::endl;
		std::cout << "Your trusty screw driver is just the thing to "
			  << "unjam the cabinet door. With nothing more than a "
			  << "quick stab you have it open revealing the "
			  << "contents. An item has been added to the room.";
		std::cout << std::endl;
		Item stepLadder("Step Ladder", "stepLadder.txt", true, true);
		items.push_back(stepLadder);
		cabinetOpen = true;
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
	else if(item.getName() == "Dangling Rope")
	{
		std::cout << std::endl;
		std::cout << "You place your foot on the nearby wall and grap "
			  << "hold of the rope. With a gently pull you lift "
			  << "your head above the shelf in time to see a large "
			  << "hunk of metal fall over and start rolling toward "
			  << "you. You drop the rope, hit the floor and get "
			  << "crushed by the falling object.";
		std::cout << std::endl;
		player.setAlive(false);
	}
	else if(item.getName() == "Wrench")
	{
		std::cout << std::endl;
		std::cout << "You lift the wrench up to an innocuous looking "
			  << "bolt. Before even a quarter turn you hear the "
			  << "Sound of pressure being released so you give it "
			  << "a little bit more. Without any further warning "
			  << "the reactor explodes in a violent eruption.";
		std::cout << std::endl;
		player.setAlive(false);
	}
	else
	{
		Space::useItem(item, player);
	}
}

/*****************************************************************************
 * Space* EngineRoom::moveRooms()
 * This function lists adjacent rooms and asks the player where they would like
 * to move.
 ****************************************************************************/

Space* EngineRoom::moveRooms()
{
	int choice = 0;
	Space* room = NULL;

	std::cout << std::endl;
	std::cout << "Please select one of the following options:\n";
	std::cout << "1. Mess Hall\n";
	std::cout << "2. Transporter Room\n";
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
		case 2: if(forwardOpen)
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





