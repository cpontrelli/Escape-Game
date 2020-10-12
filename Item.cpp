/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-2-2019
 * Description: This item class is used to create item objects used in an
 *              escape game. It has members to store the item's name,
 *              description, and boolean values noting wheter the item can
 *              be taken or used. In addiiton to a constructor, it has
 *              functions to describe the object, get the name and booleans,
 *              and set the name and booleans. It also contains an ==  operater
 *              overloader so that items can be compared by thier names.
 *****************************************************************************/

#include "Item.hpp"

/******************************************************************************
 * Item::Item(std::string name, std::string description, bool canTake, 
 * bool canUse)
 * This constructor initializes the member variables based on what was passed.
 *****************************************************************************/

Item::Item(std::string name, std::string description, bool canTake, bool canUse)
{
	this->name = name;
	this->description = description;
	this->canTake = canTake;
	this->canUse = canUse;
}

/******************************************************************************
 * void Item::describe()
 * This function reads in the item's description from a file and prints to the
 * screen.
 *****************************************************************************/

void Item::describe()
{
	readFile("./items/" + description);
}

/******************************************************************************
 * bool Item::operator==(const Item &right)
 * This operator overloader returns true if the name of the item passed in is
 * the same as the name of this item.
 *****************************************************************************/

bool Item::operator==(const Item &right)
{
	return this->name == right.name;
}

/******************************************************************************
 * These finctions return the item's member variables.
 *****************************************************************************/

std::string Item::getName()
{
	return name;
}

bool Item::getCanTake()
{
	return canTake;
}

bool Item::getCanUse()
{
	return canUse;
}

/******************************************************************************
 * These functions can change the item's boolean values canTake and canUse.
 ****************************************************************************/

void Item::setCanTake(bool canTake)
{
	this->canTake = canTake;
}

void Item::setCanUse(bool canUse)
{
	this->canUse = canUse;
}
