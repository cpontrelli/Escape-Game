/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-2-2019
 * Description: This is the main function for an escape room type game you
 *              find yourself in the supply closet of an abandoned ship and
 *              have to find your way off. Make use of any items that you
 *              find to unlock doors and teleport off the ship. Beware that
 *              using some items may kill you.
 ****************************************************************************/

#include "Item.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "SupplyCloset.hpp"
#include <list>
#include <iostream>
#include <algorithm>

int main()
{
	std::list<Item> items;
	Player player(6);
	SupplyCloset closet;
	std::list<Item>::iterator iter;

	Item beer("Beer", " ", true, true);
	Item beer2("Beer", " ", true, true);
	Item mop("Mop", " ", false, false);

	items.push_back(mop);
	items.push_back(beer);

	iter = find(items.begin(), items.end(), beer2);

	std::cout << std::endl;
	std::cout << iter->getName();
	std::cout << std::endl;
}

