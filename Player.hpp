/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-3-2019
 * Description: This class is used to create player objects in an escape room
 *              style game. It contains a boolean value to see if the player
 *              is alive, a list of inventory items, and a maximum carrying
 *              capacity. It has a constructor, functions to add or remove
 *              items from inventory, and get and set members.
 *****************************************************************************/
#include "Item.hpp"
#include "getInteger.hpp"
#include <list>
#include <algorithm>
#include <iostream>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	private:
		bool alive;
		int maxInventory;
		std::list<Item> inventory;

	public:
		Player(int maxInventory = 6);
		bool addItem(Item item);
		Item removeItem();
		std::list<Item> getInventory();
		bool getAlive();
		void setAlive(bool alive);
};

#endif

