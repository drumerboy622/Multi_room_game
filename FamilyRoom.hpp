/************************************************************************************************
Program Name: Find Keys Game
Program Developer: Matthew Solbrack
Date: 08/09/2019
Description: This header is for FamilyRoom.cpp. This holds the data members and member functions.
Visit FamilyRoom.cpp to find more information on the class.
*************************************************************************************************/
#ifndef FAMILYROOM_HPP
#define FAMILYROOM_HPP

#include "Space.hpp"

class FamilyRoom : public Space
{
private:
	int looks; // this variable has the power to tell the function if the keys have already been found
	void goofyKeyChain(); // Goofy Key Chain
public:
	int itemsToLookThrough();
	
};
#endif