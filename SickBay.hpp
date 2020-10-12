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
#include "Space.hpp"
#include "Item.hpp"
#include "getInteger.hpp"
#include "Player.hpp"
#include <iostream>

#ifndef SICKBAY_HPP
#define SICKBAY_HPP

class SickBay : public Space
{
	public:
		SickBay();
		virtual void useItem(Item item, Player &player);
		virtual Space* moveRooms();
};

#endif
