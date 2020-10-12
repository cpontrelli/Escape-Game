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

#include "Game.hpp"

/*****************************************************************************
 * Initialize static members
 ****************************************************************************/

Space* Game::currentRoom = NULL;
int Game::maxTime = 0;

/*****************************************************************************
 * Game::Game()
 * Initializes member variables, the 6 spaces, and the player. It links the
 * spaces together into a map.
 ****************************************************************************/

Game::Game()
{
	Space* supplyCloset = new SupplyCloset;
	Space* messHall = new MessHall;
	Space* sickBay = new SickBay;
	Space* engineRoom = new EngineRoom;
	Space* transporterRoom = new TransporterRoom;
	Space* safety = new Safety;
	Player newPlayer(6);

	supplyCloset->setForward(messHall);
	messHall->setForward(sickBay);
	messHall->setPort(engineRoom);
	messHall->setAft(supplyCloset);
	engineRoom->setForward(transporterRoom);
	engineRoom->setStarboard(messHall);
	sickBay->setPort(transporterRoom);
	sickBay->setAft(messHall);
	transporterRoom->setForward(safety);
	transporterRoom->setAft(engineRoom);
	transporterRoom->setStarboard(sickBay);
	safety->setAft(transporterRoom);

	this->player = newPlayer;
	head = supplyCloset;
	currentRoom = supplyCloset;
	tail = safety;
}

/*****************************************************************************
 * Game::~Game()
 * The destructor deletes memory allocated to store the spaces.
 ****************************************************************************/

Game::~Game()
{
	delete tail->getAft()->getAft();
	delete tail->getAft();
	delete tail;
	delete head->getForward()->getForward();
	delete head->getForward();
	delete head;
}

/******************************************************************************
 * void Game::start()
 * This function controls the game loop. It sets up the game by asking the user
 * for a time limit. Then it displays te introduction and places you in the
 * supply closet. Any time you move rooms it calls enter room with the name
 * of the new room. The loop ends when time runs out, the player dies, or
 * the game is won.
 *****************************************************************************/

void Game::start()
{
	std::cout << std::endl;
	std::cout << "Please enter a time limit between 5 and 60 minutes";
	std::cout << std::endl;
	maxTime = getInteger(5,60) * 60;
	
	std::cout << std::endl;
	std::cout << "SELF DESTRUCT SEQUENCE INITIATED" << std::endl;
	std::cout << maxTime/60 << " MINUTES UNTIL DETONATION" << std::endl;
	readFile("./instructions/setup.txt");
	startTime = std::time(0);

	do
	{
		currentRoom = enterRoom();
	} while(currentRoom != NULL);

	
	if(!player.getAlive())
	{
		std::cout << std::endl << "GAME OVER" << std::endl;
	}
	else if(calcTimeLeft() <= 0)
	{
		std::cout << std::endl;
	        std::cout << "Your time is up. The ship has exploded.";
		std::cout << std::endl << "GAME OVER" << std::endl;
	}
	else
	{
		tail->describe();
		std::cout << std::endl << "CONGRATULATIONS!" << std::endl;
	}
}

/******************************************************************************
 * int Game::calcTimeLeft()
 * This function calculates the time that has elapsed since the beginning of
 * the game. It subtracts that number from the max time to get the time
 * remaining. It returns the remaining time in seconds.
 *****************************************************************************/

int Game::calcTimeLeft()
{
	int timeElapsed = (int)std::difftime(std::time(0), startTime);
	return maxTime - timeElapsed;
}

/******************************************************************************
 * void Game::listItems(Inventory inventory)
 * This function accepts a list of items and prints the contents to the screen.
 * It gets the user's choice of item. If the item can be taken it asks the user
 * if they would like to take it. If it can be used, but not taken it asks the
 * user if they would like to use it.
 *****************************************************************************/

void Game::listItems(Inventory inventory)
{
	int count = 1;
	int choice = 0;
	std::list<Item> items;
	std::list<Item>::iterator iter;

	do
	{
		count = 1;
		choice = 0;

		if(inventory == PLAYER)
		{
			items = player.getInventory();
		}
		else
		{
			items = currentRoom->getItems();
		}

		if(!items.empty())
		{
			std::cout << std::endl;
			std::cout << "Please select an item to inspect.";
			std::cout << std::endl;

			for(iter = items.begin(); iter != items.end(); iter++)
			{
				std::cout << count << ". " << iter->getName(); 
				std::cout << std::endl;
				count++;
			}
		
			std::cout << count << ". Back" << std::endl;
	
			choice = getInteger(1, count);

			if(choice != count)
			{
				iter = items.begin();
				std::advance(iter, choice - 1);
				iter->describe();
				if(iter->getCanTake())
				{
					takeItem(*iter);
				}
				else if(iter->getCanUse())
				{
					useItem(*iter);
				}
			}		
		}
		else
		{
			std::cout << std::endl;
			std::cout << "There are no items here.";
			std::cout << std::endl;
			choice++; //make choice = count
		}
	}
	while(choice != count && player.getAlive() && currentRoom != tail &&
			calcTimeLeft() > 0);
}

/*****************************************************************************
 * void Game::takeItem(Item item)
 * This function accepts an item and asks the user if they want to take it.
 * If they do, the item is removed from the room and added to player's inventory
 *****************************************************************************/

void Game::takeItem(Item item)
{
	int choice = 0;

	std::cout << std::endl;
	std::cout << "Enter 1 to take the item or 2 to leave it.";
	std::cout << std::endl;
	choice = getInteger(1,2);

	if(choice == 1)
	{
		if(player.addItem(item))
		{
			currentRoom->removeItem(item);
		}
	}
}

/******************************************************************************
 * void Game::useItem(Item item)
 * This function accepts an item and asks the user if they want to use it. If
 * They do, the current room's use item function is called.
 *****************************************************************************/

void Game::useItem(Item item)
{
	int choice = 0;

	std::cout << std::endl;
	std::cout << "Enter 1 to use the item or 2 to cancel.";
	std::cout << std::endl;
	choice = getInteger(1,2);

	if(choice == 1)
	{
		currentRoom->useItem(item, player);
	}
}

/******************************************************************************
 * Space* Game::enterRoom()
 * This function is called whenever a player enters a new room. First it
 * describes the room and then it initiates a loop that runs until the player
 * moves rooms, the player dies, or time runs out. Each iteration of the loop
 * lists options for the player to interact with the room or their inventory
 * items.
 *****************************************************************************/

Space* Game::enterRoom()
{
	Space* nextRoom = NULL;
	int choice = 0;
	Item item("","",false, false);
	int seconds = 0;

	currentRoom->describe();

	do
	{
	 choice = menu("roomOptions.txt");
	 
	 switch(choice)
	 {
	   case 1: currentRoom->describe();
		   break;
	   case 2: nextRoom = currentRoom->moveRooms();
		   break;
	   case 3: listItems(ROOM);
		   break;
	   case 4: listItems(PLAYER);
		   break;
	   case 5: item = player.removeItem();
		   if(item.getName() != "")
		   {
			   currentRoom->addItem(item);
		   }
		   break;
	   case 6: seconds = calcTimeLeft();
		   std::cout << std::endl;
		   std::cout << seconds / 60 << " minutes and "
			     << seconds % 60 << " seconds till detonation.";
		   std::cout << std::endl;
	 }

	} while(nextRoom == NULL && currentRoom != tail && player.getAlive()
			&& calcTimeLeft() > 0);

	return nextRoom;
}
