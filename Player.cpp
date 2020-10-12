/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-3-2019
 * Description: This class is used to create player objects in an escape room
 *              style game. It contains a boolean value to see if the player
 *              is alive, a list of inventory items, and a maximum carrying
 *              capacity. It has a constructor, functions to add or remove
 *              items from inventory, and get and set members.
 *****************************************************************************/

#include "Player.hpp"

/******************************************************************************
 * Player::Player()
 * Sets the the initial members and adds the initial inventory. The max
 * inventory can be set by the user and defaults to 6.
 *****************************************************************************/

Player::Player(int maxInventory)
{
	Item keyRing("Key Ring", "keyRing.txt", false, true);

	this->maxInventory = maxInventory;
	alive = true;
	inventory.push_back(keyRing);
}

/******************************************************************************
 * bool addItem(Item item)
 * This function accepts an item and adds it to inventory if inventory is not
 * at max capacity. If the item is added the function returns true otherwise
 * it returns false.
 *****************************************************************************/

bool Player::addItem(Item item)
{
	if(inventory.size() < maxInventory)
	{
		item.setCanTake(false);
		inventory.push_back(item);
		std::cout << std::endl;
		std::cout << item.getName() << " added to inventory.\n";
		return true;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "You can't carry anything else. You have to "
		          << "drop something first.";
		std::cout << std::endl;
		return false;
	}
}

/*****************************************************************************
* Item Player::removeItem()
* This function lists the players inventory items and asks the user which one
* they would like to delete. It then makes a copy of that item to return, 
* deletes the item from inventory, and returns the copied item.
*****************************************************************************/

Item Player::removeItem()
{
	std::list<Item>::iterator iter = inventory.begin();
	Item item("", "", false, false);
	int count = 1;
	int choice = 0;

	if(!inventory.empty())
	{
		std::cout << std::endl;
		std::cout << "Please select an item to remove.";
		std::cout << std::endl;

		for(iter; iter != inventory.end(); iter++)
		{
			std::cout << count << ". " << iter->getName(); 
			std::cout << std::endl;
			count++;
		}
		
		std::cout << count << ". Back" << std::endl;
	
		choice = getInteger(1, count);

		if(choice != count)
		{
			iter = inventory.begin();
			std::advance(iter, choice - 1);
			item = *iter;
			inventory.erase(iter);
			std::cout << std::endl;
			std::cout << "Removed " << item.getName() << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		std::cout << "You're not holding anything";
		std::cout << std::endl;
	}
	
	return item;
}

/******************************************************************************
 * These functions return the player's member variables.
 *****************************************************************************/

bool Player::getAlive()
{
	return alive;
}

std::list<Item> Player::getInventory()
{
	return inventory;
}

/******************************************************************************
 * This function sets the alive member.
 *****************************************************************************/

void Player::setAlive(bool alive)
{
	this->alive = alive;
}
