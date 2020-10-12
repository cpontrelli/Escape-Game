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
#include "Player.hpp"
#include "readFile.hpp"
#include <list>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
	protected:
		std::string name;
		Space* forward;
		Space* aft;
		Space* starboard;
		Space* port;
		bool forwardOpen;
		bool aftOpen;
		bool starboardOpen;
		bool portOpen;
		std::string description;
		std::list<Item> items;

	public:
		virtual ~Space() = 0;
		void describe();
		virtual void useItem(Item item, Player &player);
		virtual Space* moveRooms();
		void addItem(Item item);
		void removeItem(Item item);
		std::list<Item> getItems();
		std::string getName();
		void setForward(Space* space);
		void setAft(Space* space);
		void setStarboard(Space* space);
		void setPort(Space* space);
		Space* getForward();
		Space* getAft();
		Space* getStarboard();
		Space* getPort();
};

#endif





