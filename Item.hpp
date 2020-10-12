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
#include "readFile.hpp"
#include <fstream>
#include <iostream>
#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
	private:
		std::string name;
		std::string description;
		bool canTake;
		bool canUse;

	public:
		Item(std::string name, std::string description, bool canTake,
				bool canUse);
		void describe();
		std::string getName();
		bool getCanTake();
		bool getCanUse();
		void setCanTake(bool canTake);
		void setCanUse(bool canUse);
		bool operator==(const Item &right);
};

#endif
