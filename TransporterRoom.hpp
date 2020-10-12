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
#include "Item.hpp"
#include "Space.hpp"
#include "getInteger.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>

#ifndef TRANSPORTERROOM_HPP
#define TRANSPORTERROOM_HPP


class TransporterRoom : public Space
{
	public:
		TransporterRoom();
		virtual void useItem(Item item, Player &player);
		virtual Space* moveRooms();
};

#endif
