/*****************************************************************************
 * Name: Charlie Pontrelli
 * Date: 12-8-2019
 * Description: This is the game class for an escape room type game. It has
 *              variables to store the player, the current room, the starting
 *              and ending rooms, the starting time and the max time. The
 *              constructor creates the rooms and links them together to form
 *              a map and the destructor deletes the map. It has a start loop
 *              which runs until the game ends or the player dies, an enter
 *              room function which handles the logic for interacting with the
 *              current room, a list items function to allow the player to
 *              interact with inventories, and a calculate time function to
 *              keep track of time.
 ****************************************************************************/
#include "Player.hpp"
#include "Item.hpp"
#include "Space.hpp"
#include "SupplyCloset.hpp"
#include "MessHall.hpp"
#include "EngineRoom.hpp"
#include "SickBay.hpp"
#include "Safety.hpp"
#include "getInteger.hpp"
#include "readFile.hpp"
#include "menu.hpp"
#include <iostream>
#include <ctime>
#include <list>
#include <algorithm>

#ifndef GAME_HPP
#define GAME_HPP

#include "TransporterRoom.hpp" //include after guards so it isn't nested

enum Inventory { PLAYER, ROOM };

class Game
{
	private:
		Player player;
		Space* head;
		Space* tail;
		static Space* currentRoom;
		std::time_t startTime;
		static int maxTime;

	public:
		Game();
		~Game();
		void start();
		Space* enterRoom();
		void listItems(Inventory inventory);
		int calcTimeLeft();
		void takeItem(Item item);
		void useItem(Item item);
		friend void TransporterRoom::useItem(Item item, 
				Player &player);
};

#endif
