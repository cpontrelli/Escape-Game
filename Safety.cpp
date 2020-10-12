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

#include "Safety.hpp"

/*****************************************************************************
 * Safety::Safety()
 * This constructor initializes variables based on the specifications of this
 * space. It also initializes items and adds them to the space's item list.
 ****************************************************************************/

Safety::Safety()
{
	name = "Safety";
	forward = aft = starboard = port = NULL;
	forwardOpen = aftOpen = starboardOpen = portOpen = false;
	description = "safety.txt";
}


