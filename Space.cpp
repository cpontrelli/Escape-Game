/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-2-2019
 * Description: This is an abstract space class for creating space objects to
 *              be used in an escape room type of game. It contains pointers
 *              to the adjacent spaces, boolean values to check if the adjacent
 *              rooms are open, a name, description, and a list of items.
 *              It has functions to get and set the member variables, add and
 *              remove items, and descibe the room. There is a virtual function
 *              useItem which will be defined in the derived
 *              class objects to the specifications of the derived classes.
 *****************************************************************************/

#include "Space.hpp"

/******************************************************************************
 * Space::~Space()
 * Pure virtual destructor is just here so that Space will be an abstract class
 *****************************************************************************/

Space::~Space(){}

/******************************************************************************
 * void Space::describe()
 * This function reads in the space's description from a file and prints to the
 * screen.
 *****************************************************************************/

void Space::describe()
{
	readFile("./rooms/" + description);
}

/******************************************************************************
 * void Space::useItem(Item &item, Player &player)
 * If the derived classes have a use for the item passed in, it will be defined
 * in the derived class useItem function. This function handles items that
 * cannot be used in the current room.
 *****************************************************************************/

void Space::useItem(Item item, Player &player)
{
	std::cout << std::endl;
	std::cout << "That can't be used in here.";
	std::cout << std::endl;
}

/******************************************************************************
 * Space* Space::moveRooms()
 * This is a virtual function that will be overridden by the derived classes.
 *****************************************************************************/

Space* Space::moveRooms(){}

/******************************************************************************
 * void Space::addItem(Item item)
 * This function accepts an item and adds it to the item list. It switches
 * canTake to true before adding it so that the user can pick it back up if
 * wanted.
 *****************************************************************************/

void Space::addItem(Item item)
{
	item.setCanTake(true);
	items.push_back(item);
}

/******************************************************************************
 * void Space::removeItem(Item item)
 * This function searches for the item passed in and removes it from the item
 * list.
 *****************************************************************************/

void Space::removeItem(Item item)
{
	std::list<Item>::iterator iter;

	if(!items.empty())
	{
		iter = std::find(items.begin(), items.end(), item);

		if(iter != items.end())
		{
			items.erase(iter);
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Cannot find " << item.getName()
				  << " to remove.";
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		std::cout << "No items in " << name;
		std::cout << std::endl;
	}
}

/******************************************************************************
 * These functions return the Space's name and list of items.
 *****************************************************************************/

std::list<Item> Space::getItems()
{
	return items;
}

std::string Space::getName()
{
	return name;
}

/******************************************************************************
 * These functions set pointers to the adjacent rooms.
 *****************************************************************************/

void Space::setForward(Space* space)
{
	forward = space;
}

void Space::setAft(Space* space)
{
	aft = space;
}

void Space::setStarboard(Space* space)
{
	starboard = space;
}

void Space::setPort(Space* space)
{
	port = space;
}

/*****************************************************************************
 * These functions return pointers to the adjacent rooms.
 *****************************************************************************/

Space* Space::getForward()
{
	return forward;
}

Space* Space::getAft()
{
	return aft;
}

Space* Space::getStarboard()
{
	return starboard;
}

Space* Space::getPort()
{
	return port;
}
